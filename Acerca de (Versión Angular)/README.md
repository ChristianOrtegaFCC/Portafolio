# Acerca de - Version Angular

Implementacion Angular del portafolio profesional de Christian Ortega.

## Proposito

Esta aplicacion presenta experiencia, habilidades, formacion, proyectos y medios de contacto mediante una interfaz de una sola pagina. Su contenido se consume de forma publica desde Supabase y se renderiza en el navegador.

## Arquitectura

- Angular con TypeScript y estilos SCSS.
- Componentes separados por seccion del portafolio.
- Servicio de datos centralizado para lecturas remotas y cache en memoria.
- Cliente Supabase con clave publica `anon`; no incluye credenciales administrativas ni llaves de servicio.
- Interfaz responsive, con paneles, insignias de proyecto y soporte de idiomas.

## Datos y seguridad

El cliente solo solicita informacion mediante consultas de lectura. La configuracion segura esperada en Supabase es Row Level Security (RLS) habilitado en las tablas publicadas, con politicas de `SELECT` para visitantes y sin politicas de `INSERT`, `UPDATE` o `DELETE` para roles web.

Una clave `anon` puede estar presente en un frontend publico por diseno. La proteccion de escritura depende de las politicas RLS y nunca de ocultar esa clave en el navegador.

## Desarrollo local

```bash
npm install
npm start
```

La aplicacion se sirve normalmente en `http://localhost:4200`.

## Compilacion

```bash
npm run build
```

El resultado se genera en `dist/` y puede publicarse como sitio estatico.

## Estructura relevante

```text
src/app/             Componentes y servicios de la aplicacion
src/app/services/    Carga, cache y traducciones de contenido
src/app/supabase-client.ts
public/              Recursos estaticos
```

## Notas de repositorio

No se versionan `node_modules`, resultados de compilacion, caches ni configuracion local del editor. Se regeneran con las instrucciones anteriores.
