import { CommonModule } from '@angular/common';
import { Component, OnDestroy, OnInit, effect, inject } from '@angular/core';

import { Data } from '../services/data';
import { createHoverAudio } from '../services/hover-audio';
import { UiPreferences } from '../services/ui-preferences';

interface Insignia {
  nombre: string;
  icono: string;
  valor: boolean;
}

interface Proyecto {
  nombre: string;
  descripcion: string;
  img: string;
  url_gh: string;
  fecha: string;
  monetizado: boolean;
  favorito: boolean;
  individual: boolean;
  'en-equipo': boolean;
  'en-desarrollo': boolean;
  personal: boolean;
  experimental: boolean;
  academico: boolean;
  industrial: boolean;
  'empresarial-corporativo': boolean;
  administrativo: boolean;
  independiente: boolean;
  produccion: boolean;
  activo: boolean;
  'stand-by-pausado': boolean;
  'cliente-encargo': boolean;
  'publicado-distribuido': boolean;
  'open-source': boolean;
  'closed-source': boolean;
  'confidencial-informacion-reservada': boolean;
  'incluyo-o-implico-capacitacion-de-usuarios': boolean;
  educativo: boolean;
  legado: boolean;
  'aplicaciones-de-escritorio': boolean;
  'aplicaciones-moviles': boolean;
  'desarrollo-web': boolean;
  'bases-de-datos': boolean;
  'datos-analisis-de-datos-ciencia-de-datos': boolean;
  ia: boolean;
  ml: boolean;
  llm: boolean;
  ciberseguridad: boolean;
  videojuegos: boolean;
  multimedia: boolean;
  'contenido-tecnico-documentacion': boolean;
  'nube-computacion-en-la-nube': boolean;
  hardware: boolean;
  ofimatica: boolean;
  'sistemas-embebidos': boolean;
  redes: boolean;
  backend: boolean;
  frontend: boolean;
  automatizacion: boolean;
  servidores: boolean;
  android: boolean;
  windows: boolean;
  linux: boolean;
  'dist-github': boolean;
  'dist-googleplay': boolean;
  'dist-microsoftstore': boolean;
  'dist-revista': boolean;
  'dist-web': boolean;
  'dist-nube': boolean;
  insignias?: Insignia[];
  insigniasTecnologias?: Insignia[];
  insigniasDistribucion?: Insignia[];
}

@Component({
  selector: 'app-proyectos',
  standalone: true,
  imports: [CommonModule],
  templateUrl: './proyectos.html',
  styleUrl: './proyectos.css'
})
export class Proyectos implements OnInit, OnDestroy {
  readonly ui = inject(UiPreferences);
  proyectos: Proyecto[] = [];
  isLoading = true;
  badgeSnackbarMessage: string | null = null;

  private proyectosBase: any[] = [];
  private readonly audio = createHoverAudio('swipe.mp3');
  private badgeSnackbarTimer?: number;

  constructor(private dataService: Data) {
    effect(() => {
      this.ui.language();
      this.rebuildProjects();
    });
  }

  ngOnInit(): void {
    this.cargarProyectos();
  }

  ngOnDestroy(): void {
    this.clearBadgeSnackbarTimer();
  }

  async cargarProyectos() {
    try {
      this.proyectosBase = await this.dataService.getDataFromTable('p');
      this.rebuildProjects();
    } catch (error) {
      console.error('Error al cargar proyectos:', error);
    } finally {
      this.isLoading = false;
    }
  }

  private rebuildProjects() {
    this.proyectos = this.ui.translateContent(this.proyectosBase).map((proyecto: any) => ({
      ...proyecto,
      insignias: this.obtenerInsignias(proyecto),
      insigniasTecnologias: this.obtenerInsigniasTecnologias(proyecto),
      insigniasDistribucion: this.obtenerInsigniasDistribucion(proyecto)
    }));
  }

