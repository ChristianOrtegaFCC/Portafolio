
public class Arma implements Detonacion{
	String modelo;
	
	public Arma(String modelo){
		this.modelo = modelo;
	}
	
	public boolean detonar(){
		System.out.println("\" Arma detonada \"");
		return true;
	}

}
