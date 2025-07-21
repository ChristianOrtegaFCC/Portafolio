
public class Main {
	public static void main(String[] args) {
		final int cupo = 10; int i;
		
		// chequeate cómo se instancia un array de objetos, paaaaa
		Estudiante_de_primaria Alumnado[] = new Estudiante_de_primaria[cupo];
		for(i=0; i<10 ;i++)	Alumnado[i] = new Estudiante_de_primaria(4,"-","-");
		
		Alumnado[0].nombre = "Stan";    Alumnado[1].nombre = "Kyle";  Alumnado[2].nombre = "Erik";   Alumnado[3].nombre = "Kenny";  
		Alumnado[4].nombre = "Butters"; Alumnado[5].nombre = "Wendy"; Alumnado[6].nombre = "Token";  Alumnado[7].nombre = "Timmy";  
		Alumnado[8].nombre = "Jimmy";   Alumnado[9].nombre = "Tweek";
		
		// !!!!!
		Alumnado[0].uniforme = "Ropa azul";  Alumnado[1].uniforme = "Ropa naranja";  Alumnado[2].uniforme = "Ropa roja";  Alumnado[3].uniforme = "sueter naranja";  
		Alumnado[4].uniforme = "Ropa cyan";  Alumnado[5].uniforme = "Ropa rosa";  Alumnado[6].uniforme = "Ropa morada";  Alumnado[7].uniforme = "silla de ruedas";  
		Alumnado[8].uniforme = "playera amarilla";  Alumnado[9].uniforme = "Ropa cafe";  
		
		// !!!!!
		Alumnado[4].uniforme = "Pantalon gris, camisa blanca y sueter color verde caca";
		
		// modelan sus uniformes...
		for(i=0;i<10;i++) Alumnado[i].modelar_uniforme(); //System.out.println();
		
		// !!!!
		// Básicamente si cambias el valor de un atributo static de una instancia (objeto), el
		// cambio se verá reflejado en todos los objetos, para ese atributo.
		
		
		// Ahora, los métodos static pueden mandar a llamarse sin la necesidad de crear un objeto
		// simplemente mandamos a llamar el método con el nombre de la clase, así:
		
		// Menciona el Quick Fix
		
		// Menciona que para arreglar errores, a veces hay que guardar de nuevo las clases.
		
		Estudiante_de_primaria.leer();
		
	}
}
