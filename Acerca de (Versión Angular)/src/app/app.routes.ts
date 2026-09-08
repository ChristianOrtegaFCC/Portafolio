import { Routes } from '@angular/router';
import { H } from './h/h';
import { Proyectos } from './proyectos/proyectos';
import { Experiencia } from './experiencia/experiencia';
import { Formacion } from './formacion/formacion';
import { Perfil } from './perfil/perfil';
import { Contacto } from './contacto/contacto';

export const routes: Routes = [
  {
    path: 'h',
    pathMatch: 'full',
    redirectTo: ''
  },
  {
    path: 'h/:section',
    redirectTo: ':section'
  },
  {
    path: '',
    component: H,
    children: [
      { path: 'proyectos', component: Proyectos },
      { path: 'experiencia', component: Experiencia },
      { path: 'formacion', component: Formacion },
      { path: 'perfil', component: Perfil },
      { path: 'contacto', component: Contacto }
    ]
  },
  {
    path: '**',
    redirectTo: 'proyectos'
  }
];
