
public class Vaca extends Animal{
	// En este universo hipotético, las vacas blancas dan leche normal, las
	// vacas café dan de chocolate, las vacas amarillas dan de vainilla, las
	// rosas de fresa y asi....
	public String sabor_de_leche_que_produce;
	
	public Vaca(int esperanza_de_vida, int peso, String sabor_de_leche_que_produce){
		super(esperanza_de_vida,peso);
		this.sabor_de_leche_que_produce = sabor_de_leche_que_produce;
	}
	
	// Sólo las vacas pueden mujir (sin que se vea raro)....
	@Override 
	public void comer() {
		System.out.println("Estoy comiendo pasto, muuuuu.");
	}
}
