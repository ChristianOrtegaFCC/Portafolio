
public class Vaca extends Animal{
	public String sabor_de_leche_que_produce; // las vacas blancas dan leche normal, las cafés de chocolate, las amarillas de vainilla, las rosas de fresa y asi....
	
	public Vaca(int esperanza_de_vida, int peso, String sabor_de_leche_que_produce){
		super(esperanza_de_vida,peso);
		this.sabor_de_leche_que_produce = sabor_de_leche_que_produce;
	}
	
	@Override 
	public void comer() {
		System.out.println("Estoy comiendo pasto alv.");
	}
}
