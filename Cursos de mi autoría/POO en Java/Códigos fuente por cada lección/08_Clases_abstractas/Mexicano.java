
public class Mexicano extends Persona{
	
	public Mexicano(String nombre, int edad) {
		super(nombre,edad);
	}
	
	public String saludar() {
		String frase = "Hola";
		System.out.println(frase);
		return frase;
	}
	
	public void Comer_taco() {
		System.out.println("*Se come un taco*\n");
		return;
	}
}
