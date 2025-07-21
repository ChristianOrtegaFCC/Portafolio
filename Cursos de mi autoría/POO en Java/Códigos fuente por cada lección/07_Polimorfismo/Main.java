/*

 	El polimorfismo es la habilidad de un objeto de realizar una acción
 	de diferentes maneras, Usando métodos iguales que se implementen de
 	forma diferente en varias clases. El polimorfismo permite que objetos
 	de diferentes clases sean tratados como
 	objetos de una clase base común.
 
 	Hay 2 tipos de polimorfismo:
  		> Estático -> Sobrecarga de métodos
  		> Dinámico -> Sobreescritura de métodos -> @Override
  	
		POLIMORFISMO DE TIEMPO DE COMPILACIÓN (o estático): donde varias funciones
		tienen el mismo nombre pero diferentes parámetros. (sobrecarga)
		
		POLIMORFISMO DE TIEMPO DE EJECUCIÓN (o dinámico): Se logra a través de la
		herencia y la sobrescritura (override). Esto se usa comúnmente clases abstractas
		e interfaces (veremos interfaces después).

*/


public class Main {
	public static void main(String[] args) {
		
		
		// Polimorfismo estático:
		// de la misma clase persona, todas las clases derivadas van
		// a hablar de forma diferente (Sobrecarga de métodos)
		
		Perro Dog = new Perro("Sharpei",5);
		Persona P1 = new Aleman("Jurgen",28);
		Persona P2 = new Frances("Adele",20);
		Persona P3 = new Italiano("Cipriani",30);
		Persona P4 = new Ruso("Broflovsky",10);
		Persona P5 = new Mexicano("Juan",23);
		Persona P6 = new Persona_multinacionalidad("Luisito_comunica",25);
		
		P1.hablar(); // si los métodos "hablar();" de cada uno de estos objetos no hubiesen sido reescritos, se hubiera invocado al método del padre (Persona) 
		P2.hablar();
		P3.hablar();
		P4.hablar();
		P5.hablar();
		P6.hablar();
		
		
		
		
		// Incluso el mismo objeto Persona P6, puede pasar a ser new alemán, new francés....
		P6 = new Persona_multinacionalidad("Luisito_comunica",25);
		P6 = new Persona("Luisito_comunica",25);
		P6 = new Frances("Adele",20);
		P6 = new Aleman("Jurgen",25);
		P6.hablar();
		((Aleman) P6).comer_salchicas_y_beber_cerveza();
		
		//((Aleman) Dog).comer_salchicas_y_beber_cerveza();
		// aunque intentamos hacer que el perro hable mediante el cast, esto
		// no va a pasar, porque la clase perro no es hija de clase persona
		// por eso es importante la herencia en el polimorfismo.
		
		
		P6 = new Frances("Le_Luisito_comunica",26);
		P6.hablar();
		((Frances) P6).comer_baguettes();
				
		P6 = new Ruso("Luisito_comunicavsky",27);
		P6.hablar();
		((Ruso)P6).Domar_osos();
				
		P6 = new Persona_multinacionalidad("Luisito_comunica",25);
		P6.hablar();
		
		System.out.println("\n\n !!! Cada persona habla, pero de muchas formas diferentes");
		
	}
}
