// Amador Ortega Christian Amauri - 201927821     (AmauriMapache jsjsjsj)
// SO PCA1
#include <iostream>
#include <string.h>
#define max 35
using namespace std;
bool bandrepeat= true;
string auxstring;
char s1[max],s2[max];
int auxint;
float auxfloat;

struct ventas{
			string vendedor;
			float total;
			int dia;
			int mes;
			int year;
			ventas *sig;	
		};
ventas *actual = new ventas();

class registro{
	public:
		ventas *L; 
	
	public:
		registro();
		bool found(string vo, float to, int dor,int mo,int yo,string vc, float tc, int dc,int mc,int yc);
		void registrar_venta(string v, float t, int d,int m,int y);
		void eliminar_venta(string v, float t, int d,int m,int y);
		void sort_porvendedor();
		void sort_portotal();
		void sort_porfecha();
		void sort_porvendedor_DES();
		void sort_portotal_DES();
		void sort_porfecha_DES();
		void visualizar_registros();
		void menu();
		void menu_sorts();
};

registro::registro(){
L = NULL;
return;	
}

bool registro::found(string vo, float to, int dor,int mo,int yo,string vc, float tc, int dc,int mc,int yc){
bool founded = true;
if(vo != vc) founded = false;  if(to != tc) founded = false; 
if(dor != dc) founded = false; if(mo != mc) founded = false; 
if(yo != yc) founded = false; 
return founded;
}

void registro::registrar_venta(string v, float t, int d,int m,int y){
ventas *nuevo_nodo = new ventas();
nuevo_nodo->vendedor = v;
nuevo_nodo->total = t;
nuevo_nodo->dia = d;
nuevo_nodo->mes = m;
nuevo_nodo->year = y;
ventas *aux1 = L;
ventas *aux2;

while(aux1 != NULL){
	aux2 = aux1;
	aux1 = aux1->sig;
}

if(L == aux1)L = nuevo_nodo;
else aux2->sig = nuevo_nodo;
nuevo_nodo->sig = aux1;

return;	
}

void registro::eliminar_venta(string v, float t, int d,int m,int y){
if(L != NULL){
	ventas *aux_borrar;
	ventas *anterior = NULL;
	aux_borrar = L;
		   
	while((aux_borrar != NULL) && (found(aux_borrar->vendedor,aux_borrar->total,aux_borrar->dia,aux_borrar->mes,aux_borrar->year,v,t,d,m,y ) == false)){
		anterior = aux_borrar;
		aux_borrar = aux_borrar->sig;
	}
	// el elemento no ha sido encontrado
	if(aux_borrar == NULL){
		cout<<"el elemento no ha sido encontrado"<<endl;
	}else { // el primer elemento es el que vamos a borrar
		if(anterior == NULL){
			L = L->sig;
			delete aux_borrar;
		}else{//el elemento esta en la lista pero no es el primero
			anterior->sig = aux_borrar->sig;
			delete aux_borrar;
		}
	}			
}
return;	
}

void registro::sort_porvendedor(){
cout<<"\n\nOrdenando por vendedor (Ascendentemente)... ";
actual = L;
while(bandrepeat == true){
	bandrepeat = false;
	actual = L;
	while(actual->sig != NULL){
			for(int j=0;j<max;j++)	s1[j] = '\0';
			for(int j=0;j<max;j++) s2[j]= '\0';
			for(int j=0;j<actual->vendedor.length();j++)	s1[j] = actual->vendedor[j];
			for(int j=0;j<actual->sig->vendedor.length();j++) s2[j]= actual->sig->vendedor[j];
			if( strcmp(s1,s2) > 0){// cambio...
				auxstring = actual->vendedor;// intercambiamos vendedores
				actual->vendedor = actual->sig->vendedor;
				actual->sig->vendedor = auxstring;
				  auxfloat = actual->total;// intercambiamos totales
				  actual->total = actual->sig->total;
				  actual->sig->total = auxfloat;
					auxint = actual->dia;// intercambiamos fecha (dia)
				    actual->dia = actual->sig->dia;
				    actual->sig->dia = auxint;
				      auxint = actual->mes;// intercambiamos fecha (mes)
				      actual->mes = actual->sig->mes;
				      actual->sig->mes = auxint;
				      	auxint = actual->year;// intercambiamos fecha (anio)
				    	actual->year = actual->sig->year;
				    	actual->sig->year = auxint;
				bandrepeat= true;
			}// fin if cambio
		actual = actual->sig;// siguiente nodo...		
	}
}
printf("\nLista ordenada:\n");
visualizar_registros();
printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n°°°°° Succesful sort! °°°°°\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
bandrepeat = true;
return;	
}

