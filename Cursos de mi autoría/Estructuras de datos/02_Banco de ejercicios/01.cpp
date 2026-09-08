// 1. Realice la especificaci�n del TDA Conjunto
// con las operaciones Uni�n, Intersecci�n, Diferencia, 
// Pertenencia y Complemento.
#include <iostream>
using namespace std;
# define lim 10 // si cambias el limite aqu�, se cambiar� correctamente en todo el programa

class conjunto{
	public:
		string nombre;
		int elementos[lim];
		int aux[lim*2];
		int nf;	
		
	public:
		conjunto(string id);
		int append(int n);
		int eliminar(int d);
		int _union(int guest[],int lim_guest,string name_guest);
		int interseccion(int guest[],int lim_guest,string name_guest);
		int diferencia(int guest[],int lim_guest,string name_guest);
		int pertenencia(int guest[],int lim_guest,string name_guest);
		int complemento(int guest[],int lim_guest,string name_guest);
		void mostrar(int guest[],int lim_guest,string name_guest);
		int menu(int guest[],int lim_guest,string name_guest);
};

conjunto::conjunto(string id){
int i;
nombre = id;
for(i=0;i<lim;i++){
	elementos[i]=0;
}
for(i=0;i<lim*2;i++){
	aux[i]=0;
}
return;
}

int conjunto::append(int n){
int i;
bool band = true;
for(i=0;i<nf;i++)
	if(elementos[i] == n){
		cout<<"El elemento ya existe en el conjunto..."<<endl;
		band = false;
	}

if(band == true){
	elementos[nf]=n;
	nf++;
}
return 0;	
}

int conjunto::eliminar(int d){
int i,n=0;
bool find = false;
for(i=0;i<nf;i++){
	if(elementos[i] == d){
		find = true;
		n = elementos[i];
		elementos[i] = elementos[nf-1];
		elementos[nf-1]=0;
		nf--;
		cout<<"Elemento borrado"<<endl;
		break;
	}
}
if(find == false)
	cout<<"Elemento no encontrado"<<endl;
return n;	
}

int conjunto::_union(int guest[],int lim_guest,string name_guest){
int i,j,k = nf;
bool band = true;
for(i=0;i<nf;i++){
	aux[i]=elementos[i];
}
// calcula la union
for (j=0;j<lim_guest;j++){
	band = false;
	for (i=0;i<nf;i++){
		if(guest[j] == aux[i]){
			band = true;
		}
	}
	if (band == false){
		aux[k] = guest[j];
		k++;
	}
}
// muestra la union
cout<<nombre<<" U "<<name_guest;
mostrar(aux,k," ");
cout<<endl;
return 0;	
}

int conjunto::interseccion(int guest[],int lim_guest,string name_guest){
int i,j,k = 0;
bool band;
// calcula la interseccion
for (j=0;j<lim_guest;j++){
	band = false;
	for (i=0;i<nf;i++){
		if(guest[j] == elementos[i]){
			band = true;
		}
	}
	if (band == true){
		aux[k] = guest[j];
		k++;
	}
}
// muestra la interseccion
cout<<nombre<<" n "<<name_guest;
mostrar(aux,k," ");
cout<<endl;
return 0;	
}

int conjunto::diferencia(int guest[],int lim_guest,string name_guest){
int i,j,k = 0;
bool band;
// calcula la diferencia
for (i=0;i<nf;i++){
	band = false;
	for (j=0;j<lim_guest;j++){
		if(guest[i] == elementos[j]){
			band = true;
		}
	}
	if (band == false){
		aux[k] = elementos[i];
		k++;
	}
}
// muestra la diferencia
cout<<nombre<<" - "<<name_guest;
mostrar(aux,k," ");
cout<<endl;
return 0;	
}

int conjunto::pertenencia(int guest[],int lim_guest,string name_guest){
int i,j,k = 0,p;
bool band= true;
// calcula la pertenencia
for (i=0;i<nf;i++){
	if(band == false){
		break;
	}
	band = false;
	for (j=0;j<lim_guest;j++){
		if(elementos[i] == guest[j]){
			band = true;
		}
	}
}
if (band == false){// mostramos pertenencia
	p=0;
	cout<<nombre<<" !E "<<name_guest<<".";
}else{
	cout<<nombre<<" E "<<name_guest<<".";
	p=1;
}
cout<<endl;
return p;	
}

