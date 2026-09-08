
public class Persona_multinacionalidad extends Persona{

	public Persona_multinacionalidad(String nombre, int edad) {
		super(nombre,edad);
	}
	
	// [!] Uso de @Override para modificar el comportamiento del método
	@Override
	public String hablar() {
		String frase = "Mi nombre es: "+nombre+". Around the entire world :) ";
		System.out.println(frase);
		return frase;
	}
}
