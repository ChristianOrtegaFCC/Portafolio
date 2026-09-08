import { CommonModule } from '@angular/common';
import { Component, effect, inject } from '@angular/core';

import { Data } from '../services/data';
import { createHoverAudio } from '../services/hover-audio';
import { UiPreferences } from '../services/ui-preferences';

@Component({
  selector: 'app-formacion',
  standalone: true,
  imports: [CommonModule],
  templateUrl: './formacion.html',
  styleUrl: './formacion.css'
})
export class Formacion {
  readonly ui = inject(UiPreferences);
  formaciones: any[] = [];
  isLoading = true;

  private formacionesBase: any[] = [];
  private readonly audio = createHoverAudio('swipe.mp3');

  constructor(private dataService: Data) {
    effect(() => {
      this.ui.language();
      this.formaciones = this.ui.translateContent(this.formacionesBase);
    });
  }

  ngOnInit(): void {
    this.cargarProyectos();
  }

  async cargarProyectos() {
    try {
      this.formacionesBase = await this.dataService.getDataFromTable('f');
      this.formaciones = this.ui.translateContent(this.formacionesBase);
    } catch (error) {
      console.error('Error al cargar formacion:', error);
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
