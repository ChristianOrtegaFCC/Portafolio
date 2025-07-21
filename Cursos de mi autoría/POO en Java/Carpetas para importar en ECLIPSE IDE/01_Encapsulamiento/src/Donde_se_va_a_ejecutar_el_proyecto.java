
import packet_tracer.Red_packet_Tracer;            // !!!!!! sneaky
import packet_tracer.Subred_packetito_Tracercito;  // !!!!!!


public class Donde_se_va_a_ejecutar_el_proyecto {
	public static void main(String[] args) {
		int contrasenia;
		
		// creamos un objeto (instancia) de la clase Red_packet_Tracer, y uno de la clase Usuario
		Usuario U1 = new Usuario("Mapache",201927821,20);
		Red_packet_Tracer Red1 = new Red_packet_Tracer("Red_de_mentiras", 2524678, 400, 19.95);
		
		// Veamos que podemos hacer, dados los modificadores de acceso:
		
		//podemos hacer esto, porque nombre_de_la_red es public
		Red1.nombre_de_la_red = "Red_de_corrupcion";
		U1.existir();
		
		// esto está mal, no se puede, porque todo esto es private
		//Red1.password = 1995;
		//System.out.println("El password de "+Red1.nombre_de_la_red+" es: "+Red1.password);
		//Red1.usar_red();
		//U1.masturbarse();
		
		// esto está bien (para eso existen los getters y setters, es como para pedir permiso a la clase)
		Red1.Setnumero_de_hosts();
		Red1.Setpassword(1234567);
		contrasenia = Red1.Getpassword();
		
		System.out.println("La contrasenia de \""+Red1.nombre_de_la_red+"\" es: "+contrasenia+"\n");
		
		
		// finalmente, con el hijo...
		Subred_packetito_Tracercito Red2 = new Subred_packetito_Tracercito("Red_chingona",666, 35, 3.1416,7);
		Red2.Muestra_toda_la_info();
	}
}
