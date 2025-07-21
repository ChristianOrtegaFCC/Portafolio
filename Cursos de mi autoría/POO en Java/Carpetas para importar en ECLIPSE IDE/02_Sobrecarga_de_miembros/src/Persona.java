public class Persona {
	String nombre;
	int edad;
	String apodo;
	
	//// constructores ///////////////////////////
	public Persona(String nombre, int edad) {	//
		this.nombre = nombre;					//
		this.edad = edad;						//
	}											//
												//
	public Persona(String apodo) {				//
		this.apodo = apodo;						//
	}											//
	///////////////////////////////////////////////
	
	
	// formas de correr //////////////////////////////////////////////////////////////////////////////////////
	public void correr() {																					//
		System.out.println("Estoy corriendo, como ordenaste senior xdxd...");								//
		System.out.println("Y entonces "+nombre+" '"+apodo+"' Corrio...\n");									//
	}																										//
																											//
	public void correr(int km) {																			//
		System.out.println("Voy a correr "+km+"km como ordenaste, senior...");								//
		System.out.println("Y entonces "+nombre+" '"+apodo+"' Corrio "+km+"km...\n");						//
	}																										//
																											//
	public void correr(double km) {																			//
		System.out.println("Voy a correr "+km+"km con la presicion milimetrica que ordenaste, senior...");	//
		System.out.println("Y entonces "+nombre+" '"+apodo+"' Corrio exactamente "+km+"km, luego murio\n");//
	}																										//
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
}
