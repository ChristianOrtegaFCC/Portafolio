
// Los miembros estáticos (atributos y métodos) pertenecen a la clase en sí,
// no a instancias individuales de la clase. Esto significa que hay un solo
// valor o implementación compartida entre todas las instancias.

// Pensemos en el UNIFORME de una escuela, todos los alumnos deben usar el mismo.

public class Main {
	public static void main(String[] args) {
		final int cupo = 10; int i;
		
		// Instanciamos un array de objetos:
		Estudiante_de_primaria Alumnado[] = new Estudiante_de_primaria[cupo];
		for(i=0; i<10 ;i++)	Alumnado[i] = new Estudiante_de_primaria(4,"-","-");
		
		// Los nombres de los niños, no tienen por qué ser el mismo....
		Alumnado[0].nombre = "Stan";    Alumnado[1].nombre = "Kyle";  Alumnado[2].nombre = "Erik";   Alumnado[3].nombre = "Kenny";  
		Alumnado[4].nombre = "Butters"; Alumnado[5].nombre = "Wendy"; Alumnado[6].nombre = "Token";  Alumnado[7].nombre = "Timmy";  
		Alumnado[8].nombre = "Jimmy";   Alumnado[9].nombre = "Tweek";
		
		// Pero aunque intentemos darle ropa diferente a cada uno.... (a)
		Alumnado[0].uniforme = "Ropa azul";  Alumnado[1].uniforme = "Ropa naranja";  Alumnado[2].uniforme = "Ropa roja";  Alumnado[3].uniforme = "sueter naranja";  
		Alumnado[4].uniforme = "Ropa cyan";  Alumnado[5].uniforme = "Ropa rosa";  Alumnado[6].uniforme = "Ropa morada";  Alumnado[7].uniforme = "silla de ruedas";  
		Alumnado[8].uniforme = "playera amarilla";  Alumnado[9].uniforme = "Ropa cafe";  
		
		// (a)...... Si su escuela quiere que usen uniforme, todos deberán seguir esa
		// constante (Con esta única linea, cambiamos el valor de "uniforme" de todos
		// los niños) porque "uniforme" es un atributo estático.
		Alumnado[4].uniforme = "Pantalon gris, camisa blanca y sueter color verde feo";
		
		// Modelan sus uniformes...
		for(i=0;i<10;i++) Alumnado[i].modelar_uniforme();
		
		
		// Básicamente si cambias el valor de un atributo static de una instancia (objeto), el
		// cambio se verá reflejado en todos los objetos, para ese atributo (porque es estático).
		
		
		// Ahora, los métodos static pueden mandar a llamarse sin la necesidad de crear un objeto
		// simplemente mandamos a llamar el método con el nombre de la clase, así:
		
		Estudiante_de_primaria.leer();
		
	}
}
