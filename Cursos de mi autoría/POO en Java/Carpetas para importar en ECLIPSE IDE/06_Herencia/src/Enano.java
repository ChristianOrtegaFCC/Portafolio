
public class Enano extends Persona{
	boolean enanito;
	
	public Enano(String nombre, int edad, double peso ,String direccion, boolean True) {
		super(nombre,edad,peso,direccion);// parámetros de persona
		this.enanito = True;// valor agregado del enano
	}
	
	@Override
	public void caminar() {
		System.out.println(nombre+" camina... pero chistoso");
	}
	
	@Override
	public void saltar() {
		System.out.println(nombre+" salta... pero chistoso");
	}
}
