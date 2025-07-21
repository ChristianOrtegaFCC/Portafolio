// c�lculo de configuraci�n electr�nica V3
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

enum Colors { BLACK = 0, BLUE = 1, GREEN = 2, CYAN = 3, RED = 4, MAGENTA = 5, BROWN = 6, LGREY = 7, DGREY = 8, LBLUE = 9, LGREEN = 10, LCYAN = 11, LRED = 12, LMAGENTA = 13, YELLOW = 14, WHITE = 15};
std::string configuracion_electronica(int z);
void Color(int Background, int Text);
int Busca_elemento(std::string buscar);
int Busca_simbolo(std::string buscar);
int Busca_z(int buscar);
void inicializar_elementos();
std::string error_caso(int code);

struct elemento{
	std::string nombre;
	std::string simbolo;
	int z; // numero atomico
	float masa_atomica;
};

elemento elementos[120];

int main(){
	inicializar_elementos();
	std::string entrada;
	int i,z, it;
	//printf("mmhh...");
	//for(i=1;i<117;i++) std::cout<<"["<<i<<"]\t"<<"Z="<<elementos[i].z<<"\t"<<elementos[i].simbolo<<"\t"<<elementos[i].nombre<<std::endl;
	//return 0;
	//std::cout<<"Z="<<elementos[45].z<<"\t"<<elementos[45].simbolo<<"\t"<<elementos[45].nombre<<std::endl;
	//while(true){
	//std::cout<<"dame la entrada (numero atomico, simbolo o nombre): ";
	//std::cin>>entrada;
	
	for(it =1;it<=118;it++){
	std::cout<<"dame la entrada (numero atomico, simbolo o nombre): ";
	entrada = elementos[it].nombre;
	std::cout<<entrada<<" ------------\n";
	
	if(entrada.length()<=3){
		switch(entrada.length()){
			case 1:
				if (entrada[0]-'0' >= 17)  Busca_simbolo(entrada);//error_caso(1);// no integer
				else {
					z = entrada[0] - '0';
					Busca_z(z);
				}
				break;
			case 2:
				if (entrada[0]-'0' >= 17 ||entrada[1]-'0' >= 17) Busca_simbolo(entrada);// s�mbolos ?	
				else{
					z = ((entrada[0] - '0')*10)+(entrada[1] - '0');
					Busca_z(z);
				}
				break;
			case 3:
				if (entrada[0]-'0' >= 17 ||entrada[1]-'0' >= 17 ||entrada[2]-'0' >= 17) Busca_elemento(entrada);//{ }
				else{
					z = ((entrada[0] - '0')*100)+((entrada[1] - '0')*10)+(entrada[2] - '0');
					Busca_z(z);
				}
				break;
		}
	}else{
		Busca_elemento(entrada);
	}
	std::cout<<std::endl;
}
return 0;
}


std::string configuracion_electronica(int z){
	int i, counter=0;char lastlet, lastnum;	bool jmp = false; 
	
	if (z <= 0 || z > 118){ error_caso(5); return ".l."; }
	if (z == 1){ printf("1S"); Color(BLACK, RED); printf("1\n");  Color(BLACK, WHITE);return "1S1"; }
	
	for(i=1;i<=z;i++){
		jmp = false;
		
		// Orbital S
		if (i == 2 || i == 4 || i == 12 || i ==  20 || i ==  38 || i == 56 || i ==  88 ){
			counter =0;
			switch(i){
				case 2:		lastlet = 'S';	printf("1");lastnum = '2';break;
				case 4:		lastlet = 'P';	printf("2");lastnum = '2';break;
				case 12:	lastlet = 'P';	printf("3");lastnum = '3';break;
				case 20:	lastlet = 'd';	printf("4");lastnum = '3';;break;
				case 38:	lastlet = 'd';	printf("5");lastnum = '4';break;
				case 56:	lastlet = 'F';	printf("6");lastnum = '4';break;
				case 88:	lastlet = 'F';	printf("7");lastnum = '5';break;
			}
			printf("S");
			if (i!= z){ Color(BLACK, RED); printf("2 "); jmp = true; Color(BLACK, WHITE);}
		}
		
		// Orbital P
		if (i == 10 || i == 18 || i == 36 || i ==  54 || i ==  86 || i == 118){
			lastlet = 'S';	counter =0;
			switch(i){
				case 10:	printf("2");lastnum = '3';break;
				case 18:	printf("3");lastnum = '4';break;
				case 36:	printf("4");lastnum = '5';break;
				case 54:	printf("5");lastnum = '6';break;
				case 86:	printf("6");lastnum = '7';break;
				case 118:	printf("7");lastnum = '8';break;
			}
			printf("P");
			if (i!= z){Color(BLACK, RED); printf("6 ");jmp = true; Color(BLACK, WHITE);}
		}
		
		
		// Orbital d
		if (i == 30 || i == 48 || i == 80 || i ==  112 ){
			lastlet = 'P';	counter =0;
			switch(i){
				case 30:	printf("3");lastnum = '4';break;
				case 48:	printf("4");lastnum = '5';break;
				case 80:	printf("5");lastnum = '6';break;
				case 112:	printf("6");lastnum = '7';break;
			}
			printf("d");
			if (i!= z){Color(BLACK, RED); printf("10 ");jmp = true;Color(BLACK, WHITE);}
		}
		
		// Orbital F
		if (i == 70 || i == 102 ){
			lastlet = 'd';	counter =0;
			switch(i){
				case 70:	printf("4");lastnum = '5';break;
				case 102:	printf("5");lastnum = '6';break;
			}
			printf("F");
			if (i!= z){Color(BLACK, RED); printf("14 ");jmp = true;Color(BLACK, WHITE);}
		}
		counter ++;
	}
	
	
	//if (jmp != true) printf("%c%c",lastnum,lastlet);
	Color(BLACK, RED);
		switch(z){
			case 2: printf("2 ");break;			case 4: printf("2 ");break;
			case 10: printf("6 ");break;		case 12: printf("2 ");break;
			case 18: printf("6 ");break;		case 20: printf("2 ");break;
			case 30: printf("10 ");break;		case 36: printf("6 ");break;
			case 38: printf("2 ");break;		case 48: printf("10 ");break;
			case 54: printf("6 ");break;		case 56: printf("2 ");break;
			case 70: printf("14 ");break;		case 80: printf("10 ");break;
			case 86: printf("6 ");break;		case 88: printf("2 ");break;
			case 102: printf("14 ");break;		case 112: printf("10 ");break;
			case 118: printf("6 ");break;		default: Color(BLACK, WHITE); printf("%c%c",lastnum,lastlet); Color(BLACK, RED); printf("%d",counter-1); //printf("%c%c%d",lastnum,lastlet,counter-1);  
		}
	Color(BLACK, WHITE);
	printf("\n");
	return "xd";
}

