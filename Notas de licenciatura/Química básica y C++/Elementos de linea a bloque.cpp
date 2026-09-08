// datos de linea a bloque
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void inicializar_elementos();
void escribir_elementos_por_bloque();

struct elemento{
	std::string nombre;
	std::string simbolo;
	int z; // numero atomico
	float masa_atomica;
};

elemento elementos[119];// 118 elementos
string auxs[119];

void inicializar_elementos(){
	int i=1;
	elemento aux;
	std::ifstream reader;
    reader.open("ElementosPorLinea.txt",  std::ios::in);
    if (reader.is_open()) {
        while (!reader.eof()) {
            reader >> auxs[i];//elementos[i].z;//aux.z;
            reader >> elementos[i].nombre;
            reader >> elementos[i].simbolo;
            i++;
        }
    } else {
        std::cout << "Error! El archivo no pudo ser abierto." << std::endl;
    }
    reader.close();
}

void escribir_elementos_por_bloque(){
	int i = 1;
	std::string linea;
	std::ofstream archivo;
	archivo.open("ElementosPorBloque.txt",std::ios::out);
	if(archivo.fail()){
		std::cout<<"no se pudo crear el archivo\n";
		exit(1);
	}
	for(i=1;i<=118;i++){ 
		
		linea = auxs[i]+"\n";
		archivo<<linea;
		linea = elementos[i].nombre+"\n";
		archivo<<linea;
		linea = elementos[i].simbolo+"\n";
		archivo<<linea;
		
	}
}


int main(){
	inicializar_elementos();
	escribir_elementos_por_bloque();
	return 0;
}



