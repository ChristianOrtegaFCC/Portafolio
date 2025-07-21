
public class Persona {
	String nombre;
	int edad;
	
	public Persona(String nombre, int edad) {
		this.nombre = nombre;
		this.edad = edad;
	}
	
	// [!] Este es el método que sobreescribiremos en las clases derivadas (Hijas)
	public String hablar() {
		String frase = "BlaBlaBlaBlaBlaBlaBla";
		System.out.println(frase);
		return frase;
	}
}
