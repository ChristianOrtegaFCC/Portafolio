
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
	
	public void oler_colas() {
		System.out.println("*Va y huele una cola*\n");
		return;
	}
}
