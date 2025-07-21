
public class Granada extends Arma{
	public boolean ON;
	
	public Granada(String modelo,boolean ON) {
		super(modelo);
		this.ON = ON;
	}
	
	@Override
	public boolean detonar(){
		ON = true;
		System.out.println("\" Kaboom \""); // detona alv
		return true;
	}
}
