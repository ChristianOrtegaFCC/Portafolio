
public class Persona extends Animal{
	public String apellido;
	
	public Persona(int esperanza_de_vida, int peso, String apellido){
		super(esperanza_de_vida,peso);
		this.apellido = apellido;
	}
	
	@Override 
	public void comer() {
		System.out.println("Estoy comiendo con cubiertos...");
	}
}
