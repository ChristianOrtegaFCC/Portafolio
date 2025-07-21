import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner cin = new Scanner(System.in);
		
		// [!] Oye ¿cuál es la estructura básica de un archivo? identifícala...
		int x; int y=2; String aux; boolean band_error = false;
		try{
			// caso[n]: leer un archivo
			File archivo = new File("C:\\Users\\rocke\\eclipse-workspace\\05_Exepciones_pt2\\src\\Jimmy_truco.txt");
			FileReader fr = new FileReader(archivo);
			BufferedReader bf = new BufferedReader(fr);
			String linea;
			
			while((linea = bf.readLine()) != null){ // IOException
				System.out.println(linea);
			}
		
		}catch(FileNotFoundException ex){
			System.out.println("Archivo no encontrado.");
			System.out.println("Presiona una tecla para volver a intentar.");
			aux = cin.next();
			if(aux.equals("Salir")) return;
			Main.main(args); // puede ser que por esto algunos prefieren usar el try catch en un método aparte
			band_error = true;
		}

		if(band_error == false)	System.out.println("\n >> Exito");
		else System.out.println("\n >> Fracaso");
		
		return;
	}
}
