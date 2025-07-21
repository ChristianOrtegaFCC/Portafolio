
// La idea de Sobrecarga de miembros es que pueden haber varios métodos
// llamados igual, pero deben diferenciarse en el número de parámetros que
// reciben, y/o en el tipo de parámetros que reciben. Y esto aplica tanto
// para métodos constructores como métodos normales


public class Principal {
	public static void main(String[] args) {
		Persona Amauri = new Persona("Amauri",20);
		Persona Elpelos = new Persona("El pelos");
		Persona Elpreparado = new Persona("Jurgen",20);
		
		
		Elpreparado.apodo = "El preparado";
		
		// Para cada objeto de la clase persona, podemos "correr"
		// de maneras distintas:
		
		Amauri.correr();
		Amauri.correr(10);
		Amauri.correr(10.1);
		
		Elpelos.correr();
		Elpelos.correr(100);
		Elpelos.correr(100.1);
		
		Elpreparado.correr(0.001);
		
	}
}