  private obtenerInsignias(proyecto: any) {
    const insignias: Insignia[] = [
      { nombre: this.ui.t('projects.badge.monetized'), icono: 'monetizado.png', valor: proyecto.monetizado },
      { nombre: this.ui.t('projects.badge.favorite'), icono: 'favorito.png', valor: proyecto.favorito },
      { nombre: this.ui.t('projects.badge.individual'), icono: 'individual.png', valor: proyecto.individual },
      { nombre: this.ui.t('projects.badge.team'), icono: 'en-equipo.png', valor: proyecto['en-equipo'] },
      { nombre: this.ui.t('projects.badge.inProgress'), icono: 'en-desarrollo.png', valor: proyecto['en-desarrollo'] },
      { nombre: this.ui.t('projects.badge.personal'), icono: 'personal.png', valor: proyecto.personal },
      { nombre: this.ui.t('projects.badge.experimental'), icono: 'experimental.png', valor: proyecto.experimental },
      { nombre: this.ui.t('projects.badge.academic'), icono: 'academico.png', valor: proyecto.academico },
      { nombre: this.ui.t('projects.badge.industrial'), icono: 'industrial.png', valor: proyecto.industrial },
      { nombre: this.ui.t('projects.badge.businessCorporate'), icono: 'empresarial-corporativo.png', valor: proyecto['empresarial-corporativo'] },
      { nombre: this.ui.t('projects.badge.administrative'), icono: 'administrativo.png', valor: proyecto.administrativo },
      { nombre: this.ui.t('projects.badge.independent'), icono: 'independiente.png', valor: proyecto.independiente },
      { nombre: this.ui.t('projects.badge.production'), icono: 'produccion.png', valor: proyecto.produccion },
      { nombre: this.ui.t('projects.badge.active'), icono: 'activo.png', valor: proyecto.activo },
      { nombre: this.ui.t('projects.badge.standByPaused'), icono: 'stand-by-pausado.png', valor: proyecto['stand-by-pausado'] },
      { nombre: this.ui.t('projects.badge.clientCommission'), icono: 'cliente-encargo.png', valor: proyecto['cliente-encargo'] },
      { nombre: this.ui.t('projects.badge.publishedDistributed'), icono: 'publicado-distribuido.png', valor: proyecto['publicado-distribuido'] },
      { nombre: this.ui.t('projects.badge.openSource'), icono: 'open-source.png', valor: proyecto['open-source'] },
      { nombre: this.ui.t('projects.badge.closedSource'), icono: 'closed-source.png', valor: proyecto['closed-source'] },
      { nombre: this.ui.t('projects.badge.confidentialReserved'), icono: 'confidencial-informacion-reservada.png', valor: proyecto['confidencial-informacion-reservada'] },
      { nombre: this.ui.t('projects.badge.userTraining'), icono: 'incluyo-o-implico-capacitacion-de-usuarios.png', valor: proyecto['incluyo-o-implico-capacitacion-de-usuarios'] },
      { nombre: this.ui.t('projects.badge.educational'), icono: 'educativo.png', valor: proyecto.educativo },
      { nombre: this.ui.t('projects.badge.legacy'), icono: 'legado.png', valor: proyecto.legado }
    ];

    return insignias.filter((insignia) => insignia.valor);
  }

