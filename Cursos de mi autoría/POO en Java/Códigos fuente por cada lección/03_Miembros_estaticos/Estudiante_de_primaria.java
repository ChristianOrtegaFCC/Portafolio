
public class Estudiante_de_primaria {
	public int grado = 0;
	public String nombre = "-";
	public static String uniforme = "-"; // !!!!
	
	public Estudiante_de_primaria(int grado, String nombre, String uniforme) {
		this.grado = grado;
		this.nombre = nombre;
		this.uniforme = uniforme;//...... ATENCIÓN, En esta clase, el uniforme
		//............................... será un atributo estático.
	}
	
	public void pasar_lista() {
		System.out.println("Presente");
		return;
	}

	public void modelar_uniforme() {
		System.out.println("Me llamo "+nombre+", "+grado+"to grado, mira mi "+uniforme+". pa");
		return;
	}
	
	public static void leer() {//................ ATENCIÓN, Aquí tenemos un método estático, el
		System.out.println("Un alumno lee");//... chiste de estos es que pueden ser utilizados 
	}//.......................................... incluso sin instancias creadas.
}
