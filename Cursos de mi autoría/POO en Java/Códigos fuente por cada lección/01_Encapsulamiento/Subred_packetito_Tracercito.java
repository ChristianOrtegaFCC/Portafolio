package packet_tracer;

// Esta clase podrá acceder a los métodos protected de la clase
// "Red_packet_Tracer" deriva de ella.
public class Subred_packetito_Tracercito extends Red_packet_Tracer{
	int sector;
	
	// MÉTODO CONSTRUCTOR
	public Subred_packetito_Tracercito(String nombre_de_la_red, int password, int numero_de_hosts ,double ingresos,int sector){
		super(nombre_de_la_red, password,numero_de_hosts, ingresos);
		this.sector = sector;
	}
	
}
