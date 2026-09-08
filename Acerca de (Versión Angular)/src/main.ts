import { registerLocaleData } from '@angular/common';
import { bootstrapApplication } from '@angular/platform-browser';

import localeDe from '@angular/common/locales/de';
import localeEn from '@angular/common/locales/en';
import localeEs from '@angular/common/locales/es';
import localeFr from '@angular/common/locales/fr';
import localeRu from '@angular/common/locales/ru';

import { appConfig } from './app/app.config';
import { App } from './app/app';

registerLocaleData(localeEs);
registerLocaleData(localeEn);
registerLocaleData(localeDe);
registerLocaleData(localeFr);
registerLocaleData(localeRu);

bootstrapApplication(App, appConfig)
  .catch((err) => console.error(err));
