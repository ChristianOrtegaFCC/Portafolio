
package packet_tracer;
import java.util.Scanner;

public class Red_packet_Tracer {
	// [!] ATENCIÓN a los encapsuladores:
	public String nombre_de_la_red;
	private int password;
	private int numero_de_hosts;
	protected double ingresos;
	
	
	// MÉTODO CONSTRUCTOR
	public Red_packet_Tracer(String nombre_de_la_red, int password, int numero_de_hosts ,double ingresos){
		this.nombre_de_la_red = nombre_de_la_red;
		this.password = password;
		this.numero_de_hosts = numero_de_hosts;
		this.ingresos = ingresos;
	}
	
	// MÉTODOS NORMALES
	public void mostrar_red() {
		System.out.println("!!! Red disponible: "+nombre_de_la_red);
	}
	
	private void usar_red() {
		System.out.println("Entrale pues");
	}
	
	public void Muestra_toda_la_info() {
		System.out.println("  Nombre: "+nombre_de_la_red);
		System.out.println("    Pass: "+password);
		System.out.println("   Num-H: "+numero_de_hosts);
		System.out.println("ingresos: "+ingresos);
		System.out.println("");
		return;
	}
	
	// GETTERS Y SETTERS !!!!!!!!!!!!!!!!
	
	// GETTERS - El punto de un getter es retornar el valor pedido
	public String Getnombre() { // forma general
		return nombre_de_la_red; 
	}
	
	public int Getpassword() {
		return password; 
	}
	
	public int Getnumero_de_hosts() {
		return numero_de_hosts; 
	}
	
	public double Getingresos() {
		return ingresos; 
	}
	
	

	public void  Setnombre(String nombre_de_la_red) {
		this.nombre_de_la_red = nombre_de_la_red;
		return; 
	}
	
	public void Setpassword(int password) {
		this.password = password;
		return; 
	}

	// NOTA ESTO:
	// En realidad, nada nos impide que un SETTER tenga su propio funcionamiento
	// interno. En realidad nada te impide que aquí te armes todo un sistema si
	// eso es lo que quieres, pero el punto de un SETTER es "SETTEAR" un valor.
	// Un método setter no es diferente de otro método común y corriente, sin
	// embargo la convención es: recibir un valor, y asignarlo. No más (y lo)
	// mismo aplica para los GETTERS; puedes poner dentro de un GETTER lo que
	// quieras, pero el punto debe ser devolver el valor específico. Aunque
	// la convención es simplemente devolvero sin más.
	public void Setnumero_de_hosts() {
		int Valor;
		Scanner scanf = new Scanner(System.in);
		System.out.print("Dame el numero de hosts: ");
		Valor = scanf.nextInt();
		this.numero_de_hosts = Valor;
		return; 
	}
	
	public void Setingresos(double ingresos) {
		this.ingresos = ingresos;
		return; 
	}
	
}
