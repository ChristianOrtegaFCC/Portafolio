import { Injectable } from '@angular/core';
import type { SupabaseClient } from '@supabase/supabase-js';
import { supabase } from '../supabase-client';

const PROJECTS_SELECT = `
  nombre,
  descripcion,
  img,
  url_gh,
  fecha,
  monetizado,
  favorito,
  individual,
  "en-equipo",
  "en-desarrollo",
  personal,
  experimental,
  academico,
  industrial,
  "empresarial-corporativo",
  administrativo,
  independiente,
  produccion,
  activo,
  "stand-by-pausado",
  "cliente-encargo",
  "publicado-distribuido",
  "open-source",
  "closed-source",
  "confidencial-informacion-reservada",
  "incluyo-o-implico-capacitacion-de-usuarios",
  educativo,
  legado,
  "aplicaciones-de-escritorio",
  "aplicaciones-moviles",
  "desarrollo-web",
  "bases-de-datos",
  "datos-analisis-de-datos-ciencia-de-datos",
  ia,
  ml,
  llm,
  ciberseguridad,
  videojuegos,
  multimedia,
  "contenido-tecnico-documentacion",
  "nube-computacion-en-la-nube",
  hardware,
  ofimatica,
  "sistemas-embebidos",
  redes,
  backend,
  frontend,
  automatizacion,
  servidores,
  android,
  windows,
  linux,
  "dist-github",
  "dist-googleplay",
  "dist-microsoftstore",
  "dist-revista",
  "dist-web",
  "dist-nube"
`;

@Injectable({
  providedIn: 'root'
})
export class Data {
  private readonly supabase: SupabaseClient = supabase;
  private cache = new Map<string, any>();

  async getDataFromTable(tableName: string): Promise<any> {
    if (this.cache.has(tableName)) {
      return this.cache.get(tableName);
    }

    let data: any;
    let error: any;

    if (tableName === 'e') {
      const result = await this.supabase
        .from(tableName)
        .select(`
          *,
          e_resp ( id, descripcion ),
          e_logs ( id, descripcion )
        `)
        .order('relevancia', { ascending: false });

      data = result.data;
      error = result.error;
    } else if (tableName === 'p') {
      const result = await this.supabase
        .from(tableName)
        .select(PROJECTS_SELECT)
        .order('relevancia', { ascending: false });

      data = result.data;
      error = result.error;
    } else {
      const result = await this.supabase
        .from(tableName)
        .select('*')
        .order('relevancia', { ascending: false });

      data = result.data;
      error = result.error;
    }

    if (error) throw error;

    this.cache.set(tableName, data);
    return data;
  }

  clearCache(tableName?: string) {
    if (tableName) this.cache.delete(tableName);
    else this.cache.clear();
  }
}
