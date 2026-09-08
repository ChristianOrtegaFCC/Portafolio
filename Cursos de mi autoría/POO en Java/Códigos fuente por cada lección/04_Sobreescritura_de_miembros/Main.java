// La sobreescritura de miembros es la capacidad de una clase derivada ("Hija")
// para proporcionar una implementación específica de un método que ya ha sido
// definido en su clase base, para poder comportarse de manera diferente.

// Básicamente reescribes el método heredado de una clase parde, en la clase hijo.
// recuerda que para hacer esto debes escribir @Override antes del método a sobreescribir

public class Main {
	public static void main(String[] args) {
		Persona amauri = new Persona(70,70,"Ortega");
		Perro chispa = new Perro(20,12,"Schnawzer");
		Vaca la_de_nutrileche = new Vaca(60,500,"Chocolate");
		
		// Justo aquí, todos estos ANIMALES comen,
		// pero todos lo hacen de manera diferente.
		// (SOBREESCRIBIMOS su comportamiento).
		amauri.comer();
		chispa.comer();
		la_de_nutrileche.comer();
		
		
	}
}
