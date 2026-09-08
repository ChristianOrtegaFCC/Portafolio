import { CommonModule } from '@angular/common';
import { Component, ElementRef, OnInit, ViewChild, effect, inject } from '@angular/core';

import { Data } from '../services/data';
import { createHoverAudio } from '../services/hover-audio';
import { UiPreferences } from '../services/ui-preferences';

@Component({
  selector: 'app-perfil',
  standalone: true,
  imports: [CommonModule],
  templateUrl: './perfil.html',
  styleUrl: './perfil.css'
})
export class Perfil implements OnInit {
  @ViewChild('scrollContainer', { static: false }) scrollContainer!: ElementRef;

  readonly ui = inject(UiPreferences);
  hb: any[] = [];
  lenguajes: any[] = [];
  desarrollo: any[] = [];
  bddyn: any[] = [];
  teoria: any[] = [];
  tecnologia: any[] = [];

  isLoading = true;
  isLoading2 = true;
  isLoading3 = true;
  isLoading4 = true;
  isLoading5 = true;
  isLoading6 = true;

  private hbBase: any[] = [];
  private lenguajesBase: any[] = [];
  private desarrolloBase: any[] = [];
  private bddynBase: any[] = [];
  private teoriaBase: any[] = [];
  private tecnologiaBase: any[] = [];
  private readonly audio = createHoverAudio('swipe.mp3');

  constructor(private dataService: Data) {
    effect(() => {
      this.ui.language();
      this.hb = this.ui.translateContent(this.hbBase);
      this.lenguajes = this.ui.translateContent(this.lenguajesBase);
      this.desarrollo = this.ui.translateContent(this.desarrolloBase);
      this.bddyn = this.ui.translateContent(this.bddynBase);
      this.teoria = this.ui.translateContent(this.teoriaBase);
      this.tecnologia = this.ui.translateContent(this.tecnologiaBase);
    });
  }

  scrollRight() {
    const container = this.scrollContainer.nativeElement;
    const scrollAmount = container.offsetWidth * 0.5;
    container.scrollBy({ left: scrollAmount, behavior: 'smooth' });
  }

  scrollLeft() {
    const container = this.scrollContainer.nativeElement;
    const scrollAmount = container.offsetWidth * 0.5;
    container.scrollBy({ left: -scrollAmount, behavior: 'smooth' });
  }

  ngOnInit(): void {
    this.cargarhabilidadesblandas();
    this.cargarlenguajesdeprogramacion();
    this.cargartecnologiasdedesarrollo();
    this.cargarbasesdedatosynube();
    this.cargarteoriayfundamentos();
    this.cargartecnicoycomplementario();
  }

  async cargarhabilidadesblandas() {
    try {
      this.hbBase = await this.dataService.getDataFromTable('comps');
      this.hb = this.ui.translateContent(this.hbBase);
    } catch (error) {
      console.error('Error al cargar habilidades blandas:', error);
    } finally {
      this.isLoading = false;
    }
  }

  async cargarlenguajesdeprogramacion() {
    try {
      this.lenguajesBase = await this.dataService.getDataFromTable('lenguajesdeprogramacion');
      this.lenguajes = this.ui.translateContent(this.lenguajesBase);
    } catch (error) {
      console.error('Error al cargar lenguajes de programacion:', error);
    } finally {
      this.isLoading2 = false;
    }
  }

  async cargartecnologiasdedesarrollo() {
    try {
      this.desarrolloBase = await this.dataService.getDataFromTable('tecnologiasdedesarrollo');
      this.desarrollo = this.ui.translateContent(this.desarrolloBase);
    } catch (error) {
      console.error('Error al cargar tecnologias de desarrollo:', error);
    } finally {
      this.isLoading3 = false;
    }
  }

  async cargarbasesdedatosynube() {
    try {
      this.bddynBase = await this.dataService.getDataFromTable('basesdedatosynube');
      this.bddyn = this.ui.translateContent(this.bddynBase);
    } catch (error) {
      console.error('Error al cargar "bases de datos y nube":', error);
    } finally {
      this.isLoading4 = false;
    }
  }

  async cargarteoriayfundamentos() {
    try {
      this.teoriaBase = await this.dataService.getDataFromTable('teoriayfundamentos');
      this.teoria = this.ui.translateContent(this.teoriaBase);
    } catch (error) {
      console.error('Error al cargar "teoria y fundamentos":', error);
    } finally {
      this.isLoading5 = false;
    }
  }

  async cargartecnicoycomplementario() {
    try {
      this.tecnologiaBase = await this.dataService.getDataFromTable('tecnicoycomplementario');
      this.tecnologia = this.ui.translateContent(this.tecnologiaBase);
    } catch (error) {
      console.error('Error al cargar skills tecnicas y complementarias:', error);
    } finally {
      this.isLoading6 = false;
    }
  }

  playSound() {
    this.audio.play();
  }

  pauseSound() {
    this.audio.stop();
  }
}
