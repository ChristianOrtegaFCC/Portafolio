
public class Aleman extends Persona{
	
	public Aleman(String nombre, int edad) {
		super(nombre,edad);
	}
	
	public String saludar() {
		String frase = "Hallo";
		System.out.println(frase);
		return frase;
	}
	
	public void comer_salchicas_y_beber_cerveza() {
		System.out.println("*Come salchicas y bebe cerveza*\n");
		return;
	}
}