void registro::sort_portotal(){
cout<<"\n\nOrdenando por total (Ascendentemente)... ";
actual = L;
while(bandrepeat == true){
	bandrepeat = false;
	actual = L;
	while(actual->sig != NULL){
			if(actual->total > actual->sig->total){ // cambio...
				auxstring = actual->vendedor;// intercambiamos vendedores
				actual->vendedor = actual->sig->vendedor;
				actual->sig->vendedor = auxstring;
				  auxfloat = actual->total;// intercambiamos totales
				  actual->total = actual->sig->total;
				  actual->sig->total = auxfloat;
					auxint = actual->dia;// intercambiamos fecha (dia)
				    actual->dia = actual->sig->dia;
				    actual->sig->dia = auxint;
				      auxint = actual->mes;// intercambiamos fecha (mes)
				      actual->mes = actual->sig->mes;
				      actual->sig->mes = auxint;
				      	auxint = actual->year;// intercambiamos fecha (anio)
				    	actual->year = actual->sig->year;
				    	actual->sig->year = auxint;
				bandrepeat= true;
			}// fin if cambio
		actual = actual->sig;// siguiente nodo...		
	}
} 
printf("\nLista ordenada:\n");
visualizar_registros();
printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n°°°°° Succesful sort! °°°°°\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
bandrepeat = true;
return;	
}

void registro::sort_porfecha(){
cout<<"\n\nOrdenando por fecha (Ascendentemente)... ";
bool cambio = false;
actual = L;
while(bandrepeat == true){
	bandrepeat = false;
	actual = L;
	while(actual->sig != NULL){
			// verifica la fecha....
			if(actual->year > actual->sig->year){//verifica año
				cambio = true;//printf("fecha 1 mayor!!!    (por anio)");
			}else{
				if(actual->year == actual->sig->year){
					if(actual->mes > actual->sig->mes){//verifica mes
						cambio = true;//printf("fecha 1 mayor!!!   (por mes)");
					}else{
						if(actual->mes == actual->sig->year){
							if(actual->dia > actual->sig->dia){//verifica dia
								cambio = true;//printf("fecha 1 mayor!!!    (por dia)");		
							}else{
							//	printf("fecha 1 menor/igual");
							}//fin verifica dia
						}else{
							//printf("fecha 1 menor/igual");
						}
					}// fin verifica mes
				}else{
					//printf("fecha 1 menor/igual");
				}
			}// fin verifica año
			if(cambio == true){// cambio...
				auxstring = actual->vendedor;// intercambiamos vendedores
				actual->vendedor = actual->sig->vendedor;
				actual->sig->vendedor = auxstring;
				  auxfloat = actual->total;// intercambiamos totales
				  actual->total = actual->sig->total;
				  actual->sig->total = auxfloat;
					auxint = actual->dia;// intercambiamos fecha (dia)
				    actual->dia = actual->sig->dia;
				    actual->sig->dia = auxint;
				      auxint = actual->mes;// intercambiamos fecha (mes)
				      actual->mes = actual->sig->mes;
				      actual->sig->mes = auxint;
				      	auxint = actual->year;// intercambiamos fecha (anio)
				    	actual->year = actual->sig->year;
				    	actual->sig->year = auxint;
				bandrepeat= true;
			  }// fin if cambio
			  cambio = false;// reiniciamos band-cambio
		actual = actual->sig;// siguiente nodo...		
	}
} 
printf("\nLista ordenada:\n");
visualizar_registros();
printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n°°°°° Succesful sort! °°°°°\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
bandrepeat = true;
return;	
}

void registro::sort_porvendedor_DES(){
cout<<"\n\nOrdenando por vendedor (Descendentemente)... ";
actual = L;
while(bandrepeat == true){
	bandrepeat = false;
	actual = L;
	while(actual->sig != NULL){
			for(int j=0;j<max;j++)	s1[j] = '\0';
			for(int j=0;j<max;j++) s2[j]= '\0';
			for(int j=0;j<actual->vendedor.length();j++)	s1[j] = actual->vendedor[j];
			for(int j=0;j<actual->sig->vendedor.length();j++) s2[j]= actual->sig->vendedor[j];
			if( strcmp(s2,s1) > 0 ){// cambio...
				auxstring = actual->vendedor;// intercambiamos vendedores
				actual->vendedor = actual->sig->vendedor;
				actual->sig->vendedor = auxstring;
				  auxfloat = actual->total;// intercambiamos totales
				  actual->total = actual->sig->total;
				  actual->sig->total = auxfloat;
					auxint = actual->dia;// intercambiamos fecha (dia)
				    actual->dia = actual->sig->dia;
				    actual->sig->dia = auxint;
				      auxint = actual->mes;// intercambiamos fecha (mes)
				      actual->mes = actual->sig->mes;
				      actual->sig->mes = auxint;
				      	auxint = actual->year;// intercambiamos fecha (anio)
				    	actual->year = actual->sig->year;
				    	actual->sig->year = auxint;
				bandrepeat= true;
			}// fin if cambio
		actual = actual->sig;// siguiente nodo...		
	}
}
printf("\nLista ordenada:\n");
visualizar_registros();
printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n°°°°° Succesful sort! °°°°°\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
bandrepeat = true;
return;	
}

