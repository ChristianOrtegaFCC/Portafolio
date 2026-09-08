import java.util.Scanner;
//import Excepciones.Excepcion_de_rango;
//import Excepciones.Impostor;

public class TryCatch {
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		// EXCEPCIONES Básicas ( try-catch-finally ) ////////////////////////////////////////////////////
		/*
		int x; int y=2; String aux;
		try{ // dentro del try está la parte del código en la que puede haber un error o varios
			
			// caso[1]: leer un dato de un tipo diferente al que se nos pide (como ingresar un char cuando se te pide int)
			System.out.print("Dame un numero: ");
			aux = cin.next();
			x = Integer.parseInt(aux); // Casteo
			
			// caso[2]: Dividir entre cero
			System.out.print("Lo dividimos entre "+y+": ");
			System.out.println("("+x+"/"+y+") = "+(x/y));
			cin.close();
	
		}catch(ArithmeticException ex){
			// esta parte del código administrará el error proventiente del caso [2]
			System.out.println("No es posible dividir entre cero.");
		}catch(NumberFormatException e){
			// esta parte del código debería administrar el error proventiente del caso [1]
			System.out.println("Escribe un dato legible para la operacion.");
		}finally { 
			// finally{} se ejecuta independientemente de que si hubo erroes o no
			System.out.println(".\n.\n.\n.\nVes?. Te lo dije Carl. Y tu preocupado.");
		}
		
		// si te pones a pensar un poco, escribir finally es un casi igual a simplemente no escribirlo xd 
		System.out.println("Bueno adios");
		*/
		
		
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		// EXCEPCIONES PERSONALIZADAS 1 ( trow ) /////////////////////////////////////////////////////////
		/*
		int edad;
		System.out.print("Dame tu edad: ");
		edad = cin.nextInt();
		
		try {
			if(edad < 100) {
				System.out.println("Va");
			}else {
				throw new Excepcion_de_rango("Rango incorrecto"); // !!!! throw PROVOCA UN ERROR, pero es por tu bien !!!!
			}
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		*/
		
		
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		// EXCEPCIONES PERSONALIZADAS 2 ( trow ) ////////////////////////////////////////////////////////
		/*
		String nombre;
		System.out.print("Dame tu nombre: ");
		nombre = cin.next();
	
		try { // import esta excepción !!!!!
			if(nombre.equals("Mapache")) { // comparar strings !!!!
				throw new Impostor("Esta mintiendo,",15); // nuestra excepción super personalizada!!!!, throw hace fallar el try, y catch(Exception e) se encarga
			}else {
				System.out.println("Va");
			}
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		*/
		
		
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		// EXCEPCIONES PERSONALIZADAS MEZCLADAS ( trow ) ////////////////////////////////////////////////
		
		try {// Mezclados
			String nombre; int edad; String aux_edad;
		
			System.out.print("Dame tu nombre: ");
			nombre = cin.next();
			if(nombre.equals("Mapache")) throw new Impostor("Esta mintiendo,",15);
			else System.out.println("Va");
			
			System.out.print("\nDame tu edad: ");
			aux_edad = cin.next();
			edad = Integer.parseInt(aux_edad); // Casteo
			if(edad < 100)	System.out.println("Va");
			else throw new Excepcion_de_rango("Rango incorrecto");
			
		}catch(NumberFormatException e) {	
			System.out.println("Dame un numero entero cuando te pido un numero entero");
		}catch(Exception e){
			System.out.println(e.getMessage());
		}// finally{
		
		
		return;
	}
}















