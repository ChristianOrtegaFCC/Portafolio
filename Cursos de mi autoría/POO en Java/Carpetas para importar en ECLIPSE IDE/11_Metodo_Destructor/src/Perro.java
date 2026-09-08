
public class Perro {
	String nombre;
	String raza;
	int edad;
	
	public Perro(String nombre,String raza,int edad) {
		this.nombre = nombre;
		this.raza = raza;
		this.edad = edad;
	}
	
	public void jugar() {
		System.out.println("Bark Bark");
	}
	
	public void finalize() throws Throwable{
		System.out.println("El perrito C murio xd");
		super.finalize();
	}
	
}
