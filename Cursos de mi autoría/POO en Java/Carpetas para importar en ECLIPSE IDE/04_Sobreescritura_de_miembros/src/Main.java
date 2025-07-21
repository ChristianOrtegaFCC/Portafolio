
public class Main {
	public static void main(String[] args) {
		Persona amauri = new Persona(70,70,"Ortega");
		Perro chispa = new Perro(20,12,"Schnawzer");
		Vaca la_de_nutrileche = new Vaca(60,500,"Chocolate");
		
		amauri.comer();
		chispa.comer();
		la_de_nutrileche.comer();
		
		// Básicamente reescribes el método heredado de una clase parde, en la clase hijo.
		// recuerda que para hacer esto debes escribir @Override antes del método a sobreescribir
	}
}
