public class Persona {
	String nombre;
	int edad;
	String apodo;
	
	//// Diferentes constructores, diferenciadas por el tipo y número de parámetros:
	public Persona(String nombre, int edad) {	
		this.nombre = nombre;					
		this.edad = edad;						
	}											
												
	public Persona(String apodo) {				
		this.apodo = apodo;						
	}											
	
	
	
	// Distintas métodos para correr, diferenciadas por el tipo y número de parámetros:
	public void correr() {																					
		System.out.println("Estoy corriendo...");								
		System.out.println("Y entonces "+nombre+" '"+apodo+"' Corrio...\n");								
	}																										
																											
	public void correr(int km) {																			
		System.out.println("Voy a correr "+km+"km...");								
		System.out.println("Y entonces "+nombre+" '"+apodo+"' Corrio "+km+"km...\n");						
	}																										
																											
	public void correr(double km) {																			
		System.out.println("Voy a correr "+km+"km con la presicion milimetrica que ordenaste...");	
		System.out.println("Y entonces "+nombre+" '"+apodo+"' Corrio exactamente "+km+"km\n");
	}																										
}
