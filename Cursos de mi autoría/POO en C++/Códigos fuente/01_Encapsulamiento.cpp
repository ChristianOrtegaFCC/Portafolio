#include <iostream>
using namespace std;

// El encapsulamiento consiste en restringir el acceso a los detalles internos de
// una clase y proteger su estado interno de modificaciones no deseadas. ¿Cómo lo
// hacemos? Mediante el uso de modificadores de acceso y la definición de métodos
// públicos hechos para interactuar con los datos de la clase.

class Red_packet_Tracer {

	// AQUI SE DA EL ENCAPSULAMIENTO !!!!
	
	// Con "public" definimos la lista de atributos visibles en todo el código
	public:
		string nombre_de_la_red;
	
	// Con "protected", las que son visibles por la propia clase y las clases derivadas
	protected:
		int password;
		int numero_de_hosts;
		double ingresos;
	
	public:
	// MÉTODO CONSTRUCTOR
	Red_packet_Tracer(string nombre_de_la_red, int password, int numero_de_hosts ,double ingresos){
		this->nombre_de_la_red = nombre_de_la_red;
		this->password = password;
		this->numero_de_hosts = numero_de_hosts;
		this->ingresos = ingresos;
	}
	
	// MÉTODOS NORMALES
	void mostrar_red() {
		cout<<"!!! Red disponible: "<<nombre_de_la_red<<endl;
	}
	
	void usar_red() {
		cout<<"Red en línea..."<<endl;
	}
	
	void Muestra_toda_la_info() {
		cout<<"Nombre: "<<nombre_de_la_red;
		printf(", Pass: %d",password);
		printf(", Num-H: %d",numero_de_hosts);
		printf(", ingresos: %f ",ingresos);
		printf("");
		return;
	}
	
	// MÉTODOS GETTER Y SETTER !!!!
	
	// GETTERS: El punto de un getter es preguntarle un valor específico de su clase
	string Getnombre() {
		return nombre_de_la_red;
	}
	
	int Getpassword() {
		return password;
	}
	
	int Getnumero_de_hosts() {
		return numero_de_hosts;
	}
	
	double Getingresos() {
		return ingresos;
	}
	
	
	// SETTERS: El punto de un setter es establacer un valor específico de su clase
	void  Setnombre(string nombre_de_la_red) {
		this->nombre_de_la_red = nombre_de_la_red;
		return;
	}
	
	void Setpassword(int password) {
		this->password = password;
		return;
	}
	
	// NOTA ESTO:
	// En realidad, nada nos impide que un SETTER tenga su propio funcionamiento
	// interno. En realidad nada te impide que aquí te armes todo un sistema si
	// eso es lo que quieres, pero el punto de un SETTER es "SETTEAR" un valor.
	// Un método setter no es diferente de otro método común y corriente, sin
	// embargo la convención es: recibir un valor, y asignarlo. No más (y lo)
	// mismo aplica para los GETTERS; puedes poner dentro de un GETTER lo que
	// quieras, pero el punto debe ser devolver el valor específico. Aunque
	// la convención es simplemente devolvero sin más.
	void Setnumero_de_hosts() {
		int Valor;
		printf("Dame el numero de hosts: ");
		cin>>Valor;
		this->numero_de_hosts = Valor;
		return;
	}
	
	void Setingresos(double ingresos) {
		this->ingresos = ingresos;
		return;
	}
	
};

class Subred_packet_Tracer : public Red_packet_Tracer{
	public:
		int sector;
	
	public:
	Subred_packet_Tracer(string nombre_de_la_red, int password, int numero_de_hosts ,double ingresos,int sector) :  Red_packet_Tracer(nombre_de_la_red,password,numero_de_hosts,ingresos){
		this->sector = sector;
	}
	
};

class Usuario {
	public:
		string nombre;
		int IDE;
		int edad;
	
	public:
		Usuario(string nombre, int IDE, int edad) {
			this->nombre = nombre;
			this->IDE = IDE;
			this->edad = edad;
		}
	
		void existir() {
			cout<<"me llamo "<<nombre<<"("<<IDE<<") y tengo "<<edad<<" anios\n";
		}
	
	private:
		void metodo_privado() {
			printf("Realizando operaciones vulnerables...\n");
		}
};

int main(){
	int contrasenia;
		
	Usuario U1("Mapache",201927821,20);
	Red_packet_Tracer Red1("Red_de_mentiras", 2524678, 400, 19.95);

	Red1.nombre_de_la_red = "Red_de_corrupcion";
	U1.existir();
	
	/*  Esto no se puede hacer, porque son atributios "private":

		Red1.password = 1995;
		System.out.println("El password de "+Red1.nombre_de_la_red+" es: "+Red1.password);
		Red1.usar_red();
		U1.metodo_privado();*/
	
	// Esto es lo apropiado
	Red1.Setnumero_de_hosts();
	Red1.Setpassword(1234567);
	contrasenia = Red1.Getpassword();
	
	cout<<" La contrasenia de \""<< Red1.Getnombre() <<"\" es: "<<contrasenia<<"\n";
	
	// Finalmente, con el 'hijo'...
	Subred_packet_Tracer Red2("Red_dead_redemption",666, 35, 3.1416,7);
	Red2.Muestra_toda_la_info();
}
