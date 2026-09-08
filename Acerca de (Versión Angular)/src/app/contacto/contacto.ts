import { CommonModule } from '@angular/common';
import { Component, inject } from '@angular/core';

import { createHoverAudio } from '../services/hover-audio';
import { UiPreferences } from '../services/ui-preferences';

@Component({
  selector: 'app-contacto',
  imports: [CommonModule],
  templateUrl: './contacto.html',
  styleUrl: './contacto.css'
})
export class Contacto {
  readonly ui = inject(UiPreferences);
  dadoActual = '';
  toastMessage = '';
  toastVisible = false;
  value = '';
  dados: string[] = [];

  copied = false;
  copied2 = false;
  copied3 = false;
  copied4 = false;
  copied5 = false;

  private readonly audio = createHoverAudio('swipe.mp3');

  get businessMailHref(): string {
    return this.createMailtoHref('dicelabs@outlook.com');
  }

  get professionalMailHref(): string {
    return this.createMailtoHref('christianortegafcc@gmail.com');
  }

  get whatsappHref(): string {
    const body = encodeURIComponent(this.ui.t('contact.whatsappMessage'));
    return `https://wa.me/522224961605?text=${body}`;
  }

  ngOnInit() {
    const simbolos = ['⚀', '⚁', '⚂', '⚃', '⚄', '⚅'];
    this.dados = Array.from({ length: 14 }, () => simbolos[Math.floor(Math.random() * simbolos.length)]);
  }

  mostrarToast(mensaje: string): void {
    this.toastMessage = mensaje;
    this.toastVisible = true;

    setTimeout(() => {
      this.toastVisible = false;
    }, 2000);
  }

  copiarAlPortapapeles(texto: string, value: string): void {
    navigator.clipboard.writeText(texto).then(() => {
      switch (value) {
        case '1':
          this.copied = true;
          break;
        case '2':
          this.copied2 = true;
          break;
        case '3':
          this.copied3 = true;
          break;
        case '4':
          this.copied4 = true;
          break;
        case '5':
          this.copied5 = true;
          break;
        default:
          console.error('Valor desconocido');
      }

      setTimeout(() => {
        this.copied = false;
        this.copied2 = false;
        this.copied3 = false;
        this.copied4 = false;
        this.copied5 = false;
      }, 2000);
    }).catch((err) => {
      console.error('No se pudo copiar', err);
    });
  }

  playSound() {
    this.audio.play();
  }

  pauseSound() {
    this.audio.stop();
  }

  private createMailtoHref(email: string): string {
    const subject = encodeURIComponent(this.ui.t('contact.mailSubject'));
    const body = encodeURIComponent(this.ui.t('contact.mailBody'));
    return `mailto:${email}?subject=${subject}&body=${body}`;
  }
}
