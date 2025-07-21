
public class Perro {
	String raza;
	int edad;
	
	public Perro(String raza, int edad) {
		this.raza = raza;
		this.edad = edad;
	}
	
	public String hablar() {
		String frase = "Wooooff";
		System.out.println(frase);
		return frase;
	}
	
	public void hacer_cosas_de_perro() {
		System.out.println("*Va y hace cosas de perro*\n");
		return;
	}
}