void registro::sort_portotal_DES(){
cout<<"\n\nOrdenando por total (Descendentemente)... ";
actual = L;
while(bandrepeat == true){
	bandrepeat = false;
	actual = L;
	while(actual->sig != NULL){
			if(actual->total < actual->sig->total){ // cambio...
				auxstring = actual->vendedor;// intercambiamos vendedores
				actual->vendedor = actual->sig->vendedor;
				actual->sig->vendedor = auxstring;
				  auxfloat = actual->total;// intercambiamos totales
				  actual->total = actual->sig->total;
				  actual->sig->total = auxfloat;
					auxint = actual->dia;// intercambiamos fecha (dia)
				    actual->dia = actual->sig->dia;
				    actual->sig->dia = auxint;
				      auxint = actual->mes;// intercambiamos fecha (mes)
				      actual->mes = actual->sig->mes;
				      actual->sig->mes = auxint;
				      	auxint = actual->year;// intercambiamos fecha (anio)
				    	actual->year = actual->sig->year;
				    	actual->sig->year = auxint;
				bandrepeat= true;
			}// fin if cambio
		actual = actual->sig;// siguiente nodo...		
	}
} 
printf("\nLista ordenada:\n");
visualizar_registros();
printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n°°°°° Succesful sort! °°°°°\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
bandrepeat = true;
return;	
}

void registro::sort_porfecha_DES(){
cout<<"\n\nOrdenando por fecha (Descendentemente)... ";
bool cambio = false;
actual = L;
while(bandrepeat == true){
	bandrepeat = false;
	actual = L;
	while(actual->sig != NULL){
			// verifica la fecha....
			if(actual->year < actual->sig->year){//verifica año
				cambio = true;//printf("fecha 1 menor!!!    (por año)");
			}else{
				if(actual->year == actual->sig->year){
					if(actual->mes < actual->sig->mes){//verifica mes
						cambio = true;//printf("fecha 1 menor!!!   (por mes)");
					}else{
						if(actual->mes == actual->sig->year){
							if(actual->dia < actual->sig->dia){//verifica dia
								cambio = true;//printf("fecha 1 menor!!!    (por dia)");		
							}else{
							//	printf("fecha 1 mayor/igual");
							}//fin verifica dia
						}else{
							//printf("fecha 1 mayor/igual");
						}
					}// fin verifica mes
				}else{
					//printf("fecha 1 mayor/igual");
				}
			}// fin verifica año
			if(cambio == true){// cambio...
				auxstring = actual->vendedor;// intercambiamos vendedores
				actual->vendedor = actual->sig->vendedor;
				actual->sig->vendedor = auxstring;
				  auxfloat = actual->total;// intercambiamos totales
				  actual->total = actual->sig->total;
				  actual->sig->total = auxfloat;
					auxint = actual->dia;// intercambiamos fecha (dia)
				    actual->dia = actual->sig->dia;
				    actual->sig->dia = auxint;
				      auxint = actual->mes;// intercambiamos fecha (mes)
				      actual->mes = actual->sig->mes;
				      actual->sig->mes = auxint;
				      	auxint = actual->year;// intercambiamos fecha (anio)
				    	actual->year = actual->sig->year;
				    	actual->sig->year = auxint;
				bandrepeat= true;
			  }// fin if cambio
			  cambio = false;// reiniciamos band-cambio
		actual = actual->sig;// siguiente nodo...		
	}
} 
printf("\nLista ordenada:\n");
visualizar_registros();
printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n°°°°° Succesful sort! °°°°°\n°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
bandrepeat = true;
return;	
}

void registro::visualizar_registros(){
actual = L;
while(actual != NULL){
	cout<<"\n+--------------------------------------+\n";
	cout<<" vendedor: "<<actual->vendedor<<"\n ";
	cout<<"   total: "<<actual->total<<"\n  ";
	cout<<actual->dia<<" / "<<actual->mes<<" / "<<actual->year<<"\n ";
	actual = actual->sig;
}cout<<endl<<endl;	
return;
}

