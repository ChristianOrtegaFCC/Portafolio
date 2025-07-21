
public class Enano_Luchador extends Enano{
	boolean luchador;
	
	public Enano_Luchador(String nombre, int edad, double peso ,String direccion, boolean True,boolean Truex2) {
		super(nombre,edad,peso,direccion,True); // parámetros de enano
		this.luchador = Truex2; // valor agregado de enano luchador
	}
	
	@Override
	public void caminar() {
		System.out.println(nombre+" camina, con su trajecito de luchador");
	}
	
	public void Luchar() {
		System.out.println(nombre+" lucha.");
	}
	
}
