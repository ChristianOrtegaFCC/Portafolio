
public class Usuario {
	String nombre;
	int IDE;
	int edad;
	
	public Usuario(String nombre, int IDE, int edad) {
		this.nombre = nombre;
		this.IDE = IDE;
		this.edad = edad;
		
	}
	
	public void existir() {
		System.out.println("xd, me llamo "+nombre+"("+IDE+")"+" y tengo "+edad+"anios");
	}
	
	private void metodo_privado() {
		System.out.println("Realizando algo privado...");
	}
}
