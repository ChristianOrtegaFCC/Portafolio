
public class Ruso extends Persona{
	
	public Ruso(String nombre, int edad) {
		super(nombre,edad);
	}
	
	// [!] Uso de @Override para modificar el comportamiento del método
	@Override
	public String hablar() {
		String frase = "MEHR 3OByT:"+nombre+". MOCKBA MOCKBA Y TbI XOPOXO";
		System.out.println(frase);
		return frase;
	}
	
	public void Domar_osos() {
		System.out.println("*Monta un oso*\n");
		return;
	}
}