  private obtenerInsigniasTecnologias(proyecto: any) {
    const insignias: Insignia[] = [
      { nombre: this.ui.t('projects.tech.desktopApps'), icono: 'aplicaciones-de-escritorio.png', valor: proyecto['aplicaciones-de-escritorio'] },
      { nombre: this.ui.t('projects.tech.mobileApps'), icono: 'aplicaciones-moviles.png', valor: proyecto['aplicaciones-moviles'] },
      { nombre: this.ui.t('projects.tech.webDevelopment'), icono: 'desarrollo-web.png', valor: proyecto['desarrollo-web'] },
      { nombre: this.ui.t('projects.tech.databases'), icono: 'bases-de-datos.png', valor: proyecto['bases-de-datos'] },
      { nombre: this.ui.t('projects.tech.dataScience'), icono: 'datos-analisis-de-datos-ciencia-de-datos.png', valor: proyecto['datos-analisis-de-datos-ciencia-de-datos'] },
      { nombre: this.ui.t('projects.tech.ai'), icono: 'ia-inteligencia-artificial.png', valor: proyecto.ia },
      { nombre: this.ui.t('projects.tech.ml'), icono: 'ml-machine-learning.png', valor: proyecto.ml },
      { nombre: this.ui.t('projects.tech.llm'), icono: 'llm-modelos-de-lenguaje.png', valor: proyecto.llm },
      { nombre: this.ui.t('projects.tech.cybersecurity'), icono: 'ciberseguridad.png', valor: proyecto.ciberseguridad },
      { nombre: this.ui.t('projects.tech.games'), icono: 'videojuegos.png', valor: proyecto.videojuegos },
      { nombre: this.ui.t('projects.tech.multimedia'), icono: 'multimedia.png', valor: proyecto.multimedia },
      { nombre: this.ui.t('projects.tech.documentation'), icono: 'contenido-tecnico-documentacion.png', valor: proyecto['contenido-tecnico-documentacion'] },
      { nombre: this.ui.t('projects.tech.cloud'), icono: 'nube-computacion-en-la-nube.png', valor: proyecto['nube-computacion-en-la-nube'] },
      { nombre: this.ui.t('projects.tech.hardware'), icono: 'hardware.png', valor: proyecto.hardware },
      { nombre: this.ui.t('projects.tech.office'), icono: 'ofimatica.png', valor: proyecto.ofimatica },
      { nombre: this.ui.t('projects.tech.embeddedSystems'), icono: 'sistemas-embebidos.png', valor: proyecto['sistemas-embebidos'] },
      { nombre: this.ui.t('projects.tech.networks'), icono: 'redes.png', valor: proyecto.redes },
      { nombre: this.ui.t('projects.tech.backend'), icono: 'backend.png', valor: proyecto.backend },
      { nombre: this.ui.t('projects.tech.frontend'), icono: 'frontend.png', valor: proyecto.frontend },
      { nombre: this.ui.t('projects.tech.automation'), icono: 'automatizacion.png', valor: proyecto.automatizacion },
      { nombre: this.ui.t('projects.tech.servers'), icono: 'servidor.png', valor: proyecto.servidores },
      { nombre: this.ui.t('projects.tech.android'), icono: 'android.png', valor: proyecto.android },
      { nombre: this.ui.t('projects.tech.windows'), icono: 'windows.png', valor: proyecto.windows },
      { nombre: this.ui.t('projects.tech.linux'), icono: 'linux.png', valor: proyecto.linux }
    ];

    return insignias.filter((insignia) => insignia.valor);
  }

  private obtenerInsigniasDistribucion(proyecto: any) {
    const insignias: Insignia[] = [
      { nombre: this.ui.t('projects.distribution.github'), icono: 'github.png', valor: proyecto['dist-github'] },
      { nombre: this.ui.t('projects.distribution.googlePlay'), icono: 'googleplay.png', valor: proyecto['dist-googleplay'] },
      { nombre: this.ui.t('projects.distribution.microsoftStore'), icono: 'microsoftstore.png', valor: proyecto['dist-microsoftstore'] },
      { nombre: this.ui.t('projects.distribution.magazine'), icono: 'revista.png', valor: proyecto['dist-revista'] },
      { nombre: this.ui.t('projects.distribution.web'), icono: 'web.png', valor: proyecto['dist-web'] },
      { nombre: this.ui.t('projects.distribution.cloud'), icono: 'nube.png', valor: proyecto['dist-nube'] }
    ];

    return insignias.filter((insignia) => insignia.valor);
  }

  playSound() {
    this.audio.play();
  }

  pauseSound() {
    this.audio.stop();
  }

  showBadgeSnackbar(message: string, event: Event) {
    event.stopPropagation();
    this.badgeSnackbarMessage = message;
    this.clearBadgeSnackbarTimer();

    this.badgeSnackbarTimer = window.setTimeout(() => {
      this.badgeSnackbarMessage = null;
      this.badgeSnackbarTimer = undefined;
    }, 2800);
  }

  private clearBadgeSnackbarTimer() {
    if (this.badgeSnackbarTimer === undefined) return;

    window.clearTimeout(this.badgeSnackbarTimer);
    this.badgeSnackbarTimer = undefined;
  }
}
