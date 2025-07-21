// El método destructor simplemente elimina una instancia creada. Aunque esto
// se hace automáticamente al finalizar la ejecución, así que no es necesario
// implementarlo manualmente, pero es algo curioso de ver :)

public class Main {
	public static void main(String[] args) throws Throwable {
		Perro P1 = new Perro("Toby","Schnauzer",25);//..... Constructor
		P1.jugar();
		P1.finalize();//........ Destructor
	}
}
