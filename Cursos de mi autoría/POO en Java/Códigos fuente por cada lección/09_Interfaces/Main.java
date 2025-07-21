/*	
 	Definición 1:
	En términos simples, una interfaz funge como una lista de métodos que una clase
 	debe implementar. Es como una lista de requisitos, si una clase implementa una
 	interfaz, pero no tiene definidos todos los métodos que pide, hay error.

 	La interfaz no te pide que implementes los métodos de un modo específico, sólo
 	te lo pide.


	Definición 2:
	Una interface es una cosa que define los métodos que la clase que la implemente debe
	desarrollar (la interface obliga a la clase que la usa, a usar sus métodos). En java
	Se usan principalmente para emular la herencia multiple.
	
	Las interfaces pueden tener atributos, pero estos se trabajarán como constantes aunque no quieras
	

*/

public class Main {
	public static void main(String[] args) {
		
		// Primero lo básico:
		// [Persona] [Coche] [Habitos] [Rueda] 
		Coche EDH_824 = new Coche("Mazda","Rojo",2020);
		Persona_con_formacion Ing = new Persona_con_formacion("Tadashi",20,70.7,EDH_824);
		
		Ing.mostrar_su_coche();
		Ing.Presumir_sus_habitos();
		
		
		// Ahora algo extremo:
		// [Arma] [Detonacion] [Pistola] [Granada] [Circuito] [Arduino] [Motor_DC] [CircuitoDeBomba]
		Granada Granada1 = new Granada("Quacker",false);
		Circuito_de_B_0_M_B_A Circuito1 = new Circuito_de_B_0_M_B_A("El_temible_Komodo_3000",7.5,5.2,false,Granada1,35);
		
		Circuito1.ON();
		
	}
}