std::string error_caso(int code){
	switch(code){
		case 1:
			printf("Solo diste una letra");
			return "Solo diste una letra";
			break;
		case 2:
			printf("Eso no es el simbolo de ningun elemento");
			return "Eso no es el simbolo de ningun elemento";
			break;
		case 3:
			printf("Eso no es un  elemento");
			return "Eso no es un  elemento";
			break;
		case 4:
			printf("Uno de los caracteres no es un digito");
			return "Uno de los caracteres no es un digito";
			break;
		case 5:
			printf("Rango inválido");
			return "Rango inválido";
			break;	
		default:
			printf("Algo salió mal");
			return "Algo salió mal";
			break;
	}
	return "Algo salió mal";
}

int Busca_simbolo(std::string buscar){
	int i,z;bool found = false;
	buscar[0]=  toupper(buscar[0]);
	buscar[1]=  tolower(buscar[1]);
	for(i=1;i<=118;i++){
		if(buscar == elementos[i].simbolo){
			Color(BLACK, CYAN);std::cout<<"["<<buscar<<"]";
			Color(BLACK,WHITE);std::cout<<": "<<elementos[i].nombre;
			printf(", Z="); Color(BLACK, BROWN); printf("%d",elementos[i].z); Color(BLACK, WHITE); printf(":  ");
			configuracion_electronica(elementos[i].z);
			found = true;
			z = elementos[i].z;
			break;
		}
	}
	if(found== false){
		std::cout<<"El elemento que estas buscando no existe en la tabla periodica\n\n";
		return -1;
	}
	return z;
}

int Busca_elemento(std::string buscar){
	int i,j,z;bool found = false;
	buscar[0]=  towupper(buscar[0]);
	for(j=1;j<=buscar.length();j++) buscar[j] = tolower(buscar[j]);
	for(i=1;i<=118;i++){
		if(buscar == elementos[i].nombre){
			Color(BLACK, CYAN);std::cout<<"["<<elementos[i].simbolo<<"]";
			Color(BLACK,WHITE);std::cout<<": "<<elementos[i].nombre;
			printf(", Z="); Color(BLACK, BROWN); printf("%d",elementos[i].z); Color(BLACK, WHITE); printf(":  ");
			configuracion_electronica(elementos[i].z);
			found = true;
			z = elementos[i].z;
			break;
		}
	}
	if(found== false){
		std::cout<<"El elemento que estas buscando no existe en la tabla periodica\n\n";
		return -1;
	}
	return z;
}

int Busca_z(int buscar){
	int i,z;bool found = false;
	for(i=1;i<=118;i++){
		if(buscar == elementos[i].z){
			Color(BLACK, CYAN);std::cout<<"["<<elementos[i].simbolo<<"]";
			Color(BLACK,WHITE);std::cout<<": "<<elementos[i].nombre;
			printf(", Z="); Color(BLACK, BROWN); printf("%d",elementos[i].z); Color(BLACK, WHITE); printf(":  ");
			configuracion_electronica(elementos[i].z);
			found = true;
			z = elementos[i].z;
			break;
		}
	}
	if(found== false){
		std::cout<<"El elemento que estas buscando no existe en la tabla periodica\n\n";
		return -1;
	}
	return z;	
}

void inicializar_elementos(){
	int i=1;
	std::ifstream reader;
    reader.open("ElementosPorLinea.txt",  std::ios::in);
    if (reader.is_open()) {
        while (!reader.eof()) {
            reader >> elementos[i].z;//aux.z;
            reader >> elementos[i].nombre;
            reader >> elementos[i].simbolo;
            //printf("%d\n",i);
			i++;
        }
    } else {
        std::cout << "Error! El archivo no pudo ser abierto." << std::endl;
    }
    reader.close();
}

void Color(int Background, int Text){
HANDLE Console=GetStdHandle(STD_OUTPUT_HANDLE);
int New_Color=Text+(Background*16);
SetConsoleTextAttribute(Console,New_Color);
}









