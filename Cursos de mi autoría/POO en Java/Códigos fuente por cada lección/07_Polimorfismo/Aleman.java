
public class Aleman extends Persona{
	
	public Aleman(String nombre, int edad) {
		super(nombre,edad);
	}
	
	// [!] Uso de @Override para modificar el comportamiento del método
	@Override
	public String hablar() {
		String frase = "Mein name ist: "+nombre+". Du, Du hast, Du hast mich";
		System.out.println(frase);
		return frase;
	}
	
	public void comer_salchicas_y_beber_cerveza() {
		System.out.println("*Come salchicas y bebe cerveza*\n");
		return;
	}
}