int conjunto::complemento(int guest[],int lim_guest,string name_guest){
int i,j,k=0;
bool band;
if (pertenencia(guest,lim_guest,name_guest) == 0){
	cout<<"Entonces NO podemos calcular "<<nombre<<"' de "<<name_guest<<"."<<endl<<endl;
}else{
	cout<<"Entonces podemos calcular "<<nombre<<"' de "<<name_guest<<":"<<endl;
	// calcula el complemento
	for (j=0;j<lim_guest;j++){
		band = false;
		for (i=0;i<nf;i++){
			if(guest[j] == elementos[i]){
				band = true;
			}
		}
		if (band == false){
			aux[k] = guest[j];
			k++;
		}
	}
	//muestra el complemento
	cout<<nombre<<"' de "<<name_guest;
	mostrar(aux,k,"Complemento ");
	cout<<endl;
}
return 0;	
}

void conjunto::mostrar(int guest[],int lim_guest,string name_guest){
int i;
cout<<name_guest<<" = { ";
for(i=0;i<lim_guest;i++){
	if (i== lim_guest-1)
		cout<<guest[i];
	else
		cout<<guest[i]<<", ";
}
cout<<" }"<<endl;
return;
}

int conjunto::menu(int guest[],int lim_guest,string name_guest){
int opc,dato;
char rep;
do{
	cout<<endl<<endl<<":::: OPERACIONES DE "<<nombre<<" :::::::"<<endl;
	cout<<"0. Append."<<endl;
	cout<<"1. Elimiar."<<endl;
	cout<<"2. "<<nombre<<" U "<<name_guest<<"."<<endl;
	cout<<"3. "<<nombre<<" n "<<name_guest<<"."<<endl;
	cout<<"4. "<<nombre<<" - "<<name_guest<<"."<<endl;
	cout<<"5. "<<nombre<<" E "<<name_guest<<"."<<endl;
	cout<<"6. "<<nombre<<"' de "<<name_guest<<"."<<endl;
	cout<<"7. mostrar conjuntos."<<endl;
	cout<<"8. salir del menu de "<<nombre<<"."<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 0:
			do{
				cout<<nombre<<".Append >>> ";
				cin>>dato;
				append(dato);
				cout<<"Presiona r para repetir"<<endl<<"cualquier otra cosa para volver"<<endl<<"   >>> ";
				cin>>rep;
			}while(rep=='r');
			break;
		case 1:
			do{
				cout<<nombre<<".Eliminar >>> ";
				cin>>dato;
				eliminar(dato);
				cout<<"Presiona r para eliminar algo de nuevo"<<endl<<"cualquier otra cosa para volver"<<endl<<"   >>> ";
				cin>>rep;
			}while(rep=='r');
			break;
		case 2:
			_union(guest,lim_guest,name_guest);
			break;
		case 3:
			interseccion(guest,lim_guest,name_guest);
			break;
		case 4:
			diferencia(guest,lim_guest,name_guest);
			break;
		case 5:
			pertenencia(guest,lim_guest,name_guest);
			break;
		case 6:
			complemento(guest,lim_guest,name_guest);
			break;
		case 7:
			mostrar(elementos,nf,nombre);
			mostrar(guest,lim_guest,name_guest);
			cout<<endl;
			break;
		case 8:
			cout<<"Adios"<<endl;
			break;
		default:
			cout<<"debes escoger entre 0 y 8"<<endl;	
	}
}while(opc != 8);	
return 0;
}

//    FIN DEL TDA, EL MAIN PUEDE SER IMPLEMENTADO AL GUSTO

int main(){
int opc;
conjunto *c1 = new conjunto("A");
conjunto *c2 = new conjunto("B");
conjunto *c3 = new conjunto("C");
c3->append(1);
c3->append(4);
c3->append(6);
c3->append(9);
c3->append(0);

c1->append(6);
c1->append(2);
c1->append(3);
c1->append(4);

c2->append(1);
c2->append(2);
c2->append(3);
c2->append(4);
c2->append(5);

do{
	cout<<"::::::: MENU PRINCIPAL ::::::::"<<endl;
	cout<<"1. Operaciones desde "<<c1->nombre<<"."<<endl;
	cout<<"2. Operaciones desde "<<c2->nombre<<"."<<endl;
	cout<<"3. salir del programa."<<endl;
	cout<<"   >>> ";
	cin>>opc;
	cout<<endl;
	switch(opc){
		case 1:
			c1->menu(c2->elementos,c2->nf,c2->nombre);
			break;
		case 2:
			c2->menu(c1->elementos,c1->nf,c1->nombre);
			break;
		case 3:
			cout<<"adios";
			break;
		default:
			cout<<"debes escoger entre 1 y 3"<<endl;
	}
}while(opc!=3);
return 0;
} 
