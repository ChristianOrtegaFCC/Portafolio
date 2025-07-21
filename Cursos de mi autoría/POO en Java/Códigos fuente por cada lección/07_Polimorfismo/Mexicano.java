
public class Mexicano extends Persona{
	
	public Mexicano(String nombre, int edad) {
		super(nombre,edad);
	}
	
	// [!] Uso de @Override para modificar el comportamiento del método
	@Override
	public String hablar() {
		String frase = "Mi nombre es: "+nombre+". Ayayayay canta y no llores";
		System.out.println(frase);
		return frase;
	}
	
	public void Comer_taco() {
		System.out.println("*Se come un taco*\n");
		return;
	}
}
