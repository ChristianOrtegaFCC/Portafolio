
public class Clase_Normal { // supongamos una clase para un Taser
	public String modelo;
	public double voltaje;
	public double amperaje;
	public double poder;
	public static boolean legal;
	
	public Clase_Normal(String modelo,double voltaje,double amperaje,boolean legal) {
		this.modelo = modelo;
		this.voltaje = voltaje;
		this.amperaje = amperaje;
		     poder = voltaje*amperaje;
		this.legal = legal;
	}
	
	public void toque() {
		System.out.println("Tsssst xdxd");
	}
}
