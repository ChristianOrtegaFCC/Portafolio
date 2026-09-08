import { Component, inject } from '@angular/core';
import { RouterOutlet, RouterLink, RouterLinkActive } from '@angular/router';
import { CommonModule } from '@angular/common';

import { UiPreferences } from './services/ui-preferences';
import type { LanguageCode } from './services/ui-translations';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, RouterLink, RouterLinkActive, CommonModule],
  templateUrl: './app.html',
  styleUrl: './app.css'
})
export class App {
  protected title = 'Web_version';
  readonly ui = inject(UiPreferences);

  mostrarMenuSecundario = false;
  mostrarMenuIdiomas = false;
  mostrarMenuPerfil = false;

  toggleMenu(): void {
    this.mostrarMenuSecundario = !this.mostrarMenuSecundario;

    if (!this.mostrarMenuSecundario) {
      this.mostrarMenuIdiomas = false;
    }

    this.mostrarMenuPerfil = false;
  }

  ocultarMenu(): void {
    this.mostrarMenuSecundario = false;
    this.mostrarMenuIdiomas = false;
    this.mostrarMenuPerfil = false;
  }

  toggleTheme(): void {
    this.ui.toggleTheme();
  }

  toggleLanguageMenu(event?: Event): void {
    event?.stopPropagation();
    this.mostrarMenuIdiomas = !this.mostrarMenuIdiomas;
  }

  toggleProfileMenu(event?: Event): void {
    event?.stopPropagation();
    this.mostrarMenuPerfil = !this.mostrarMenuPerfil;

    if (!this.mostrarMenuPerfil) {
      this.mostrarMenuIdiomas = false;
    }
  }

  selectLanguage(language: LanguageCode, event?: Event): void {
    event?.stopPropagation();
    this.ui.setLanguage(language);
    this.mostrarMenuIdiomas = false;
  }

  closeLanguageMenu(event?: Event): void {
    event?.stopPropagation();
    this.mostrarMenuIdiomas = false;
  }
}
