import java.util.Scanner;
import java.util.LinkedList;

//En esto sí me hice bolas la vdd xd
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);	String palabra,palabra2; int entero;
		System.out.print("Dame una palabra: ");  palabra = scan.next();
		System.out.print("Dame otra palabra: "); palabra2 = scan.next();
		
		
		// Genericidad es a los datos, lo que las interfaces a los métodos
		
		
		/*
		// Lista (clase genérica de la librería LinkedList) de datos sin definir, de esta forma salen warnings
		LinkedList Lista = new LinkedList();
		Lista.add(palabra);
		palabra2 = (String)Lista.getFirst(); // para que esto funcione, Lista.getfirst debe ahuevo estar casteado a String
		System.out.println("Lista.first = "+Lista.getFirst());
		*/
		
		
		
		/*
		LinkedList <String>Lista2 = new LinkedList<>(); // operador diamante, en este caso indicamos que la lista será de String's
		Lista2.add(palabra);
		palabra2 = Lista2.getFirst(); // chequea, ya no hay warnings
		System.out.println("Lista.first = "+Lista2.getFirst());
		*/
		
		
		
		/*
		LinkedList <Clase_Normal> Tasers = new LinkedList<>();// en este caso indicamos que la lista será de Clase_Normal's
		Clase_Normal Taser1 = new Clase_Normal("Aturdidor",12.5,3.5,false);
		Clase_Normal Taser2 = new Clase_Normal("-",0,0,false);
		Tasers.add(palabra);// hey esto está mal, 'palabra' es clase "String", yo quiero objetos clase "Clase_Normal"
		Tasers.add(Taser1);// hey esto está bien
		Taser2 = Tasers.getFirst();
		System.out.println(Taser2.modelo);
		*/
		
		
		
		/*
		// A esta lista le pasaremos Clases normales:
		Clase_Normal T1 = new Clase_Normal("Rayito",3.14,2.1,false);
		Clase_Normal T2 = new Clase_Normal("Rayote",14.3,1.2,false);
		
		LinkedList <Clase_Generica> Lista_de_quiensabeque = new LinkedList<>();
		Clase_Generica <Clase_Normal> OBJ = new Clase_Generica<>(T1);
		Clase_Generica <Clase_Normal> OBJ2 = new Clase_Generica<>(T2);
		//Clase_Generica <Clase_Normal> OBJ3 = new Clase_Generica<>("Rayote",14.3,1.2,false); // esto está mal
		//Como objeto de clase entero, podemos imprimirlo:
		System.out.println("\nValor de \"OBJ\": "+OBJ.dato);
		OBJ2.oye_wey_tu_que_madres_usas();
		
		
		
		
		// Ahora, No puedes parametrizar variables primitivas; int, float, double, boolean... Así como así
		//
		// 		Esto está mal:
		//
		//			Clase_Generica <int> OBJ_INT = new Clase_Generica<>(10);
		// 			Clase_Generica <boolean> OBJ2_INT = new Clase_Generica<>(false);
		//
		// Si quieres por ejemplo una lista de enteros, debes covertir el entero a clase. ¿y como por qué?
		// chingados necesitaría yo hacer eso?. Esque LinkedList es una clase genérica, no sabe lo que vendrá
		// sólo sabe que recibira un dato de una CLASE en partícular. entonces convertimos en enero a clase
		// mediante el operador diamante:
		
		// A esta lista le pasaremos enteros:
		int x=1,y=2;
		
		LinkedList <Clase_Generica> Lista_de_quiensabeque2 = new LinkedList<>();
		Clase_Generica <Integer> OBJ_INT = new Clase_Generica<>(x);
		Clase_Generica <Integer> OBJ2_INT = new Clase_Generica<>(y);
		//Como objeto de clase entero, podemos imprimirlo:
		System.out.println("Valor de \"OBJ_INT\": "+OBJ_INT.dato);
		OBJ2_INT.oye_wey_tu_que_madres_usas();
		
		
		
		// A esta lista le pasaremos doubles:
		double j=3.1416,k=2.7;
		
		LinkedList <Clase_Generica> Lista_de_quiensabeque3 = new LinkedList<>();
		Clase_Generica <Double> OBJ_DOUBLE = new Clase_Generica<>(j);
		Clase_Generica <Double> OBJ2_DOUBLE = new Clase_Generica<>(k);
		//Como objeto de clase entero, podemos imprimirlo:
		System.out.println("Valor de \"OBJ2_DOUBLE\": "+OBJ2_DOUBLE.dato);
		OBJ2_DOUBLE.oye_wey_tu_que_madres_usas();
		
		// Lista_de_quiensabeque, Lista_de_quiensabeque2 y Lista_de_quiensabeque3 son todas listas(LinkedList) de
		// clase genérica, aparte, el tipo de clase que se le manda es genérica, por lo que realmente podemos meter
		// datos de todo tipos tanto a Lista_de_quiensabeque, Lista_de_quiensabeque2 y Lista_de_quiensabeque3:
		
		// Chequea esto:
		Lista_de_quiensabeque.add(OBJ);
		Lista_de_quiensabeque.add(OBJ_INT);
		Lista_de_quiensabeque.add(OBJ2_DOUBLE);
		
		Lista_de_quiensabeque2.add(OBJ2_INT);
		Lista_de_quiensabeque2.add(OBJ2_DOUBLE);
		Lista_de_quiensabeque2.add(OBJ_INT);
		
		Lista_de_quiensabeque3.add(OBJ2_DOUBLE);
		Lista_de_quiensabeque3.add(OBJ_INT);
		Lista_de_quiensabeque3.add(OBJ2);
		
		System.out.println(Lista_de_quiensabeque.getFirst().dato);
		System.out.println(Lista_de_quiensabeque.getLast().dato);
		
		System.out.println(Lista_de_quiensabeque2.getFirst().dato);
		System.out.println(Lista_de_quiensabeque2.getLast().dato);
		
		System.out.println(Lista_de_quiensabeque3.getFirst().dato);
		System.out.println(Lista_de_quiensabeque3.getLast().dato);
		*/
		
		scan.close();
	}
}
