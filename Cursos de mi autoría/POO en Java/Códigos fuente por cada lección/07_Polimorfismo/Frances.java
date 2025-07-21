
public class Frances extends Persona{
	
	public Frances(String nombre, int edad) {
		super(nombre,edad);
	}
	
	// [!] Uso de @Override para modificar el comportamiento del método
	@Override
	public String hablar() {
		String frase = "Mon nom est: "+nombre+". De ton regard amoureux";
		System.out.println(frase);
		return frase;
	}
	
	public void comer_baguettes() {
		System.out.println("*Se atiborra de baguettes :)*\n");
		return;
	}
}
