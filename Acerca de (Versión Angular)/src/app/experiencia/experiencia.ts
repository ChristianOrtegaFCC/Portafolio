import { CommonModule } from '@angular/common';
import { Component, effect, inject } from '@angular/core';

import { Data } from '../services/data';
import { createHoverAudio } from '../services/hover-audio';
import { UiPreferences } from '../services/ui-preferences';

@Component({
  selector: 'app-experiencia',
  standalone: true,
  imports: [CommonModule],
  templateUrl: './experiencia.html',
  styleUrl: './experiencia.css'
})
export class Experiencia {
  readonly ui = inject(UiPreferences);
  experiencias: any[] = [];
  isLoading = true;

  private experienciasBase: any[] = [];
  private readonly audio = createHoverAudio('swipe.mp3');

  constructor(private dataService: Data) {
    effect(() => {
      this.ui.language();
      this.experiencias = this.ui.translateContent(this.experienciasBase);
    });
  }

  ngOnInit(): void {
    this.cargarExperiencias();
  }

  async cargarExperiencias() {
    try {
      this.experienciasBase = await this.dataService.getDataFromTable('e');
      this.experiencias = this.ui.translateContent(this.experienciasBase);
    } catch (error) {
      console.error('Error al cargar experiencia(s):', error);
    } finally {
      this.isLoading = false;
    }
  }

  playSound() {
    this.audio.play();
  }

  pauseSound() {
    this.audio.stop();
  }
}
