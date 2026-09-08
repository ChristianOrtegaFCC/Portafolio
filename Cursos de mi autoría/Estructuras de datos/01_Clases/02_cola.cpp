#include <iostream>
# define lim 10
using namespace std;

class cola{
	public:
		int nf;
		int elementos[lim];
	
	public:
		cola();
		void encolar(int e);
		int desencolar();
		int top_sig();
		int top_ultimo_formado();
		bool is_empty();
		bool is_full();
		void MostrarCola();
		void menu();
};

cola::cola(){
int i;
nf = 0;
for(i=0;i<lim;i++){
	elementos[i] = 0;
}
cout<<"Cola de limite "<<lim<<" creada con exito."<<endl;
return;	
};

void cola::encolar(int e){
if( is_full() == false){
	elementos[nf] = e;
	nf++;
}
return;
};

int cola::desencolar(){
int d,i;
if( is_empty()== false){
	d = elementos[0];
	for(i=0;i<nf;i++){
		elementos[i] = elementos[i+1];
	}
	nf = nf-1;
	cout<<"Des-encolando: cola[0] = "<<d<<endl;
}else{
	return 0;
}
return d;
};

int cola::top_sig(){
if( is_empty() == false){
	cout<<"Siguiente en salir: cola[0] = "<<elementos[0]<<endl;
	return elementos[0];
}
return 0;
};

int cola::top_ultimo_formado(){
if(is_empty() == false){
	cout<<"Ultimpo elemento en integrarse: cola["<<nf-1<<"] = "<<elementos[nf-1]<<endl;
	return elementos[nf-1];	
}
return 0;	
};

bool cola::is_empty(){
if (nf == 0){
	cout<<"Cola vacia !!!"<<endl;
	return true;
}
return false;	
};

bool cola::is_full(){
if (nf == lim){
	cout<<"Cola llena !!!"<<endl;
	return true;
}
return false;	
};

void cola::MostrarCola(){
int i;
if( is_empty() == false){
	cout<<"Cola: "<<endl;
	for(i=0;i<nf;i++){
		cout<<"C["<<i<<"]: "<<elementos[i]<<endl;
	}
	cout<<endl;
}
return;
};

void cola::menu(){
int opc,dato;
do{
	cout<<"::::: C O L A S ::::::::::::: LIM ["<<lim<<"]"<<endl;
	cout<<"1.Encolar."<<endl;
	cout<<"2.Des-encolar."<<endl;
	cout<<"3.Proximo en salir?"<<endl;
	cout<<"4.Ultimo en entrar?"<<endl;
	cout<<"5.Cola vacia?"<<endl;
	cout<<"6.Cola llena?"<<endl;
	cout<<"7.Mostrar cola."<<endl;
	cout<<"8.Salir."<<endl;
	cout<<"  >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			if( is_full() == false){
				cout<<"Elemento a encolar: ";
				cin>>dato;
				encolar(dato);
			}
			break;
		case 2:
			desencolar();
			break;
		case 3:
			top_sig();
			break;
		case 4:
			top_ultimo_formado();
			break;
		case 5:
			if( is_empty() == false)
				cout<<"La cola no esta vacia."<<endl;
			break;
		case 6:
			if( is_full() == false)
				cout<<"La cola no esta llena."<<endl;
			break;
		case 7:
			MostrarCola();
			break;
		case 8:
			cout<<"Adios."<<endl;
			break;
		default:
			cout<<"debes escoger entre 1 y 8."<<endl;
	}	
}while(opc != 8);	
return;
};

int main(){
cola* c1 = new cola;
c1->menu();
return 0;
};

