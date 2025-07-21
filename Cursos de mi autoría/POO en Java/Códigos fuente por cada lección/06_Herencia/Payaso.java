// Los payasos son personas, y como personas, tienen las mismas funciones y
// atributos heredados de una persona... (notemos la sintáxis que define la
// existencia de herencia en esta clase)

public class Payaso extends Persona{
	boolean EsPayaso;
	
	public Payaso(String nombre, int edad, double peso ,String direccion) {
		super(nombre,edad,peso,direccion);// parámetros de persona
		this.EsPayaso = true;// valor agregado del Payaso
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
