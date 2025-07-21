
public class Pistola extends Arma{
	
	public Pistola(String modelo) {
		super(modelo);
	}
	
	@Override
	public boolean detonar(){
		System.out.println("\" piu piu piu \"");// detona con balas
		return true;
	}
}
