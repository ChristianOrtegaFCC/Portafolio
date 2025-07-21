
public class Persona_multinacionalidad extends Persona{

	public Persona_multinacionalidad(String nombre, int edad) {
		super(nombre,edad);
	}
	
	@Override
	public String hablar() {
		String frase = "Mi nombre es: "+nombre+". Aroun the  world Aroun the worl, Aroun the  world Aroun the worl, Aroun the  world Aroun the worl ";
		System.out.println(frase);
		return frase;
	}
}