void registro::menu(){
int opc;
string ve; float to; int di, me, ye;
do{
	cout<<endl<<":::: R E G I S T R O S ::::::::::"<<endl;
	cout<<"1. insertar venta. "<<endl;
	cout<<"2. eliminar venta. "<<endl;
	cout<<"3. ver registros. "<<endl;
	cout<<"4. ordenar registros. "<<endl;
	cout<<"5. salir."<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			// quizá aquí deba meter un except
			cout<<"Insertar venta..."<<endl;
			fflush(stdin);
			do{
			  cout<<"nombre del vendedor >> "; getline(cin,ve);fflush(stdin);
			  if(ve.length() > 30) cout<<"Procura que el nombre del vendedor no supere los 30 caracteres, esto es solo un prototipo\nintentalo de nuevo...\n";
			}while(ve.length() > 30);
			cout<<"total de la venta   >> "; cin>>to; fflush(stdin);
			do{
				cout<<"fecha de la venta:\ndia  >> "; cin>>di; fflush(stdin);
				if (di > 31) cout<<"No existe mes con mas de 31 dias, genio"<<endl ;
				if (di < 1) cout<<"No existe mes con menos de 1 dia, genio"<<endl ;
			}while(di > 31 || di < 1);
			do{
				cout<<"mes  >> "; cin>>me; fflush(stdin);
				if (me > 12) cout<<"No hay mas de 12 meses, genio"<<endl ;
				if (me < 1) cout<<"No hay menos de 1 mes, genio"<<endl ;
			}while(me > 12 || me < 1);
			cout<<"anio >> "; cin>>ye; fflush(stdin);
			registrar_venta(ve,to,di,me,ye);
			break;
		case 2:
			cout<<"Eliminar venta..."<<endl;
			cout<<"(Porfa dame >>TODOS<< los datos EXACTOS XD)"<<endl;
			fflush(stdin);
			cout<<"nombre del vendedor >> "; getline(cin,ve); fflush(stdin);
			cout<<"total de la venta   >> "; cin>>to; fflush(stdin);
			cout<<"fecha de la venta:\ndia  >> "; cin>>di; fflush(stdin);
			cout<<"mes  >> "; cin>>me; fflush(stdin);
			cout<<"anio >> "; cin>>ye; fflush(stdin);
			eliminar_venta(ve,to,di,me,ye);
			break;
		case 3:
			visualizar_registros();
			break;
		case 4:
			menu_sorts();
			break;
		case 5:
			cout<<"adios\n\n";
			break;
		default:
			cout<<endl<<"debes escoger entre 1 y 5"<<endl;	
	}
}while(opc != 5);	
return;
}

void registro::menu_sorts(){
int opc,opc2,dato;
do{
	do{
		cout<<endl<<":::: O R D E N A R :::::::::::::"<<endl;
		cout<<"1. Por fecha. "<<endl;
		cout<<"2. Por total. "<<endl;
		cout<<"3. Por vendedores. "<<endl;
		cout<<"4. Regresar."<<endl;
		cout<<"   >>> ";
		cin>>opc;
		if (opc < 1 || opc > 4 )cout<<"debes escoger entre 1 y 4\n";
		if (opc == 4) return;
	}while(opc < 1 || opc > 4 );	
	do{
		cout<<"\n::: Ascendente o Descendente?::::\n";
		cout<<"1. Ascendente. "<<endl;
		cout<<"2. descendente. "<<endl;
		cout<<"  >>> ";
		cin>>opc2;
		if(opc2 < 1 || opc2 > 2) cout<<endl<<"Para esto debes escoger entre 1 y 2"<<endl;
	}while(opc2 < 1 || opc2 > 2);
	switch(opc){
		case 1:
			if (opc2 == 1) sort_porfecha();
			else sort_porfecha_DES();
			break;
		case 2:
			if (opc2 == 1) sort_portotal();
			else sort_portotal_DES();
			break;
		case 3:
			if (opc2 == 1) sort_porvendedor();
			else sort_porvendedor_DES();
			break;
		default: printf("\n\n°°°° You werent supposed to  °°°°\n°°°°   be able to get here   °°°°\n\n");
	}
}while(opc != 4);	
return;	
}

int main(){
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
printf("°°°°°°°°     SO PCA1     °°°°°°°°°\n");
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
registro* r1 = new registro;
//    Datos muestrales
r1->registrar_venta("Butters",350.75,1 , 1,2022);   r1->registrar_venta("Kyle"   ,255.0 ,31, 7,1979);
r1->registrar_venta("Cartman",19.95 ,30, 7,2005);   r1->registrar_venta("Kenny"  ,5.0   ,10, 8,2001);
r1->registrar_venta("Stan"   ,24.33 ,2 , 2,2001);   r1->registrar_venta("Timmy"  ,99.99 ,12, 4,2021);
r1->registrar_venta("Jimmy"  ,95.19 ,29, 3,1998);   r1->registrar_venta("Mapache",222.22,30, 7,2001);
r1->registrar_venta("Anahi"  ,66.66 ,28, 1,2001);   r1->registrar_venta("Zowl"   ,3.1416,24, 7,1990);
r1->registrar_venta("El sat" ,66.66 ,28, 1,2001);   r1->registrar_venta("Amlo"   ,0.0001,13,11,1953);   
//*/

r1->menu();

return 0;
}//:^)
