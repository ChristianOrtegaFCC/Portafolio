
public class Perro extends Animal{
	public String raza_perruna;
	
	public Perro(int esperanza_de_vida, int peso, String raza_perruna){
		super(esperanza_de_vida,peso);
		this.raza_perruna = raza_perruna;
	}
	
	@Override 
	public void comer() {
		System.out.println("Estoy comiendo con mi plato en el suelo...");
	}
}
