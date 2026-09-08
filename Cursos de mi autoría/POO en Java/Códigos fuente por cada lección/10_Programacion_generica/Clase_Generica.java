
public class Clase_Generica <T>{ // '<>': Operador diamante, ('T' no es palabra reservada, puedes cambiarla)
	public T dato;
	
	public Clase_Generica(T dato) {
		this.dato = dato;
	}
	
	// De entrada, no sabemos lo que esta clase usa en su atributo 'T'
	public String oye_dime_que_usas() {
		String mensaje = ("Yo uso datos de tipo: "+dato.getClass().getName())+"\n\n";
		System.out.println(mensaje);
		return mensaje;
	}
}
