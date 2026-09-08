package packet_tracer;

public class Subred_packetito_Tracercito extends Red_packet_Tracer{
	int sector;
	
	// MÉTODO CONSTRUCTOR
	public Subred_packetito_Tracercito(String nombre_de_la_red, int password, int numero_de_hosts ,double ingresos,int sector){
		super(nombre_de_la_red, password,numero_de_hosts, ingresos);
		this.sector = sector;
	}
	
}
