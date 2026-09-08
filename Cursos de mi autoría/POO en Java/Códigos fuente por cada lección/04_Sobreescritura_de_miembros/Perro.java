
public class Perro extends Animal{
	public String raza_perruna;// [!] Atributo único en su clase
	
	public Perro(int esperanza_de_vida, int peso, String raza_perruna){
		super(esperanza_de_vida,peso);
		this.raza_perruna = raza_perruna;
	}
	
	// Método comer SOBREESCRITO
	@Override 
	public void comer() {
		System.out.println("Estoy comiendo con mi plato en el suelo...");
	}
}
