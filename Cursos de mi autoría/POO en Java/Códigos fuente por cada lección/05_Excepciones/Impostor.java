// [!] Recuerda importar esto en donde lo vayas a usar :)
package Excepciones;

// [!] Nota que heredamos de la clase Exception
// [!] (Nota que Excaption es una clase)
public class Impostor extends Exception{
	String Mensaje;
	int num_balazos;
	
	// Aquí recibimos los parámetros
	public Impostor(String Mensaje,int num_balazos) {
		this.Mensaje = Mensaje;
		this.num_balazos = num_balazos;
	}
	
	@Override
	public String getMessage() {
		return Mensaje+" Rapido, denle "+num_balazos+" balazos";
	}

}
