
public class Frances extends Persona{
	
	public Frances(String nombre, int edad) {
		super(nombre,edad);
	}
	
	public String saludar() {
		String frase = "Salut";
		System.out.println(frase);
		return frase;
	}
	
	public void comer_baguettes() {
		System.out.println("*Se atiborra de baguettes*\n");
		return;
	}
}