
public class Clase_Generica <T>{ // Operador diamante, T no es palabra reservada, puedes cambiarla
	public T dato;
	
	public Clase_Generica(T dato) {
		this.dato = dato;
	}
	
	public String oye_wey_tu_que_madres_usas() {
		String mensaje = ("Yo uso datos de tipo: "+dato.getClass().getName())+"\n\n";
		System.out.println(mensaje);
		return mensaje;
	}
}
