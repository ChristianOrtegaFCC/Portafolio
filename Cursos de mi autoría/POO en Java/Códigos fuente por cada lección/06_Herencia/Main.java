// La herencia consiste en la capacidad de una clase de poder reusar los atributos
// y las instancias ya previamente escritas de una clase. Como padres e hijos.

// Primero definimos una clase base (también conocida como clase madre, clase
// padre, o como quieras, siempre y cuando entiendas la idea)


public class Main {
	public static void main(String[] args) {
		Persona P1 = new Persona("Marek",25,76.1,"CD.Paraiso calle Resurreccion #12-04 cp:72320");
		Payaso E1 = new Payaso("Francisco",21,45.2,"Clavijero");
		Payaso_Luchador E2 = new Payaso_Luchador("Eduardo",21,50.3,"Santa fe, puebla pue", true);
		
		P1.caminar();
		E1.caminar();
		E2.caminar();
	}
}
