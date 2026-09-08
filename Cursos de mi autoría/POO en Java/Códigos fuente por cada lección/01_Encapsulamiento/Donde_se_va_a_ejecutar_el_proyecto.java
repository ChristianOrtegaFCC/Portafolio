
import packet_tracer.Red_packet_Tracer;            // Si vamos a separar nuestros scripts entre paquetes,
import packet_tracer.Subred_packetito_Tracercito;  // tendremos que importarlos en donde los usemos.

// NOTAS a considerar para Eclpise IDE:
// [!] El Quick Fix en Eclipse IDE puede ayudarte con problemas de sintáxis
// [!] Para arreglar errores, a veces hay que guardar de nuevo las clases.


// Esta es la sintáxis para Hacer un Hola mundo en Java:
public class Donde_se_va_a_ejecutar_el_proyecto {
	public static void main(String[] args) {
		System.out.println("Hola mundo");
		
		
		
		// Ahora, pasemos a POO:
		int contrasenia;
		
		// creamos un objeto (instancia) de la clase Red_packet_Tracer,
		// y uno de la clase Usuario
		Usuario U1 = new Usuario("Mapache",201927821,20);
		Red_packet_Tracer Red1 = new Red_packet_Tracer("Red_de_mentiras", 2524678, 400, 19.95);
		
		// Veamos que podemos hacer, dados los tres modificadores de acceso:
		// [1]: public........ Característica accesible por todos
		// [2]: private....... Característica accesible sólo por la propia classe
		// [3]: protected..... Característica accesible por la propia clase, y las clases derivadas
		
		// [!] Podemos hacer esto, porque nombre_de_la_red es "public"
		Red1.nombre_de_la_red = "Red_de_corrupcion";
		U1.existir();
		
		// Esto está mal, no se puede, porque todo esto es "private" (por eso hay errores)
		Red1.password = 1995;
		System.out.println("El password de "+Red1.nombre_de_la_red+" es: "+Red1.password);
		Red1.usar_red();
		U1.metodo_privado();
		
		// Esta es la forma correcta (para esto existen los getters y
		// setters, es para acceder a esta información desde la clase)
		Red1.Setnumero_de_hosts();
		Red1.Setpassword(1234567);
		contrasenia = Red1.Getpassword();
		System.out.println("La contrasenia de \""+Red1.nombre_de_la_red+"\" es: "+contrasenia+"\n");
		System.out.println("La contrasenia de \""+Red1.nombre_de_la_red+"\" es: "+Red1.Getpassword()+"\n");
		
		
		// Finalmente, el hijo...
		Subred_packetito_Tracercito Red2 = new Subred_packetito_Tracercito("Red_Mapache",666, 35, 3.1416,7);
		Red2.Muestra_toda_la_info();
	}
}
