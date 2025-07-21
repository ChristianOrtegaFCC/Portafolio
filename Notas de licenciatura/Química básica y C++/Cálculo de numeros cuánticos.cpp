// c�lculo de numeros cuanticos V2
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

void inicializar_elementos();
enum Colors { BLACK = 0, BLUE = 1, GREEN = 2, CYAN = 3, RED = 4, MAGENTA = 5, BROWN = 6, LGREY = 7, DGREY = 8, LBLUE = 9, LGREEN = 10, LCYAN = 11, LRED = 12, LMAGENTA = 13, YELLOW = 14, WHITE = 15};
std::string configuracion_electronica(int z);
int Busca_elemento(std::string buscar);
int Busca_simbolo(std::string buscar);
void Color(int Background, int Text);
std::string error_caso(int code);
void numerosCuanticos();
int Busca_z(int buscar);

struct elemento{
	std::string nombre;
	std::string simbolo;
	int z; // numero atomico
	float masa_atomica;
};

class lista{
	public:
		struct nodo{
			short n;
			short l;
			short m;
			float s;
			nodo *sig;	
		};
		nodo *L;
	
	public:
lista(){
	L = NULL;	
}

void insertarInicio(int n,int l, int m, float s){
nodo *nuevo_nodo = new nodo();
nuevo_nodo->n = n;
nuevo_nodo->l = l;
nuevo_nodo->m = m;
nuevo_nodo->s = s;
nuevo_nodo->sig = L;
L = nuevo_nodo;
return ;
}

void insertarFinal(int n,int l,int m, float s){
if(L == NULL){
	insertarInicio(n,l,m,s);	
}else{
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->n = n;
	nuevo_nodo->l = l;
	nuevo_nodo->m = m;
	nuevo_nodo->s = s;
	nodo *aux1 = L;
	nodo *aux2;
	while(aux1 != NULL){
		aux2 = aux1;
		aux1 = aux1->sig;
	}
	aux2->sig = nuevo_nodo;	
	nuevo_nodo->sig = aux1;
}
return ;
}

void borrarTodo(){
	L=NULL;
	return;
}

void mostrar(int lim){
int i = 1;
if(L != NULL){
	nodo *auxrec;
	auxrec = L;	
	while(auxrec != NULL && i <= lim){
		printf("e%c[%d]:\t",494,i); if(i<100) printf("\t");
		printf("n: %d\t",auxrec->n);
		printf("l: %d\t",auxrec->l);
		printf("m: %d\t",auxrec->m);
		if (auxrec->s>0) printf("s:  %c (%c)\n",427,280); else printf("s: -%c (%c)\n",427,281);  // (427 = 1/2) (280 = arriba) (281 = abajo)
		//if (s>0) printf("s:  %c\n",280); else printf("s:  %c\n",281);  // (427 = 1/2) (280 = arriba) (281 = abajo)
		//if (s>0) printf("s:  %c\n",427); else printf("s:  -%c\n",427);  // (427 = 1/2) (280 = arriba) (281 = abajo)
		auxrec = auxrec->sig;
		i++;
	}
}
return ;
}
};

int emes_carita_triste[119] = {-900,0,0,0,0,-1,0,1,-1,0,1,0,0,-1,0,1,-1,0,1,0,0,-2,-1,0,1,2,-2,-1,0,1,2,-1,0,1,-1,0,1,0,0,-2,-1,0,1,2,-2,-1,0,1,2,-1,0,1,-1,0,1,0,0,-3,-2,-1,0,1,2,3,-3,-2,-1,0,1,2,3,-2,-1,0,1,2,-2,-1,0,1,2,-1,0,1,-1,0,1,0,0,-3,-2,-1,0,1,2,3,-3,-2,-1,0,1,2,3,-2,-1,0,1,2,-2,-1,0,1,2,-1,0,1,-1,0,1,};
elemento elementos[119];// 118 elementos
lista* L1 = new lista;

int main(){
	inicializar_elementos();
	std::string entrada;
	int i,z, it;
	
	//for(i=1;i<117;i++) std::cout<<"["<<i<<"]\t"<<"Z="<<elementos[i].z<<"\t"<<elementos[i].simbolo<<"\t"<<elementos[i].nombre<<std::endl;
	//std::cout<<"Z="<<elementos[45].z<<"\t"<<elementos[45].simbolo<<"\t"<<elementos[45].nombre<<std::endl;
	//while(true){
	//std::cout<<"dame la entrada (numero atomico, simbolo o nombre): ";
	//std::cin>>entrada;
	
	for(it =1;it<=118;it++){
	entrada = elementos[it].simbolo;
	std::cout<<"Entrada: "<<entrada<<" ���������������������������������������������������������������������������������������������� "<<std::endl;
	
	if(entrada.length()<=3){
		// N�mero at�mico o s�mbolos
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
	short i, counter=0; char lastlet, lastnum;	bool jmp = false, negative = false; 
	short n=1,l=0; float s=0.5;
	
	if (z <= 0 || z > 118){ error_caso(5); return ".l."; }
	
	L1->insertarFinal(n,l,emes_carita_triste[1],s);
	for(i=1;i<=z+1;i++){		
		if(i == 1 || i == 3|| i == 7|| i == 11|| i == 15|| i == 19|| i == 25 || i== 33 || i== 37 || i== 43 || i== 51 || i== 55 || i== 63 || i== 75 || i== 83 || i== 87 || i== 95 || i== 107 || i== 115 ) negative = true;
		// Orbital S
		if (i == 2 || i == 4 || i == 12 || i ==  20 || i ==  38 || i == 56 || i ==  88 ){
			negative = false;
			switch(i){
				case 2:		n=2;	l=0;break;
				case 4:		n=2; l=1;break;
				case 12:	n=3; l=1;break;
				case 20:	n=3; l=2;break;
				case 38:	n=4; l=2;break;
				case 56:	n=4; l=3;break;
				case 88:	n=5; l=3;break;
			}
		}
		
		// Orbital P
		if (i == 10 || i == 18 || i == 36 || i ==  54 || i ==  86 || i == 118){
			l=0;negative = false;
			switch(i){
				case 10:	n=3;	break;
				case 18:	n=4;	break;
				case 36:	n=5;	break;
				case 54:	n=6;	break;
				case 86:	n=7;	break;
				case 118:	n=8;	break;// You weren't supposed to get here
			}
		}
		
		// Orbital d
		if (i == 30 || i == 48 || i == 80 || i ==  112 ){
			l=1;negative = false;
			switch(i){
				case 30:	n=4;	break;
				case 48:	n=5;	break;
				case 80:	n=6;	break;
				case 112:	n=7;	break;
			}
		}
		
		// Orbital F
		if (i == 70 || i == 102 ){
			l=2; negative = false;
			switch(i){
				case 70: n=5;	break;
				case 102:n=6;	break;
			}
		}
		if(negative == true) s =-0.5; else s=0.5;
		L1->insertarFinal(n,l,emes_carita_triste[i+1],s);
	}
	
	
	printf("\n\nnumeros cuanticos de sus electrones:\n");
	L1->mostrar(z);
	L1->borrarTodo();
	printf("\n\n");
	
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
	return "Mira, no s� lo que fall� pero algo hiciste mal";
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
	elemento aux;
	std::ifstream reader;
    reader.open("ElementosPorLinea.txt",  std::ios::in);
    if (reader.is_open()) {
        while (!reader.eof()) {
            reader >> elementos[i].z;//aux.z;
            reader >> elementos[i].nombre;
            reader >> elementos[i].simbolo;
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
