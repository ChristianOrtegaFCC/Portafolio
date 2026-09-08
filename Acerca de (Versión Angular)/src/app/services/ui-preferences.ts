import { DOCUMENT } from '@angular/common';
import { Injectable, computed, effect, inject, signal } from '@angular/core';

import {
  CONTENT_TRANSLATIONS,
  LANGUAGE_OPTIONS,
  type LanguageCode,
  normalizeText,
  type ThemeMode,
  UI_TEXTS,
  type UiTextKey
} from './ui-translations';

const LANGUAGE_STORAGE_KEY = 'dice-labs-career-language';
const THEME_STORAGE_KEY = 'dice-labs-career-theme';

@Injectable({
  providedIn: 'root'
})
export class UiPreferences {
  private readonly document = inject(DOCUMENT);

  readonly languages = LANGUAGE_OPTIONS;
  readonly language = signal<LanguageCode>(this.readStoredLanguage());
  readonly theme = signal<ThemeMode>(this.readStoredTheme());
  readonly currentLanguage = computed(
    () => this.languages.find((language) => language.code === this.language()) ?? this.languages[0]
  );
  readonly currentLocale = computed(() => this.currentLanguage().locale);
  readonly isLightTheme = computed(() => this.theme() === 'light');
  readonly themeSymbol = computed(() => (this.isLightTheme() ? '☀' : '☾'));

  constructor() {
    effect(() => {
      const theme = this.theme();
      const root = this.document?.documentElement;

      if (root) {
        root.dataset['theme'] = theme;
      }

      this.safeStore(THEME_STORAGE_KEY, theme);
    });

    effect(() => {
      const language = this.currentLanguage();
      const root = this.document?.documentElement;

      if (root) {
        root.lang = language.locale;
      }

      this.safeStore(LANGUAGE_STORAGE_KEY, language.code);
    });
  }

  toggleTheme(): void {
    this.theme.update((value) => (value === 'dark' ? 'light' : 'dark'));
  }

  setLanguage(language: LanguageCode): void {
    this.language.set(language);
  }

  t(key: UiTextKey): string {
    const translations = UI_TEXTS[key];

    if (!translations) {
      return key;
    }

    return translations[this.language()] ?? translations.es;
  }

  translateText(value: string): string {
    const currentLanguage = this.language();

    if (currentLanguage === 'es') {
      return value;
    }

    const translation = CONTENT_TRANSLATIONS[normalizeText(value)]?.[currentLanguage];
    return translation ?? value;
  }

  translateContent<T>(value: T): T {
    return this.translateValue(value) as T;
  }

  private translateValue(value: unknown): unknown {
    if (typeof value === 'string') {
      return this.translateText(value);
    }

    if (Array.isArray(value)) {
      return value.map((entry) => this.translateValue(entry));
    }

    if (value && typeof value === 'object') {
      const translated: Record<string, unknown> = {};

      for (const [key, entry] of Object.entries(value)) {
        translated[key] = this.translateValue(entry);
      }

      return translated;
    }

    return value;
  }

  private readStoredLanguage(): LanguageCode {
    const storedLanguage = this.safeRead(LANGUAGE_STORAGE_KEY);

    if (storedLanguage && this.languages.some((language) => language.code === storedLanguage)) {
      return storedLanguage as LanguageCode;
    }

    return 'es';
  }

  private readStoredTheme(): ThemeMode {
    return 'dark';
  }

  private safeRead(key: string): string | null {
    try {
      return globalThis.localStorage?.getItem(key) ?? null;
    } catch {
      return null;
    }
  }

  private safeStore(key: string, value: string): void {
    try {
      globalThis.localStorage?.setItem(key, value);
    } catch {
      // localStorage may be unavailable in privacy-restricted environments.
    }
  }
}
