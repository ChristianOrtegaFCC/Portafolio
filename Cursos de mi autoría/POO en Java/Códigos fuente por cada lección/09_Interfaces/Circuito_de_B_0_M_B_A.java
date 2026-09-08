// Las interfaces es un tema muy sencillo, así que compliquémos las cosas en esta
// lección para ver un poco cómo se puede jugar con los conceptos de POO, y como
// un pequeño examen teórico de todo lo que hemos visto :)

public class Circuito_de_B_0_M_B_A extends Circuito implements Arduino, MOTOR_DC{
	Granada G;
	int seconds;
	
	public Circuito_de_B_0_M_B_A(String modelo , double voltaje_total, double amperaje_total, boolean ON, Granada G, int seconds) {
		super(modelo, voltaje_total,amperaje_total,ON);
		this.G = G;
		this.seconds = seconds;
	}
	
	@Override // sobreescribo mi método Circuito.ON
	public boolean ON() {
		ON = true;
		System.out.println(modelo+" activad@...");
		ARD_ON();
		return true;
	}
	
	// > > >  DESARROLLO UNA COMPLEJA DETONACIÓN MEDIANTE TODAS LAS INTERFACES QUE SE ME PIDIÓ  < < <
	
	// [!] Implemento los métodos de la interface Arduino
	public boolean ARD_ON(){
		System.out.println("Arduino encendido -> Arduino se ejecuta...");
		ARD_RUN();
		return true;
	}
	
	public boolean ARD_OFF(){
		// Dada la naturaleza de este objeto (Circuito_de_B_0_M_B_A),
		// no se supone que podamos alcanzar este fragmento de código,
		// pero la interface lo pide, y hay que 'implementarlo' :)
		return true;
	}
	
	public boolean ARD_RUN(){
		amperaje_total = amperaje_total + Arduino.amperaje; 
		voltaje_total = voltaje_total  + Arduino.voltaje;
		System.out.println("-> Arduino enciende motor...");
		MOTOR_ON( (amperaje_total*voltaje_total) , Arduino.pin2);
		return true;
	}
	
	// [!] Implemento los métodos de la interface MOTOR_DC
	public boolean MOTOR_ON(double power, short pin){ // !!!!
		// supongamos que en alguna parte de esta implementación,
		// usamos los valores que acabamos de recibir hahahahaha.
		
		System.out.println("MOTOR: TRRRRRRRA, TATATATA...");
		while(true) {
			System.out.println("["+seconds+"]");
			seconds --;
			if (seconds == 0) {
				INTERFACE_ARD_WITH_MOTOR_DC();
				break;
			}
		}
		return true;
	}
	
	public boolean MOTOR_OFF(){
		// Dada la naturaleza de este objeto (Circuito_de_B_0_M_B_A),
		// no se supone que podamos alcanzar este fragmento de código,
		// pero la interface lo pide, y hay que 'implementarlo' :)
		return true;
	}
	
	// [!][!] Implemento una sola vez, un método que aparece en las interfaces de Arduino y de
	//        MOTOR_DC al mismo tiempo, y con esa sola vez basta
	public boolean INTERFACE_ARD_WITH_MOTOR_DC(){
		G.ON = true;
		G.detonar();
		return true;
	}
	
	
	
}
