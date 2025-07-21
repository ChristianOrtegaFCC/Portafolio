#include <iostream>

class claseArbol{
private:
    struct structNodo {
        int dato;
        struct structNodo *izq;
        struct structNodo  *der;
    };

public:
    typedef struct structNodo  *nodo;
    void insertar(int aux, nodo &);
    void preorden (nodo);
    void inorden (nodo);
    void postorden (nodo);
    bool buscar(nodo,int numero);
    void eliminar(int aux,nodo, nodo);
    void eliminarRaiz(int aux,nodo &);
    int Msg1();
    int Msg2();
    void menu();
};

void claseArbol::insertar(int aux,nodo &raiz){
    if(raiz == NULL){
        nodo nuevo = new (struct structNodo );
        nuevo->dato = aux;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        raiz = nuevo;
    }else{
        if(aux > raiz->dato){
            insertar(aux,raiz->der);
        }else if(aux < raiz->dato){
            insertar(aux,raiz->izq);
        }else{
            std::cout << "Error! \n No puede haber numeros repetidos , intentelo de nuevo" << std::endl;
        }
    }
}

void claseArbol::preorden(nodo raiz){
    if(raiz != NULL){
        std::cout<<raiz->dato<<" - ";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void claseArbol::inorden(nodo raiz){
    if(raiz != NULL){
        inorden(raiz->izq);
        std::cout<<raiz->dato<<" - ";
        inorden(raiz->der);
    }
}

void claseArbol::postorden(nodo raiz){
    if(raiz != NULL){
        postorden(raiz->izq);
        postorden(raiz->der);
        std::cout<<raiz->dato<<" - ";
    }
}

bool claseArbol::buscar(nodo raiz,int numero){
    if(raiz != NULL){
		if(raiz->dato == numero){
            return true;
        }else if(numero > raiz->dato){
            return buscar(raiz->der,numero);
        }else if(numero < raiz->dato){
            return buscar(raiz->izq,numero);
        }else{
            return false;
        }
    }
}

int claseArbol::Msg1(){
    int aux;
    std::cout << std::endl<<"===Arbol de Busqueda Binaria===" << std::endl;
    std::cout << "1.Insertar" << std::endl;;
    std::cout << "2.Buscar" << std::endl;;
    std::cout << "3.Eliminar" << std::endl;;
    std::cout << "4.Recorrer" << std::endl;;
    std::cout << "5.Salir" << std::endl;
    std::cout << "Respuesta: ";
    std::cin >> aux;
    return aux;
}

int claseArbol::Msg2(){
    int aux;
    std::cout << "=== Recorrido ===" << std::endl;
    std::cout << "1.Preorden" << std::endl;;
    std::cout << "2.Inorden" << std::endl;;
    std::cout << "3.Postorden" << std::endl;;
    std::cout << "4.Todos" << std::endl;;
    std::cout << "5.Salir" << std::endl;
    std::cout << "Respuesta: ";
    std::cin >> aux;
    return aux;
}

void claseArbol::eliminarRaiz(int aux,nodo &raiz){
if((raiz->der == NULL) && (raiz -> izq == NULL)){// sin hijos ==========================
	raiz = NULL;
	return;
}else{
	if((raiz->der != NULL) && (raiz -> izq != NULL)){ // dos hijos =====================
		nodo aguanta_tantito;
		nodo hallar_fin;
		aguanta_tantito = raiz->izq;
		hallar_fin = raiz->der;
		while(hallar_fin->izq != NULL) hallar_fin = hallar_fin->izq;
			hallar_fin->izq = aguanta_tantito;
		return;	
	}else{// un hijo ======================================================================
		if(raiz->izq == NULL) raiz = raiz->der; else raiz = raiz->izq;
		if(raiz->der == NULL) raiz = raiz->izq; else raiz = raiz->der;
		return;
	}
}	
return;
}

void claseArbol::eliminar(int aux,nodo raiz, nodo ant){
if(raiz != NULL){
        if(raiz->dato == aux){// encontramos al dato (nodo) que queremos eliminar
        	if(ant == NULL){ // en caso de que el nodo a borrar sea el primero...
        		eliminarRaiz(aux,raiz);
				return;
			}
        	if((raiz->der == NULL) && (raiz -> izq == NULL)){// sin hijos ==========================
				if(raiz->dato > ant->dato) ant->der = NULL; else ant->izq = NULL;
				return;
			}else{
				if((raiz->der != NULL) && (raiz -> izq != NULL)){ // dos hijos =====================
					nodo aguanta_tantito;
					nodo hallar_fin;
					if(ant->dato > raiz->dato){// proceso del lado izquierdo del ABB
						aguanta_tantito = raiz->izq;
						ant->izq = raiz->der;
						hallar_fin = ant->izq;
					}else{ // proceso del lado derecho del ABB
						aguanta_tantito = raiz->der;
						ant->der = raiz->der;
						hallar_fin = ant->der;
					}
					while(hallar_fin->izq != NULL) hallar_fin = hallar_fin->izq;
						hallar_fin->izq = aguanta_tantito;
					return;	
				}else{// un hijo ======================================================================
					if(ant->dato > raiz->dato){//lado izquierdo del ABB
						if(raiz->izq == NULL) ant->izq = raiz->der; else ant->izq = raiz->izq;
					}else{// lado derecho del ABB
						if(raiz->izq == NULL) ant->der = raiz->der; else ant->der = raiz->izq;
					}
					return;
				}
			}
		}
		ant = raiz;
		eliminar(aux, raiz->izq, ant);
        eliminar(aux, raiz->der, ant);
    }
return;
}

void claseArbol::menu(){
    nodo arbol = NULL;
    /*  //Datos muestrales
	insertar(25,arbol);
    insertar(10,arbol);
    insertar(45,arbol);
    insertar(3,arbol);
    insertar(12,arbol);
    insertar(50,arbol);
    insertar(7,arbol);
    insertar(46,arbol);
	 */

/*	 
//datos muestrales
//(este orden crea el ABB de modo que la raiz es 1 y los otros datos se almacenanan a la derecha como mayores)
	insertar(1,arbol);
	insertar(2,arbol);
	insertar(3,arbol);
	insertar(4,arbol);
	insertar(5,arbol);
	insertar(6,arbol);
	insertar(7,arbol);
	insertar(8,arbol);
	insertar(20,arbol);
	insertar(26,arbol);
	insertar(29,arbol);
	insertar(32,arbol);
	insertar(50,arbol);
	insertar(100,arbol);
	 */
	
//datos muestrales (los mismos datos de arriba pero en otro orden)
//(este orden crea el ABB de modo que la raiz es 100 y los otros datos se almacenanan a la izquierda como menores)
	insertar(100,arbol);
	insertar(50,arbol);
	insertar(20,arbol);
	insertar(6,arbol);
	insertar(29,arbol);
	insertar(4,arbol);
	insertar(7,arbol);
	insertar(26,arbol);
	insertar(32,arbol);
	insertar(3,arbol);
	insertar(5,arbol);
	insertar(8,arbol);
	insertar(22,arbol);
	insertar(27,arbol);
	insertar(1,arbol);
	insertar(2,arbol);
	
	
	int aux = 0, opc, opc2;
    do {
        opc = Msg1();
        switch (opc) {
            case 1:
                std::cout << "==Insertar==" << std::endl;;
                std::cout << "Ingrese un numero: ";
                std::cin >> aux;
                insertar(aux,arbol);
                break;
            case 2:
                std::cout << "==Buscar==" << std::endl;;
                std::cout << "Ingrese un numero: ";
                std::cin >> aux;
                if (buscar(arbol,aux)){
                    std::cout << "El numero: " << aux << " se ha encontrado!" << std::endl;;
                }else{
                    std::cout << "El numero: " << aux << " NO se ha encontrado!" << std::endl;;
                }
                break;
            case 3:
            	std::cout << "==eliminar==" << std::endl;;
                std::cout << "numero a eliminar: ";
                std::cin >> aux;
                eliminar(aux, arbol, NULL);
                break;
            case 4:
                do{
                    opc2 = Msg2();
                    switch(opc2){
                        case 1:
                            std::cout << "=== Preorden ===" << std::endl;
                            preorden(arbol);
                            std::cout << " " << std::endl;
                            break;
                        case 2:
                            std::cout << "=== Inorden ===" << std::endl;
                            inorden(arbol);
                            std::cout << " " << std::endl;
                            break;
                        case 3:
                            std::cout << "=== Postorden ===" << std::endl;
                            postorden(arbol);
                            std::cout << " " << std::endl;
                            break;
                        case 4:
                            std::cout << "=== Preorden ===" << std::endl;
                            preorden(arbol);
                            std::cout << " " << std::endl;
                            std::cout << "=== Inorden ===" << std::endl;
                            inorden(arbol);
                            std::cout << " " << std::endl;
                            std::cout << "=== Postorden ===" << std::endl;
                            postorden(arbol);
                            std::cout << " " << std::endl;
                            break;
                        case 5:
                            std::cout << "Saliendo..." << std::endl;
                            break;
                        default:
                            std::cout << "Error!" << std::endl;
                            break;
                    }
                }while(opc2 != 5);
                break;
            case 5:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Error!" << std::endl;
                break;
        }
    }while(opc != 5);
}

int main(){
    claseArbol ABB;
    ABB.menu();
    return 0;

}
