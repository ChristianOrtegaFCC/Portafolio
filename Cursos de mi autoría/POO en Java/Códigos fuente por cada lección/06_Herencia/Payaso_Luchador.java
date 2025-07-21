// Misma lógica con una clase derivada de payaso:

public class Payaso_Luchador extends Payaso{
	boolean luchador;
	
	public Payaso_Luchador(String nombre, int edad, double peso ,String direccion,boolean Truex2) {
		super(nombre,edad,peso,direccion);//........ Parámetros de payaso
		this.luchador = Truex2;//................... Valor agregado de payaso luchador
	}
	
	@Override
	public void caminar() {
		System.out.println(nombre+" camina, con su trajecito de luchador");
	}
	
	public void Luchar() {//........................ Método agregado de luchador
		System.out.println(nombre+" lucha.");
	}
	
}
