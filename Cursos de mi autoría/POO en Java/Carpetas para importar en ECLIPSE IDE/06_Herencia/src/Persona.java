
public class Persona {
	public String nombre;
	public int edad;
	public double peso;
	public String direccion;
	
	public Persona(String nombre, int edad, double peso ,String direccion) {
		this.nombre = nombre;
		this.edad = edad;
		this.peso = peso;
		this.direccion = direccion;
	}
	
	public void caminar() {
		System.out.println(nombre+" camina...");
	}
	
	public void saltar() {
		System.out.println(nombre+" salta...");
	}
	
	
	
}
