
public class Persona_con_formacion implements Habitos{
	String nombre;
	int edad;
	double peso;
	Coche transporte;
	
	
	public Persona_con_formacion(String nombre, int edad, double peso,Coche transporte){
		this.nombre = nombre;
		this.edad = edad;
		this.peso = peso;
		this.transporte = transporte;
	}
	
	// métodos normalillos...
	public void mostrar_su_coche() {
		System.out.println(nombre+" Dice: \"Mi coche es un "+transporte.modelo+" "+transporte.color+" del anio "+transporte.anio+"\"\n");
	}
	
	public void Presumir_sus_habitos() {
		// si quisieramos podríamos definir el numero de horas mandado cada tarea como un atributo variable o contsante en la clase
		// pero para nuestros fines didácticos, que pinche hueva.
		
		Hacer_ejercicio(1);
		Estudiar(4);
		Trabajar(6);
		Hacer_la_cama();
		Asearse();
	}
	
	//Implementaciones  !!!! si falta una, se tomará como un error
	public void Hacer_ejercicio(int horas) {
		System.out.println(nombre+" hace ejercicio "+horas+" horas al dia");
		return;
	}
	
	public void Estudiar(int horas) {
		System.out.println(nombre+" estudia "+horas+" horas al dia");
		return;
	}
	
	public void Trabajar(int horas) {
		System.out.println(nombre+" trabaja "+horas+" horas al dia");
		return;
	}
	
	public void Hacer_la_cama() {
		System.out.println(nombre+" hace la pvta cama cuando se levanta");
		return;
	}
	
	public void Asearse() {
		System.out.println(nombre+" se lava los dientes, se bania, se peina...");
		return;
	}
	
}
