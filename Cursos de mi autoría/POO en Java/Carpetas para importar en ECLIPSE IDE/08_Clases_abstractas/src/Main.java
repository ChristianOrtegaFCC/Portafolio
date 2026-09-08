/*
 	Las clases abstractas:
 	  > son iguales a las otras clases (pueden tener atributos, constructor y métodos). lo que hace a una clase abstracta, es tener al menos un método abstracto.
	  > Se usan solo como clases padre (o super clases)
	  > No puedes crear objetos de ellas (o instancias)
	  > Sirven como bosquejo de lo que serán sus clases hijas !!!!
*/
public class Main {
	public static void main(String[] args) {
		//Persona P0 = new Persona("Christian",20); // ya ves?!, esto no se puede xd
		Persona P1 = new Aleman("Amauri",21);
		Frances P2 = new Frances("Amador",22);
		Persona P3 = new Mexicano("Ortega",23);
		
		P1.saludar();
		P2.saludar();
		P3.saludar();
		
	}
}
