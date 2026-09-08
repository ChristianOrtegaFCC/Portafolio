
public class Coche implements Rueda{
	String modelo;
	String color;
	int anio;
	
	public Coche(String modelo, String color, int anio){
		this.modelo =  modelo;
		this.color =  color;
		this.anio =  anio;
	}
	
	public void avanzar() {
		System.out.println("Avanza con 4 ruedas");
	}
	
	public void detenerse() {
		System.out.println("se frenan 2 ruedas, por lo tanto, se frenan las 4");
	}
	
}
