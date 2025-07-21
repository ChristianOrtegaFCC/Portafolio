
public class Italiano extends Persona{
	
	public Italiano(String nombre, int edad) {
		super(nombre,edad);
	}
	
	// [!] Uso de @Override para modificar el comportamiento del método
	@Override
	public String hablar() {
		String frase = "Il mio nome e: "+nombre+". Sai spicco il volo.";
		System.out.println(frase);
		return frase;
	}
	
	public void Mover_la_manita_usando_la_munieca_con_los_cinco_dedos_pegados() {
		System.out.println("*Mueve la mano con la munieca y con los 5 dedos pegados*\n");
		return;
	}
}
