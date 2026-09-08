
public class Main {
	public static void main(String[] args) {
		Persona P1 = new Persona("Marek",25,76.1,"CD.Paraiso calle Resurreccion #12-04 cp:72320");
		Enano E1 = new Enano("Francisco",21,45.2,"Clavijero",true);
		Enano_Luchador E2 = new Enano_Luchador("Eduardo",21,50.3,"Santa fe, puebla pue",true,true);
		
		P1.caminar();
		E1.caminar();
		E2.caminar();
	}
}
