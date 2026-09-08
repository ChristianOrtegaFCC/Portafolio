package Excepciones;

public class Impostor extends Exception{
	String Mensaje;
	int num_balazos;
	
	public Impostor(String Mensaje,int num_balazos) {
		this.Mensaje = Mensaje;
		this.num_balazos = num_balazos;
	}
	
	@Override
	public String getMessage() {
		return Mensaje+" Rapido, denle "+num_balazos+" balazos";
	}

}
