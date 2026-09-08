// El manejo de excepciones simplemente consiste en la gestión de errores en la
// ejecución, esa es toda la teoría.

import java.util.Scanner;
import Excepciones.Excepcion_de_rango;
import Excepciones.Impostor;

public class TryCatch {
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		
		
		// [I] EXCEPCIONES BÁSICAS ( try-catch-finally )
		int x; int y=2; String aux;
		try{
			// Dentro del try está la parte del código en la que puede haber
			// uno o varios errores
			
			// Caso[1]: leer un dato de un tipo diferente al que se nos pide
			// (como ingresar un char cuando se te pide int)
			System.out.print("Dame un numero: ");
			aux = cin.next();
			x = Integer.parseInt(aux); // Cast de datos (área de riesgo de error)
			
			// Caso[2]: Dividir entre cero
			System.out.print("Lo dividimos entre "+y+": ");
			System.out.println("("+x+"/"+y+") = "+(x/y));
			cin.close();
	
		}catch(ArithmeticException ex){
			// Esta parte del código administrará el error proventiente del caso [2]
			System.out.println("No es posible dividir entre cero.");
		}catch(NumberFormatException e){
			// Esta parte del código debería administrar el error proventiente del caso [1]
			System.out.println("Escribe un dato legible para la operacion.");
		}finally { 
			// El bloque finally {...} es un bloque que se ejecuta sí o sí,
			// Independientemente de que ocurran errores o no
			System.out.println(".\n.\n.\n.\nTodo salio bien.");
		}
		
		// Si te pones a pensar un poco, escribir "finally" es lo mismo
		// que simplemente no escribirlo jajajaja.
		
		
		
		
		
		
		
		
		// [II] EXCEPCIONES PERSONALIZADAS ( trow )
		int edad;
		System.out.print("Dame tu edad: ");
		edad = cin.nextInt();
		
		try {
			if(edad < 100) {
				System.out.println("Ok");
			}else {
				// [!] throw PROVOCA UN ERROR (pero es por tu bien)
				throw new Excepcion_de_rango("Rango incorrecto");
			}
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		
		
		
		
		
		
		

		// [III] MÁS EXCEPCIONES PERSONALIZADAS ( trow )
		String nombre;
		System.out.print("Dame tu nombre: ");
		nombre = cin.next();
	
		try {//................................... [!] Recuerda importar esta excepción.
			if(nombre.equals("Mapache")) {//...... [!] Compara strings (zona de riesgo).
				
				// En nuestra excepción personalizada (importada); "throw" hace
				// fallar el "try", y el "catch(Exception e)" se encarga de
				// gestionar ese error, como corresponda.
				throw new Impostor("Esta mintiendo,",15); //... Son los parámetros que nuestra
			}else {//.......................................... Excepción importada requiere.
				System.out.println("Ok");
			}
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		
		
		
		
		
		
		
		
		// [IV] EXCEPCIONES PERSONALIZADAS MEZCLADAS ( trow )
		try {
			String aux_edad;
		
			System.out.print("Dame tu nombre: ");
			nombre = cin.next();
			if(nombre.equals("Mapache")) throw new Impostor("Esta mintiendo,",15);
			else System.out.println("Va");
			
			System.out.print("\nDame tu edad: ");
			aux_edad = cin.next();
			edad = Integer.parseInt(aux_edad); //......... [!] Cast de tipo de dato.
			if(edad < 100)	System.out.println("Va");
			else throw new Excepcion_de_rango("Rango incorrecto");
			
		}catch(NumberFormatException e) {	
			System.out.println("Dame un numero entero cuando te pido un numero entero");
		}catch(Exception e){
			System.out.println(e.getMessage());
		}finally{
			
		}
		
		return;
	}
}


