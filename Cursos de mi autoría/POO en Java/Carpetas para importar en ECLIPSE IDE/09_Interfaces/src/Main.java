
/*
	Una interface es una madre que define los métodos que la clase que la implemente debe
	desarrollar (la interface obliga a la clase que la usa, a usar sus métodos). En java
	Se usan principalmente para emular la herencia multiple.
	
	Las interfaces pueden tener atributos, pero estos se trabajarán como constantes aunque no quieras
	
	
	otra definición que se les da a las interfaces es: "una madre que hace que dos objetos de distintas
	clases se comuniquen adecuadamente entre sí"
*/

public class Main {
	public static void main(String[] args) {
		
		// Primero lo primero:
		// [Persona] [Coche] [Habitos] [Rueda] 
		Coche EDH_824 = new Coche("Mazda","Rojo",2020);
		Persona_con_formacion Japones = new Persona_con_formacion("Tadashi",20,70.7,EDH_824);
		
		Japones.mostrar_su_coche();
		Japones.Presumir_sus_habitos();
		//Japones.avanzar(); // Persona_con_formacion implements Rueda(){
		
		/*
		// Ahora algo perrón:
		// [Arma] [Detonacion] [Pistola] [Granada] [Circuito] [Arduino] [Motor_DC] [CircuitoDeBomba]
		System.out.println("\n\n\nAhora algo perron. . .\n");
		Granada Granada1 = new Granada("Quacker",false);
		Circuito_de_B_0_M_B_A Circuito1 = new Circuito_de_B_0_M_B_A("El_temible_Komodo_3000",7.5,5.2,false,Granada1,35);
		
		Circuito1.ON();
		*/
	}
}
