
/*
 * El polimorfismo es la habilidad de un objeto de realizar una acción
 * de diferentes maneras, Usando métodos iguales que se implementen de
 * forma diferente en varias clases
 * 
 * Hay 2 tipos de polimorfismo:
 *  > estático -> @Overload -> Sobrecarga de métodos
 *  > dinámico -> @Override
 *  
 *  (Esta info la encontré así pero algo no me cuadra...) (@Override y @Overload deberían ir al revés)
 * */


public class Main {
	public static void main(String[] args) {
		
		
		// Polimorfismo estático:
		// de la misma clase persona, creamos un new aleman
		// un new francés, y así. Y asi se queda hasta el final
		// de la ejecución... (Sobrecarga de métodos)
		
		Perro Dog = new Perro("Sharpei",5);
		Persona P1 = new Aleman("Jurgen",28);
		Persona P2 = new Frances("Adele",20);
		Persona P3 = new Italiano("Cipriani",30);
		Persona P4 = new Ruso("Broflovsky",10);
		Persona P5 = new Mexicano("Juan",23);
		Persona P6 = new Persona_multinacionalidad("Luisito_comunica",25); // !!!!!!!
		
		P1.hablar(); // si los métodos "hablar();" de cada uno de estos objetos no hubiesen sido reescritos, se hubiera invocado al método del padre (Persona) 
		P2.hablar();
		P3.hablar();
		P4.hablar();
		P5.hablar();
		P6.hablar(); // !!!!!!!!!
		
		
		
		
		/*
		// Polimorfismo dinámico:
		// El mismo objeto Persona P6, puede pasar a ser new alemán, new francés
		// y así el hijo de su puta madre... todo esto ocurre en tiempo de ecución:
		
		Perro Dog = new Perro("Sharpei",5);
		//Persona P6 = new Persona_multinacionalidad("Luisito_comunica",25); // Check
		//Persona P6 = new Persona("Luisito_comunica",25); // Check
		//Persona P6 = new Frances("Adele",20);
		
		
		System.out.println("\nAqui se empieza a poner raro...\n");
		
		P6 = new Aleman("Hail_Luisito_comunica",25);
		P6.hablar();
		((Aleman) P6).comer_salchicas_y_beber_cerveza();
		//((Aleman) Dog).comer_salchicas_y_beber_cerveza();
		// aunque intentamos hacer que el perro hable mediante el cast, esto
		// no va a pasar, porque la clase perro no es hija de clase persona
		// por eso es importante la herencia en el polimorfismo.
		
		// un año despues xdxd
		P6 = new Frances("Le_Luisito_comunica",26);
		P6.hablar();
		((Frances) P6).comer_baguettes();
		//((Aleman) Dog).comer_baguettes();
		
		// un año despues xdxd
		P6 = new Ruso("Luisito_comunicavsky",27);
		P6.hablar();
		((Ruso)P6).Domar_osos();
		//((Aleman) Dog).Comer_taco();
		
		P6 = new Persona_multinacionalidad("Luisito_comunica",25);
		P6.hablar();
		
		
		System.out.println("\n\n !!! Es el mismo hijo de su puta madre, pero con muchas formas diferentes");
		*/
	}
}
