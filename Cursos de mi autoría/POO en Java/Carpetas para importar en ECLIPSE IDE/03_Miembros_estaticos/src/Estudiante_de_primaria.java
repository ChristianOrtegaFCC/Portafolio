
public class Estudiante_de_primaria {
	public int grado = 0;
	public String nombre = "-";
	public static String uniforme = "-"; // !!!!
	
	public Estudiante_de_primaria(int grado, String nombre, String uniforme) {
		this.grado = grado;
		this.nombre = nombre;
		this.uniforme = uniforme;
	}
	
	public void pasar_lista() {
		System.out.println("Presente xd");
		return;
	}

	public void modelar_uniforme() {
		System.out.println("Me llamo "+nombre+", "+grado+"to grado, chequeate mi "+uniforme+". pa xd");
		return;
	}
	
	public static void leer() {
		System.out.println("Estoy haciendo la leyedera, la leyesion");
	}
}
