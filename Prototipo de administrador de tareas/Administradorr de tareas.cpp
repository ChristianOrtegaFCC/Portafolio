// PROYECTO 1 "Planificador de procesos"

#include <iostream>
#include <fstream>


//Creamos la clase Nodo de tipo Struct que almacena un dato de tipo int y el nodo del siguiente struct
class claseNodo {
private:
    struct nodo {
        int pid;
        int Tllegada;
        int Texe;
        int prioridad;
        int Tespera;
        bool fin;
        int Tfin;
        nodo *sig;
    };

    //Métodos Públicos de la claseNodo
public:

    nodo *inicializarNodo(); //Método que crea el nodo y lo retorna, el dato que retorna es de tipo claseNodo

    void insertarListaInicio(nodo *&); //Método que inserta datos al inicio recibiendo como parámetros al la dir de nodo porque lo recibe como referencia y el dato int a guardar

    void insertarListaFinal(nodo *&);//Método que inserta datos al final recibiendo como parámetros al la dir de nodo porque lo recibe como referencia y el dato int a guardar

    void autoListaInicio(nodo *&, int, int, int, int, int, bool,int); //Método que inserta datos al inicio recibiendo como parámetros al la dir de nodo porque lo recibe como referencia y el dato int a guardar

    void autoListaFinal(nodo *&, int, int, int, int, int, bool,int);//Método que inserta datos al final recibiendo como parámetros al la dir de nodo porque lo recibe como referencia y el dato int a guardar

    void mostrarLista(nodo *); //Método que muestra la lista recibiendo el nodo por referencia

    void ordenarLista(nodo *&, int);

    //MONOTAREA-MONOPROCESO-MULTIPROCESO
    void algoritmo1(nodo *&, nodo *&, nodo *&, int);

    //MULTITAREA-MONOPROCESO-MULTIPROCESO
    void algoritmo2(nodo *&, nodo *&, nodo *&, int);

    //Funcion DE PRUEBA - SIN USAR
    //void algoritmoRecursivo(nodo *&, nodo *&, nodo *&, int [], int[],int);

    void eliminar(nodo *&, int); //Método que elimina al inicio recibiendo la dir del nodo porque lo recibe como referencia

    //Funcion que actualiza los nuevos valores de Tfin y el Tespera de los procesos cuando se ejecutan
    void actualizarProceso(nodo *&, nodo *&, int, int);

    //Hace lo mismo que el de arriba pero para un arreglo bidimensional
    void actualizarProcesoMulti(nodo *&, int, int);

    //Funcion que encola de nuevo procesos si su Texe es mayor a 1
    void repetirCola(nodo *&, nodo *&, int, int);

    //Funcion que en dado caso que se ejecute multitarea actualizarCola lo que hace es que cuando la primera cola finalice , esta misma se copie a la cola para que se ejecute otra vez
    void actualizarCola(nodo *&, nodo *&, int);

    //Checamos la cantidad de procesos enlistados
    int checarLista(nodo *);

    //Funcion que verifica cuantas veces se han ejecutado los procesos basandose en su Texe
    int checarRepeticiones(int [], int);

    //Funcion que suma todos los tiempos de los procesos que se vayan ejecutando
    int sumaEspera(nodo *);

    //Funcion que hace una busqueda para hallar el tiempo de ejecucion del pid que mandemos
    int numTexeBusqueda(nodo *, int);

    //Funcion que busca el pid de la siguiente manera T.exe(ligero), Prioridad(Alta), Pid(ASC/DESC) el ultimo int que pide es si es pid asc o desc
    int procesoBusqueda1(nodo *, int, int);

    //Funcion que busca el pid de la siguiente manera  Prioridad(Alta), T.exe(ligero), Pid(ASC/DESC) el ultimo int que pide es si es pid asc o desc
    int procesoBusqueda2(nodo *, int, int);

    //Funcion que ingresa los procesos que se ejecutan en una matriz y devuelve el tiempo en el que terminó
    int ingresarMatriz2(int [], int);

    void ingresarMatriz3(int [], int);

    //Funcion que ingresa los procesos que se ejecutan en una matriz y devuelve el tiempo en el que terminó
    int ingresarMatriz(int [], int, int);

    //Funcion que ingresa los procesos que se ejecutan en una matriz y devuelve el tiempo en el que terminó
    int ingresarMatrizMulti(int [][2], int, int);

    //Funcion que ingresa los procesos que se ejecutan en una matriz y devuelve el tiempo en el que terminó
    int ingresarMatrizMulti2(int [][2], int);

    //Métodos que muestran Strings
    int menu4();

    int menu3();

    int menu2();

    void menu();

    void Espacio();

    void Mensaje1();

    bool listaVacia(nodo *); //Método que indica si la lista está vacía recibiendo al nodo por valor

};

//Método de tipo claseNodo que inicializa un nodo y retorna a Lista
claseNodo::nodo *claseNodo::inicializarNodo() {
    nodo *lista = NULL;
    return lista;
}

//Método que inserta al inicio que recibe como paso de parámetros a lista como referencia y al dato n para almacenarlo
void claseNodo::insertarListaInicio(nodo *&lista) {
    //Creamos un nodo auxiliar llamado nuevo nodo para recorrer lista
    nodo *nuevo_nodo = new nodo();

    //Llenamos los campos
    std::cout << "Inserte el pid:" << std::endl;
    std::cin >> nuevo_nodo->pid;
    std::cout << "Inserte el Tiempo de llegada:" << std::endl;
    std::cin >> nuevo_nodo->Tllegada;
    std::cout << "Inserte el Tiempo de ejecucion:" << std::endl;
    std::cin >> nuevo_nodo->Texe;
    std::cout << "Inserte la prioridad:" << std::endl;
    std::cin >> nuevo_nodo->prioridad;
    nuevo_nodo->fin = false;
    nuevo_nodo->Tfin = 0;
    nuevo_nodo->Tespera = 0;
    //Asignamos que aux1 sea igual a la dir de lista
    nodo *aux1 = lista;

    if (lista == NULL) {
        //decimos que donde apuntaba lista ahora apunta el nuevo nodo
        nuevo_nodo->sig = aux1;

    } else {
        nuevo_nodo->sig = aux1;

    }
    //Lista tiene la dir de nuevo_nodo para conectarlo con el nuevo elemento
    lista = nuevo_nodo;
    std::cout << "\n" << std::endl;
}

//Método que inserta al final que recibe a lista como referencia y un int n que es el dato a almacenar
void claseNodo::insertarListaFinal(nodo *&lista) { // <<<< NUEVA
    //Creamos un nodo auxiliar llamado nuevo nodo para recorrer lista
    nodo *nuevo_nodo = new nodo();

    //Llenamos los campos
    std::cout << "Inserte el pid:" << std::endl;
    std::cin >> nuevo_nodo->pid;
    std::cout << "Inserte el Tiempo de llegada:" << std::endl;
    std::cin >> nuevo_nodo->Tllegada;
    std::cout << "Inserte el Tiempo de ejecucion:" << std::endl;
    std::cin >> nuevo_nodo->Texe;
    std::cout << "Inserte la prioridad:" << std::endl;
    std::cin >> nuevo_nodo->prioridad;
    nuevo_nodo->fin = false;
    nuevo_nodo->Tfin = 0;
    nuevo_nodo->Tespera = 0;
    //Creamos el nodo aux1 y le asignamos la dir de lista
    nodo *aux1 = lista;
    //Creamos el nodo aux2
    nodo *aux2;

    //Buscamos con este while el último nodo que en su campo sig sea nulo
    while (aux1 != NULL) {
        aux2 = aux1;
        aux1 = aux1->sig;
    }

    aux2->sig = nuevo_nodo;

    std::cout << "\n" << std::endl;
}

//Métodos de String que imprimen mensajes
void claseNodo::Espacio() {
    std::cout << "================================" << std::endl;
}

void claseNodo::Mensaje1() {
    Espacio();
    std::cout << "Sistema a Planificar\n" << std::endl;
}

//Método que retorna un int dependiendo que se seleccionó en él
int claseNodo::menu2() {
    int opc;
    Mensaje1();
    Espacio();
    std::cout << "Planificador" << std::endl;
    std::cout << "1. MonoTarea" << std::endl;
    std::cout << "2. MultiTarea" << std::endl;
    std::cout << "3. Ver tabla" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "Opcion: " << std::endl;
    std::cin >> opc;
    return opc;
}

//Método que retorna un int dependiendo que se seleccionó en él
int claseNodo::menu3() {
    int opc;
    Espacio();
    std::cout << "Numero de canales" << std::endl;
    std::cout << "1. MonoProceso" << std::endl;
    std::cout << "2. Multiproceso" << std::endl;
    std::cout << "Opcion: " << std::endl;
    std::cin >> opc;
    Espacio();
    return opc;
}

//Método que retorna un int dependiendo que se seleccionó en él
int claseNodo::menu4() {
    int opc;
    Espacio();
    std::cout << "Algoritmo" << std::endl;
    std::cout << "1. T.Exe(Ligero) - Prioridad(Alta) - Pid(ASC)" << std::endl;
    std::cout << "2. T.Exe(Ligero) - Prioridad(Alta) - Pid(DESC)" << std::endl;
    std::cout << "3. Prioridad(Alta) - T.Exe(Ligero) - Pid(ASC)" << std::endl;
    std::cout << "4. Prioridad(Alta) - T.Exe(Ligero) - Pid(DESC)" << std::endl;
    do {
        std::cout << "Opcion: " << std::endl;
        std::cin >> opc;
    } while (opc < 1 || opc > 4);

    Espacio();
    return opc;
}

//Método menu que depende de que retorne menu2
void claseNodo::menu() {
    //Asignamos al nodo pp lo que retorne el método que crea nodos
    nodo *pp = inicializarNodo();
    nodo *cola = inicializarNodo();
    nodo *colaAux = inicializarNodo();
    int pid1, llegada2, exe3, prioridad4;

    //Leer archivos
    std::ifstream reader;
    reader.open("texto.txt", std::ios::out | std::ios::in);
    if (reader.is_open()) {
        while (!reader.eof()) {
            reader >> pid1;
            reader >> llegada2;
            reader >> exe3;
            reader >> prioridad4;

            if (pp == NULL) {
                autoListaInicio(pp, pid1, llegada2, exe3, prioridad4, 0, false, 0);
            } else {
                autoListaFinal(pp, pid1, llegada2, exe3, prioridad4, 0, false, 0);
            }


        }
    } else {
        std::cout << "Error! El archivo no pudo ser abierto." << std::endl;
    }
    reader.close();

    int opc, opc2;

    do {
        //Dependiento de que se seleccione en el menu2 será el metodo que se llame para ejecutar sea MONOTAREA O MULTITAREA
        opc = menu2();
        //totalDatos = numTotalLista(pp);
        switch (opc) {

            //MONOTAREA
            case 1:
                opc2 = menu3();
                algoritmo1(pp, cola, colaAux, opc2);
                opc = 4;
                break;
                //MULTITAREA
            case 2:
                opc2 = menu3();
                algoritmo2(pp, cola, colaAux, opc2);
                opc = 4;
                break;
                //Muestra los Procesos
            case 3:
                mostrarLista(pp);
                break;
            case 4:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida!" << std::endl;
                break;
        }
    } while (opc != 4);
}

//Método que recibe por valor a lista
void claseNodo::mostrarLista(nodo *lista) {
    //Creamos el nodo auxiliar p y le asignamos la dir de lista
    nodo *p;
    p = lista;

    //Lo recorremos a lista con p y la imprimimos
    std::cout << "Lista de procesos:\n" << std::endl;
    if ((listaVacia(lista) != true)) {
        while (p != NULL) {
            std::cout << "PID: " << p->pid << std::endl;
            std::cout << "T.Llegada: " << p->Tllegada << std::endl;
            std::cout << "T.Exe: " << p->Texe << std::endl;
            std::cout << "Prioridad: " << p->prioridad << std::endl;
            if (p->fin == true) {
                std::cout << "Fin: SI" << std::endl;
            } else {
                std::cout << "Fin: NO" << std::endl;
            }
            std::cout << "T.Fin: " << p->Tfin << std::endl;
            std::cout << "T.Espera: " << p->Tespera << "\n" << std::endl;
            p = p->sig;
        }
    }
}


//Método que recibe por valor a lista y nos regresa cuantos datos están en ella
int claseNodo::checarLista(nodo *lista) {
    //Creamos el nodo auxiliar p y le asignamos la dir de lista
    int cant = 0;
    nodo *p;
    p = lista;

    //Lo recorremos a lista con p y los contamos

    if ((listaVacia(lista) != true)) {
        while (p != NULL) {
            if (lista->fin == true) {
                cant = cant + 1; //vamos contando los datos
            }
            p = p->sig;
        }
    }
    //Regresa la cantidad de datos en la lista
    return cant;
}


//Método que checa cuantas veces se ha ejecutado de su Texe un pid
int claseNodo::checarRepeticiones(int A[], int pidI) {
    //Creamos el nodo auxiliar p y le asignamos la dir de lista
    int cant = 0, i;


    //Lo recorremos a lista con p y los contamos

    for (i = 0; i < 50; i++) {
        if (A[ i ] == pidI) {
            cant = cant + 1;
        }
    }
    return cant; //Regresamos las veces que se ha ejecutado su Texe y que sea igual al que sea, en casos que sea mayor a 1
}

//Metodo que suma todos los Tespera para hacer el promedio
int claseNodo::sumaEspera(nodo *lista) {
    //Creamos el nodo auxiliar p y le asignamos la dir de lista
    int cant = 0;
    nodo *p;
    p = lista;

    //Lo recorremos a lista con p y los contamos

    if ((listaVacia(lista) != true)) {
        while (p != NULL) {
            cant = cant + p->Tespera; //Sumamos los tiempos de espera de todos los de la lista
            p = p->sig;
        }
    }
    return cant;
}

//Método que recibe por valor a lista y nos regresa cuantos datos ya ejecutamos
int claseNodo::numTexeBusqueda(nodo *lista, int pid) {
    //Creamos el nodo auxiliar p y le asignamos la dir de lista
    int cant = 0;
    nodo *p;
    p = lista;

    //Lo recorremos a lista con p y los contamos

    if ((listaVacia(lista) != true)) {
        while (p != NULL) {
            if (p->pid == pid) {
                cant = p->Texe;
            }
            p = p->sig;
        }
    }
    return cant;
}

//Método que recibe por valor a lista y nos regresa el pid de la siguiente manera T.exe(ligero), Prioridad(Alta), Pid(ASC/DESC) el ultimo int que pide es si es pid asc o desc
int claseNodo::procesoBusqueda1(nodo *lista, int compara, int opc) {
    //Creamos el nodo auxiliar p y le asignamos la dir de lista
    int acumulado = 0, acumulado2 = 0, compara2, auxPid, auxA[10], auxB[10], i, box = 0;
    nodo *p;
    p = lista;
    bool band = true, pausa = false;

    for (i = 0; i < 10; i++) {
        auxA[ i ] = -1;
        auxB[ i ] = -1;
    }
    //Lo recorremos a lista con p y los contamos
    i = 0;
    //Se verifica si son más procesos que cumplen con que sean Texe ligeros
    if ((listaVacia(lista) != true)) {
        while (p != NULL) {
            if (p->Texe == compara) {
                acumulado = acumulado + 1;
                auxPid = p->pid;
                auxA[ i ] = p->pid;
                i = i + 1;
            }
            p = p->sig;

        }
    }

    //Si solo es uno , se envia , si no ahora se busca por prioridad alta
    if (acumulado == 1) {
        return auxPid;
    } else {
        p = lista;
        ordenarLista(p, 2);
        compara2 = p->prioridad;
        i = 0;
        for (int j = 0; j < acumulado; j++) {
            p = lista;
            if ((listaVacia(lista) != true)) {
                while (p != NULL) {
                    if (p->pid == auxA[ j ] && p->prioridad == compara2) {
                        acumulado2 = acumulado2 + 1;
                        auxPid = p->pid;
                        auxB[ i ] = p->pid;
                        i = i + 1;
                    }
                    p = p->sig;

                }
            }
        }

        //Si es un proceso se retorna , si no se retorna el PID dependiendo de que int se recibio en la funcion si es 3 entonces es ASC Y si es 4 Desc
        if (acumulado2 == 1) {
            return auxPid;
        } else {
            p = lista;
            if (opc == 1) {
                ordenarLista(p, 3);
                //ASC
                for (i = 0; i < 9; i++) {

                    if (auxB[ i ] > auxB[ i + 1 ]) {
                        box = auxB[ i ];
                        auxB[ i ] = auxB[ i + 1 ];
                        auxB[ i + 1 ] = box;
                    }
                }
            } else if (opc == 2) {
                ordenarLista(p, 4);
                //DESCENDENTE
                for (i = 0; i < 9; i++) {

                    if (auxB[ i ] < auxB[ i + 1 ]) {
                        box = auxB[ i ];
                        auxB[ i ] = auxB[ i + 1 ];
                        auxB[ i + 1 ] = box;
                    }
                }
            }

            for (i = 0; i < 10; i++) {
                if (auxB[ i ] != -1 && pausa == false) {
                    box = auxB[ i ];
                    pausa = true;
                }
            }

            for (int j = 0; j < acumulado2; j++) {
                p = lista;
                if ((listaVacia(lista) != true)) {
                    while (p != NULL) {
                        if (opc == 1) {
                            if (p->pid == box && band == true) {
                                auxPid = p->pid;
                                band = false;
                            }
                        } else if (opc == 2) {
                            if (p->pid == box) {
                                auxPid = p->pid;
                            }
                        }
                        p = p->sig;
                    }
                }
            }
            return auxPid;
        }

    }

}

//REALIZAMOS LO MISMO QUE ARRIBA SOLO QUE SE CAMBIA EL ORDEN Texe<->Prioridad
//Método que recibe por valor a lista y nos regresa el pid de la siguiente manera Prioridad(Alta), T.exe(ligero),  Pid(ASC/DESC) el ultimo int que pide es si es pid asc o desc
int claseNodo::procesoBusqueda2(nodo *lista, int compara, int opc) {
    //Creamos el nodo auxiliar p y le asignamos la dir de lista
    int acumulado = 0, acumulado2 = 0, compara2, auxPid, auxA[10], auxB[10], i, box = 0;
    nodo *p;
    p = lista;
    bool band = true, pausa = false;

    for (i = 0; i < 10; i++) {
        auxA[ i ] = -1;
        auxB[ i ] = -1;
    }
    //Lo recorremos a lista con p y los contamos
    i = 0;
    if ((listaVacia(lista) != true)) {
        while (p != NULL) {
            if (p->prioridad == compara) {
                acumulado = acumulado + 1;
                auxPid = p->pid;
                auxA[ i ] = p->pid;
                i = i + 1;
            }
            p = p->sig;

        }
    }

    if (acumulado == 1) {
        return auxPid;
    } else {
        p = lista;
        ordenarLista(p, 1);
        compara2 = p->Texe;
        i = 0;
        for (int j = 0; j < acumulado; j++) {
            p = lista;
            if ((listaVacia(lista) != true)) {
                while (p != NULL) {
                    if (p->pid == auxA[ j ] && p->Texe == compara2) {
                        acumulado2 = acumulado2 + 1;
                        auxPid = p->pid;
                        auxB[ i ] = p->pid;
                        i = i + 1;
                    }
                    p = p->sig;
                }
            }
        }

        if (acumulado2 == 1) {
            return auxPid;
        } else {
            p = lista;
            if (opc == 3) {
                ordenarLista(p, 3);
                //ASC
                for (i = 0; i < 9; i++) {
                    if (auxB[ i ] > auxB[ i + 1 ]) {
                        box = auxB[ i ];
                        auxB[ i ] = auxB[ i + 1 ];
                        auxB[ i + 1 ] = box;
                    }
                }
            } else if (opc == 4) {
                ordenarLista(p, 4);
                //DESCENDENTE
                for (i = 0; i < 9; i++) {
                    if (auxB[ i ] < auxB[ i + 1 ]) {
                        box = auxB[ i ];
                        auxB[ i ] = auxB[ i + 1 ];
                        auxB[ i + 1 ] = box;
                    }
                }
            }
            for (i = 0; i < 10; i++) {
                if (auxB[ i ] != -1 && pausa == false) {
                    box = auxB[ i ];
                    pausa = true;
                }
            }
            for (int j = 0; j < acumulado2; j++) {
                p = lista;
                if ((listaVacia(lista) != true)) {
                    while (p != NULL) {
                        if (opc == 3) {
                            if (p->pid == box && band == true) {
                                auxPid = p->pid;
                                band = false;
                            }
                        } else if (opc == 4) {
                            if (p->pid == box) {
                                auxPid = p->pid;
                            }
                        }
                        p = p->sig;
                    }
                }
            }
            return auxPid;
        }

    }

}


//Método que retorna un booleano que recibe el nodo de lista por paso de parámetros por valor
bool claseNodo::listaVacia(nodo *lista) {
    //Creamos un nodo aux llamado p
    nodo *p;
    //Asignamos la dir de lista a p
    p = lista;

    //Si p apunta a vacía entonces no hay nada
    if (p == NULL) {
        //std::cout << "Esta vacia!\n" << std::endl;
        return true;
    } else {//Si no es que contiene datos
        return false;
    }
}

//Ordena la lista dependiendo de que se eligio para hacer el orden 1 No trabajador 2 Total 3 Fecha
void claseNodo::ordenarLista(nodo *&lista, int opc) {
    int temp;
    bool temp2;
    //Creamos un nodo aux llamado Borrar
    //Metodo burbuja, tomaremos a apuntador como i y a actual como j
    nodo *apuntador, *actual = NULL;
    //Asignamos la dir de lista a apuntador
    apuntador = lista;
    //Preguntamos si quiere en forma ascendente o descendente para que se ejecute el algoritmo de ordenamiento de burbuja ya sea < o >

    //Dependiendo si 1-Ascendente o 2-Descendente se ordena segun el if que toque
    //Segun el valor de opc será
    //1 para T.exe(Ligero) Ascendente
    //2 para Prioridad(Alta) Descendente
    //3 para Pid(Ascendete)
    //4 para Pid(Descendente)
    //5 Tllegada(Ascendente)
    //6 Tllegada(Descendente)
    while (apuntador != NULL) {
        actual = apuntador->sig;
        while (actual != NULL) {
            if (opc == 1) {
                //Forma Ascendente
                //Ascendente Texe(Ligero)
                if (apuntador->Texe > actual->Texe) {
                    temp = apuntador->Texe;
                    apuntador->Texe = actual->Texe;
                    actual->Texe = temp;

                    temp = apuntador->pid;
                    apuntador->pid = actual->pid;
                    actual->pid = temp;

                    temp = apuntador->Tllegada;
                    apuntador->Tllegada = actual->Tllegada;
                    actual->Tllegada = temp;

                    temp = apuntador->prioridad;
                    apuntador->prioridad = actual->prioridad;
                    actual->prioridad = temp;

                    temp = apuntador->Tespera;
                    apuntador->Tespera = actual->Tespera;
                    actual->Tespera = temp;

                    temp = apuntador->Tfin;
                    apuntador->Tfin = actual->Tfin;
                    actual->Tfin = temp;

                    temp2 = apuntador->fin;
                    apuntador->fin = actual->fin;
                    actual->fin = temp2;
                }
            }
            if (opc == 2) {
                //Forma Descendente
                //Ascendente Prioridad(Alta)
                if (apuntador->prioridad < actual->prioridad) {
                    temp = apuntador->Texe;
                    apuntador->Texe = actual->Texe;
                    actual->Texe = temp;

                    temp = apuntador->pid;
                    apuntador->pid = actual->pid;
                    actual->pid = temp;

                    temp = apuntador->Tllegada;
                    apuntador->Tllegada = actual->Tllegada;
                    actual->Tllegada = temp;

                    temp = apuntador->prioridad;
                    apuntador->prioridad = actual->prioridad;
                    actual->prioridad = temp;

                    temp = apuntador->Tespera;
                    apuntador->Tespera = actual->Tespera;
                    actual->Tespera = temp;

                    temp = apuntador->Tfin;
                    apuntador->Tfin = actual->Tfin;
                    actual->Tfin = temp;

                    temp2 = apuntador->fin;
                    apuntador->fin = actual->fin;
                    actual->fin = temp2;
                }
            }
            if (opc == 3) {
                //Forma Ascendente
                //Ascendente Pid(Ascendete)
                if (apuntador->pid > actual->pid) {
                    temp = apuntador->Texe;
                    apuntador->Texe = actual->Texe;
                    actual->Texe = temp;

                    temp = apuntador->pid;
                    apuntador->pid = actual->pid;
                    actual->pid = temp;

                    temp = apuntador->Tllegada;
                    apuntador->Tllegada = actual->Tllegada;
                    actual->Tllegada = temp;

                    temp = apuntador->prioridad;
                    apuntador->prioridad = actual->prioridad;
                    actual->prioridad = temp;

                    temp = apuntador->Tespera;
                    apuntador->Tespera = actual->Tespera;
                    actual->Tespera = temp;

                    temp = apuntador->Tfin;
                    apuntador->Tfin = actual->Tfin;
                    actual->Tfin = temp;

                    temp2 = apuntador->fin;
                    apuntador->fin = actual->fin;
                    actual->fin = temp2;
                }
            }
            if (opc == 4) {
                //Forma Descendente
                //Ascendente Pid(Descendete)
                if (apuntador->pid < actual->pid) {
                    temp = apuntador->Texe;
                    apuntador->Texe = actual->Texe;
                    actual->Texe = temp;

                    temp = apuntador->pid;
                    apuntador->pid = actual->pid;
                    actual->pid = temp;

                    temp = apuntador->Tllegada;
                    apuntador->Tllegada = actual->Tllegada;
                    actual->Tllegada = temp;

                    temp = apuntador->prioridad;
                    apuntador->prioridad = actual->prioridad;
                    actual->prioridad = temp;

                    temp = apuntador->Tespera;
                    apuntador->Tespera = actual->Tespera;
                    actual->Tespera = temp;

                    temp = apuntador->Tfin;
                    apuntador->Tfin = actual->Tfin;
                    actual->Tfin = temp;

                    temp2 = apuntador->fin;
                    apuntador->fin = actual->fin;
                    actual->fin = temp2;
                }
            }

            if (opc == 5) {
                //Forma Ascendente
                //Ascendente Tllegada(Ascendente)
                if (apuntador->Tllegada > actual->Tllegada) {
                    temp = apuntador->Texe;
                    apuntador->Texe = actual->Texe;
                    actual->Texe = temp;

                    temp = apuntador->pid;
                    apuntador->pid = actual->pid;
                    actual->pid = temp;

                    temp = apuntador->Tllegada;
                    apuntador->Tllegada = actual->Tllegada;
                    actual->Tllegada = temp;

                    temp = apuntador->prioridad;
                    apuntador->prioridad = actual->prioridad;
                    actual->prioridad = temp;

                    temp = apuntador->Tespera;
                    apuntador->Tespera = actual->Tespera;
                    actual->Tespera = temp;

                    temp = apuntador->Tfin;
                    apuntador->Tfin = actual->Tfin;
                    actual->Tfin = temp;

                    temp2 = apuntador->fin;
                    apuntador->fin = actual->fin;
                    actual->fin = temp2;
                }
            }

            if (opc == 6) {
                //Forma Descendente
                //Ascendente Tllegada(Descendente)
                if (apuntador->Tllegada < actual->Tllegada) {
                    temp = apuntador->Texe;
                    apuntador->Texe = actual->Texe;
                    actual->Texe = temp;

                    temp = apuntador->pid;
                    apuntador->pid = actual->pid;
                    actual->pid = temp;

                    temp = apuntador->Tllegada;
                    apuntador->Tllegada = actual->Tllegada;
                    actual->Tllegada = temp;

                    temp = apuntador->prioridad;
                    apuntador->prioridad = actual->prioridad;
                    actual->prioridad = temp;

                    temp = apuntador->Tespera;
                    apuntador->Tespera = actual->Tespera;
                    actual->Tespera = temp;

                    temp = apuntador->Tfin;
                    apuntador->Tfin = actual->Tfin;
                    actual->Tfin = temp;

                    temp2 = apuntador->fin;
                    apuntador->fin = actual->fin;
                    actual->fin = temp2;
                }
            }


            //Se mueve el apuntador j
            actual = actual->sig;
        }
        //Se mueve el apuntador i
        apuntador = apuntador->sig;
    }
    //Muestra el resultado
}

//Método que inserta al inicio que recibe como paso de parámetros a lista como referencia y al dato n para almacenarlo
void
claseNodo::autoListaInicio(nodo *&lista, int pid, int Tllegada, int Texe, int prioridad, int Tespera, bool fin,
                           int Tfin) {
    //Creamos un nodo auxiliar llamado nuevo nodo para recorrer lista
    nodo *nuevo_nodo = new nodo();

    //Llenamos los campos
    nuevo_nodo->pid = pid;
    nuevo_nodo->Tllegada = Tllegada;
    nuevo_nodo->Texe = Texe;
    nuevo_nodo->prioridad = prioridad;
    nuevo_nodo->Tespera = Tespera;
    nuevo_nodo->fin = fin;
    nuevo_nodo->Tfin = Tfin;

    //Asignamos que aux1 sea igual a la dir de lista
    nodo *aux1 = lista;

    if (lista == NULL) {
        //decimos que donde apuntaba lista ahora apunta el nuevo nodo
        nuevo_nodo->sig = aux1;

    } else {
        nuevo_nodo->sig = aux1;

    }
    //Lista tiene la dir de nuevo_nodo para conectarlo con el nuevo elemento
    lista = nuevo_nodo;
    std::cout << "\n" << std::endl;
}

//Método que inserta al final que recibe a lista como referencia y un int n que es el dato a almacenar
void
claseNodo::autoListaFinal(nodo *&lista, int pid, int Tllegada, int Texe, int prioridad, int Tespera, bool fin,
                          int Tfin) { // <<<< NUEVA
    //Creamos un nodo auxiliar llamado nuevo nodo para recorrer lista
    nodo *nuevo_nodo = new nodo();

    //Llenamos los campos
    nuevo_nodo->pid = pid;
    nuevo_nodo->Tllegada = Tllegada;
    nuevo_nodo->Texe = Texe;
    nuevo_nodo->prioridad = prioridad;
    nuevo_nodo->Tespera = Tespera;
    nuevo_nodo->fin = fin;
    nuevo_nodo->Tfin = Tfin;

    //Creamos el nodo aux1 y le asignamos la dir de lista
    nodo *aux1 = lista;
    //Creamos el nodo aux2
    nodo *aux2;

    //Buscamos con este while el último nodo que en su campo sig sea nulo
    while (aux1 != NULL) {
        aux2 = aux1;
        aux1 = aux1->sig;
    }

    aux2->sig = nuevo_nodo;

    std::cout << "\n" << std::endl;
}

//Método que recibe a lista por referencia
void claseNodo::eliminar(nodo *&lista, int pid) {
    //Creamos un nodo aux llamado Borrar
    nodo *Borrar, *auxAnt = NULL;
    //Asignamos la dir de lista a Borrar
    Borrar = lista;

    if ((listaVacia(lista) != true)) {
        //While para recorrer y buscar el dato en la lista
        while ((Borrar != NULL) && (Borrar->pid != pid)) {
            auxAnt = Borrar;
            Borrar = Borrar->sig;
        }
        //Si el apuntador nunca entró al while entonces no existe el elemento
        if (Borrar == NULL) {
            //std::cout << "El elemento no existe...\n" << std::endl;
        }
            //Si es el primer elemento se apunta a lista al campo sig y se borra el primero
        else if (auxAnt == NULL) {
            lista = lista->sig;
            delete Borrar;
        }
            //Fuera de los otros casos se unen el nodo anterior al sig del que se va a eliminar
        else {
            auxAnt->sig = Borrar->sig;
            delete Borrar;
        }
    }
}

//Método que recibe a lista por referencia y actuualiza los tiempos de Tespera, su estado de fin (en dado caso que haya terminado), y su Tespera
void claseNodo::actualizarProceso(nodo *&lista, nodo *&cola, int pid, int max) {
    //Creamos un nodo aux llamado Borrar
    nodo *p;
    //Asignamos la dir de lista a Borrar
    p = lista;

    if ((listaVacia(lista) != true)) {
        while (p != NULL) {
            //Muestra los campos de la lista
            if (p->pid == pid) {
                if (cola == NULL) {
                    autoListaInicio(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, (max) - (p->Tllegada + p->Texe),
                                    true, max);
                } else {
                    autoListaFinal(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, (max) - (p->Tllegada + p->Texe),
                                   true, max);

                }
            }
            p = p->sig;

        }
    }

}

//Método que recibe a lista por referencia y actuualiza los tiempos de Tespera, su estado de fin (en dado caso que haya terminado), y su Tespera
void claseNodo::actualizarProcesoMulti(nodo *&lista, int pid, int max) {
    //Creamos un nodo aux llamado Borrar
    nodo *p;
    //Asignamos la dir de lista a Borrar
    p = lista;

    if ((listaVacia(lista) != true)) {
        while (p != NULL) {
            //Muestra los campos de la lista
            if (p->pid == pid) {
                p->Tespera = (max) - (p->Tllegada + p->Texe);
                p->Tfin = max;
            }
            p = p->sig;

        }
    }

}

//Método que recibe a lista por referencia y a cola , y encola los datos  una vez más , solo en casos que Texe sea mayor a 1
void claseNodo::repetirCola(nodo *&lista, nodo *&cola, int pid, int max) {
    //Creamos un nodo aux llamado Borrar
    nodo *p;
    //Asignamos la dir de lista a Borrar
    p = lista;

    if ((listaVacia(lista) != true)) {
        while (p != NULL) {
            //Muestra los campos de la lista
            if (p->pid == pid) {
                if (cola == NULL) {
                    autoListaInicio(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, (max) - (p->Tllegada + p->Texe),
                                    false, max);
                } else {
                    autoListaFinal(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, (max) - (p->Tllegada + p->Texe),
                                   false, max);

                }
            }
            p = p->sig;

        }
    }

}

//Método que recibe a lista por referencia y copia lo de lista a cola ------ nodo ORIGEN , nodo DESTINO
void claseNodo::actualizarCola(nodo *&lista, nodo *&cola, int pidI) {
    //Creamos un nodo aux llamado Borrar
    nodo *p, *colaSig;
    //Asignamos la dir de lista a Borrar
    p = lista;

    if ((listaVacia(lista) != true)) {
        while (p != NULL) {
            //Muestra los campos de la lista
            if (p->pid == pidI) {
                if (cola == NULL) {
                    autoListaInicio(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, p->Tespera, p->fin,
                                    p->Tfin);
                    colaSig = p;
                    eliminar(lista, colaSig->pid);
                } else {
                    autoListaFinal(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, p->Tespera, p->fin,
                                   p->Tfin);
                    colaSig = p;
                    eliminar(lista, colaSig->pid);
                }
            }
            p = p->sig;
        }
    }

}

//Metodo que ingresa los pids en una matriz para mostrar al usuario y en unos casos regresa el tiempofinalizacion para que lo use el metodo de actualizarproceso
int claseNodo::ingresarMatriz2(int A[], int pidI) {
    int i, acumulado = 0, Tiempofin;
    bool band = false;
    for (i = 0; i < 50; i++) {
        if ((A[ i ] == -1) && band == false) {
            A[ i ] = pidI;
            band = true;
            Tiempofin = i;
        }
    }
    return Tiempofin + 1;
}

//MATRIZ BIDIMENSIONAL - MULTIPROCESO
//Metodo que ingresa los pids en una matriz para mostrar al usuario y en unos casos regresa el tiempofinalizacion para que lo use el metodo de actualizarproceso
void claseNodo::ingresarMatriz3(int A[], int pidI) {
    int i;
    bool band = false;
    for (i = 0; i < 50; i++) {
        if ((A[ i ] == -1) && band == false) {
            A[ i ] = pidI;
            band = true;
        }
    }
}

//MATRIZ BIDIMENSIONAL - MULTIPROCESO
//Metodo que ingresa los pids en una matriz para mostrar al usuario y en unos casos regresa el tiempofinalizacion para que lo use el metodo de actualizarproceso
int claseNodo::ingresarMatriz(int A[], int pidI, int Tiempo) {
    int i, acumulado = 0, Tiempofin;
    bool band = false;
    for (i = 0; i < 50; i++) {
        if ((A[ i ] == -1) && band == false) {
            if (Tiempo == 1) {
                A[ i ] = pidI;
                band = true;
                Tiempofin = i;
            } else {
                for (i = 0; i < 50; i++) {
                    if ((A[ i ] == -1) && band == false) {
                        A[ i ] = pidI;
                        acumulado = acumulado + 1;
                        if (acumulado == Tiempo) {
                            band = true;
                        }
                        Tiempofin = i;
                    }
                }
            }
        }
    }
    return Tiempofin + 1;
}

//MATRIZ BIDIMENSIONAL - MULTIPROCESO
//Metodo que ingresa los pids en una matriz para mostrar al usuario y en unos casos regresa el tiempofinalizacion para que lo use el metodo de actualizarproceso
int claseNodo::ingresarMatrizMulti(int A[][2], int pidI, int Tiempo) {
    int i, acumulado = 0, Tiempofin;
    bool band = false;
    for (i = 0; i < 50; i++) {

        if ((A[ i ][ 0 ] == -1) && band == false) {
            if (Tiempo == 1) {
                A[ i ][ 0 ] = pidI;
                Tiempofin = i;
                band = true;
            }

        } else if ((A[ i ][ 1 ] == -1) && band == false) {
            if (Tiempo == 1) {
                A[ i ][ 1 ] = pidI;
                Tiempofin = i;
                band = true;
            }
        } else {
            for (i = 0; i < 50; i++) {

                if ((A[ i ][ 0 ] == -1) && band == false) {
                    A[ i ][ 0 ] = pidI;
                    acumulado = acumulado + 1;

                    Tiempofin = i;
                }
                if (acumulado == Tiempo) {
                    band = true;
                }
                if ((A[ i ][ 0 ] != -1 && A[ i ][ 1 ] == -1) && band == false) {

                    A[ i ][ 1 ] = pidI;
                    acumulado = acumulado + 1;
                    Tiempofin = i;
                }
                if (acumulado == Tiempo) {
                    band = true;
                }
            }
        }
        return Tiempofin + 1;
    }
}


//MATRIZ BIDIMENSIONAL - MULTIPROCESO
//Metodo que ingresa los pids en una matriz para mostrar al usuario y en unos casos regresa el tiempofinalizacion para que lo use el metodo de actualizarproceso
int claseNodo::ingresarMatrizMulti2(int A[][2], int pidI) {
    int i, acumulado = 0, Tiempofin;
    bool band = false;
    for (i = 0; i < 50; i++) {

        if ((A[ i ][ 0 ] == -1) && band == false) {

            A[ i ][ 0 ] = pidI;
            Tiempofin = i;
            band = true;


        } else if ((A[ i ][ 1 ] == -1) && band == false) {

            A[ i ][ 1 ] = pidI;
            Tiempofin = i;
            band = true;

        }

    }
    return Tiempofin + 1;
}

//Algoritmo que anida MonoProceso-MonoTarea-MultiTarea
void claseNodo::algoritmo1(nodo *&lista, nodo *&colaEspera, nodo *&colaAux, int aux) {
    int i, j, num, tiempoA = 0, max, resultado[50], resultadoMulti[50][2], auxProceso, maxLlegada, tipo, tiempoPausa, auxPausa = 0;
    float promedioG = 0, sumaPromedio = 0, totalPromedio = 0;
    bool band = false, pausa = false;
    nodo *p, *cola, *colaSig;
    ordenarLista(lista, 6);
    p = lista;
    cola = colaEspera;
    maxLlegada = p->Tllegada;
    for (i = 0; i < 50; i++) {
        resultado[ i ] = -1;
        resultadoMulti[ i ][ 0 ] = -1;
        resultadoMulti[ i ][ 1 ] = -1;
    }

    tipo = menu4();
    switch (aux) {
        //MonoTarea-MonoProceso
        case 1:
            num = 0;
            max = 0;
            do {
                ordenarLista(lista, 5);
                p = lista;

                if ((listaVacia(lista) != true) && num <= maxLlegada) {
                    while (p != NULL) {
                        //Muestra los campos de la lista
                        if (p->Tllegada == num) {
                            if (cola == NULL) {
                                autoListaInicio(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, p->Tespera, p->fin,
                                                p->Tfin);
                                colaSig = p;
                                eliminar(lista, colaSig->pid);
                            } else {
                                autoListaFinal(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, p->Tespera, p->fin,
                                               p->Tfin);
                                colaSig = p;
                                eliminar(lista, colaSig->pid);
                            }
                        }
                        p = p->sig;
                    }
                }
                //mostrarLista(cola);
                //std::cout << "Tiempo de Llegada: " << num << std::endl;

                if (tiempoPausa == auxPausa) {
                    pausa = false;
                }

                if (pausa == false) {
                    if (tipo == 1 || tipo == 2) {
                        //Ordenamos a la lista cola por T.exe (ligero)
                        ordenarLista(cola, 1);
                        //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                        auxProceso = procesoBusqueda1(cola, cola->Texe, tipo);
                        //Buscamos el tiempo de ejecucion segun el exe
                        tiempoA = numTexeBusqueda(cola, auxProceso);
                        //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion

                        //std::cout << "pid elegido: " << auxProceso << " texe del pid: " << tiempoA << std::endl;
                        j = ingresarMatriz(resultado, auxProceso, tiempoA);

                        //std::cout << "T fin: " << j << std::endl;
                        max = j;

                        //Actualizamos los datos en la tabla
                        actualizarProceso(cola, lista, auxProceso, j);
                        //Lo eliminamos de la cola una vez finalizado
                        eliminar(cola, auxProceso);
                        if (tiempoA > 1) {
                            pausa = true;
                            tiempoPausa = tiempoA - 2;
                        }
                        num = num + 1;
                        //mostrarLista(cola);
                    } else {
                        //Ordenamos a la lista cola por Prioridad(Alta)
                        ordenarLista(cola, 2);
                        //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                        auxProceso = procesoBusqueda2(cola, cola->prioridad, tipo);
                        //Buscamos el tiempo de ejecucion segun el exe
                        tiempoA = numTexeBusqueda(cola, auxProceso);
                        //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion

                        j = ingresarMatriz(resultado, auxProceso, tiempoA);

                        //El ultimo proceso dirá hasta donde el arreglo llegó
                        max = j;

                        //Actualizamos los datos en la tabla
                        actualizarProceso(cola, lista, auxProceso, j);
                        //Lo eliminamos de la cola una vez finalizado
                        eliminar(cola, auxProceso);
                        if (tiempoA > 1) {
                            pausa = true;
                            tiempoPausa = tiempoA - 2;
                        }
                        num = num + 1;

                    }
                } else {
                    auxPausa = auxPausa + 1;
                    num = num + 1;
                }





                //Condicion de paro , se detendra hasta que la cola se resuelva
                if ((listaVacia(cola) == true)) {
                    band = true;
                }


            } while (band == false);

            //Mostramos los resultados
            ordenarLista(lista, 5);
            //mostrarLista(lista);
            //colaEspera = cola;
            //mostrarLista(cola);

            for (i = 0; i < max; i++) {
                std::cout << "CPU1 [" << i << "] : " << resultado[ i ] << std::endl;
            }
            totalPromedio = checarLista(lista);
            sumaPromedio = sumaEspera(lista);
            promedioG = (sumaPromedio / totalPromedio);
            Espacio();
            std::cout << "Total: " << sumaPromedio << std::endl;
            std::cout << "Promedio: " << promedioG << std::endl;
            break;

            //Multitarea-MonoProceso
        case 2:
            num = 0;
            max = 0;
            do {
                ordenarLista(lista, 5);
                p = lista;

                if ((listaVacia(lista) != true) && num <= maxLlegada) {
                    while (p != NULL) {
                        //Muestra los campos de la lista
                        if (p->Tllegada == num) {
                            if (cola == NULL) {
                                autoListaInicio(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, p->Tespera, p->fin,
                                                p->Tfin);
                                colaSig = p;
                                eliminar(lista, colaSig->pid);
                            } else {
                                autoListaFinal(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, p->Tespera, p->fin,
                                               p->Tfin);
                                colaSig = p;
                                eliminar(lista, colaSig->pid);
                            }
                        }
                        p = p->sig;
                    }
                }

                if (tiempoPausa == auxPausa) {
                    pausa = false;
                }

                if (pausa == false) {
                    if (tipo == 1 || tipo == 2) {
                        //Ordenamos a la lista cola por T.exe (ligero)
                        ordenarLista(cola, 1);
                        //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                        auxProceso = procesoBusqueda1(cola, cola->Texe, tipo);
                        //Buscamos el tiempo de ejecucion segun el exe
                        tiempoA = numTexeBusqueda(cola, auxProceso);
                        //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion

                        //std::cout << "pid elegido: " << auxProceso << " texe del pid: " << tiempoA << std::endl;
                        j = ingresarMatrizMulti(resultadoMulti, auxProceso, tiempoA);

                        //std::cout << "T fin: " << j << std::endl;
                        max = j;

                        //Actualizamos los datos en la tabla
                        actualizarProceso(cola, lista, auxProceso, j);
                        //Lo eliminamos de la cola una vez finalizado
                        eliminar(cola, auxProceso);
                        if (tiempoA > 1) {
                            pausa = true;
                            tiempoPausa = tiempoA - 2;
                        }
                        num = num + 1;
                        //mostrarLista(cola);
                    } else {
                        //Ordenamos a la lista cola por Prioridad(Alta)
                        ordenarLista(cola, 2);
                        //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                        auxProceso = procesoBusqueda2(cola, cola->prioridad, tipo);
                        //Buscamos el tiempo de ejecucion segun el exe
                        tiempoA = numTexeBusqueda(cola, auxProceso);
                        //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion

                        //std::cout << "pid elegido: " << auxProceso << " texe del pid: " << tiempoA << std::endl;
                        j = ingresarMatrizMulti(resultadoMulti, auxProceso, tiempoA);
                        //std::cout << "T fin: " << j << std::endl;
                        max = j;

                        //Actualizamos los datos en la tabla
                        actualizarProceso(cola, lista, auxProceso, j);
                        //Lo eliminamos de la cola una vez finalizado
                        eliminar(cola, auxProceso);
                        if (tiempoA > 1) {
                            pausa = true;
                            tiempoPausa = tiempoA - 2;
                        }
                        num = num + 1;

                    }
                } else {
                    auxPausa = auxPausa + 1;
                    num = num + 1;
                }

                //Condicion de paro , se detendra hasta que la cola se resuelva
                if ((listaVacia(cola) == true)) {
                    band = true;
                }

            } while (band == false);

            ordenarLista(lista, 5);


            for (i = 0; i < max; i++) {
                std::cout << "CPU1 [" << i << "] : " << resultadoMulti[ i ][ 0 ] << std::endl;
                std::cout << "CPU2 [" << i << "] : " << resultadoMulti[ i ][ 1 ] << std::endl;
            }
            totalPromedio = checarLista(lista);
            sumaPromedio = sumaEspera(lista);
            promedioG = (sumaPromedio / totalPromedio);
            Espacio();
            std::cout << "Total: " << sumaPromedio << std::endl;
            std::cout << "Promedio: " << promedioG << std::endl;

            break;
        default:
            std::cout << "Opcion invalida!" << std::endl;
            break;
    }
}


//Algoritmo que anida Multiproceso-MonoTarea-MultiTarea
void claseNodo::algoritmo2(nodo *&lista, nodo *&colaEspera, nodo *&colaAux, int aux) {
    int i, j, num, tiempoA = 0, tiempoB = 0, max, resultado[50], resultadoMulti[50][2], reingreso[50], auxProceso, maxLlegada, tipo, tiempoPausa, auxPausa = 0, parar = 0, parar2 = 0;
    float promedioG = 0, sumaPromedio = 0, totalPromedio = 0;
    bool band = false, pausa = false, denuevo = false;
    nodo *p, *cola, *colaSig = NULL, *cola2;
    ordenarLista(lista, 6);
    p = lista;
    cola = colaEspera;
    cola2 = colaAux;

    maxLlegada = p->Tllegada;
    for (i = 0; i < 50; i++) {
        resultado[ i ] = -1;
        resultadoMulti[ i ][ 0 ] = -1;
        resultadoMulti[ i ][ 1 ] = -1;
        reingreso[ i ] = -1;
    }

    tipo = menu4();
    switch (aux) {
        //MonoTarea-MonoProceso
        case 1:
            num = 0;
            max = 0;

            do {
                ordenarLista(lista, 5);
                p = lista;

                if ((listaVacia(lista) != true) && num <= maxLlegada) {
                    while (p != NULL) {
                        //Muestra los campos de la lista
                        if (p->Tllegada == num && p->fin == false) {
                            if (cola == NULL) {
                                autoListaInicio(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, p->Tespera, p->fin,
                                                p->Tfin);
                                colaSig = p;
                                eliminar(lista, colaSig->pid);
                            } else {
                                autoListaFinal(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, p->Tespera, p->fin, p->Tfin);
                                colaSig = p;
                                eliminar(lista, colaSig->pid);
                            }
                        }
                        p = p->sig;
                    }
                }

                if (tiempoPausa == auxPausa) {
                    pausa = false;
                }

                if (pausa == false) {
                    if (tipo == 1 || tipo == 2) {
                        //Ordenamos a la lista cola por T.exe (ligero)
                        ordenarLista(cola, 1);
                        //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                        auxProceso = procesoBusqueda1(cola, cola->Texe, tipo);
                        //Buscamos el tiempo de ejecucion segun el exe
                        tiempoA = numTexeBusqueda(cola, auxProceso);
                        //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion

                        //std::cout << "pid elegido: " << auxProceso << " texe del pid: " << tiempoA << std::endl;
                        j = ingresarMatriz2(resultado, auxProceso);

                        //std::cout << "T fin: " << j << std::endl;
                        max = j;


                        //Lo eliminamos de la cola una vez finalizado
                        tiempoB = checarRepeticiones(resultado, auxProceso);

                        if (tiempoA != tiempoB) {
                            pausa = true;
                            tiempoPausa = tiempoA - 1;
                            repetirCola(cola, colaAux, auxProceso, j);
                            ingresarMatriz3(reingreso, auxProceso);
                        } else {
                            //Actualizamos los datos en la tabla
                            actualizarProceso(cola, lista, auxProceso, j);
                        }
                        eliminar(cola, auxProceso);
                        num = num + 1;

                    } else {
                        //Ordenamos a la lista cola por Prioridad(Alta)
                        ordenarLista(cola, 2);
                        //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                        auxProceso = procesoBusqueda2(cola, cola->prioridad, tipo);
                        //Buscamos el tiempo de ejecucion segun el exe
                        tiempoA = numTexeBusqueda(cola, auxProceso);
                        //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion

                        j = ingresarMatriz2(resultado, auxProceso);

                        max = j;


                        tiempoB = checarRepeticiones(resultado, auxProceso);

                        if (tiempoA != tiempoB) {
                            pausa = true;
                            tiempoPausa = tiempoA - 1;
                            repetirCola(cola, colaAux, auxProceso, j);
                            ingresarMatriz3(reingreso, auxProceso);
                        } else {
                            //Actualizamos los datos en la tabla
                            actualizarProceso(cola, lista, auxProceso, j);
                        }
                        eliminar(cola, auxProceso);
                        num = num + 1;

                    }
                } else {
                    auxPausa = auxPausa + 1;
                    num = num + 1;
                }

                //Condicion de paro , se detendra hasta que la cola se resuelva
                if (listaVacia(cola) == true) {
                    band = true;
                    if (listaVacia(colaAux) != true) {
                        for (i = 0; i < 50; i++) {
                            if (reingreso[ i ] != -1) {
                                actualizarCola(colaAux, cola, reingreso[ i ]);
                                reingreso[ i ] = -1;
                            }
                        }
                    }

                }

            } while (band == false);

            band = false;
            if (listaVacia(cola) == true) {

            } else {

                do {

                    if (tiempoPausa == auxPausa) {
                        pausa = false;
                    }

                    if (pausa == false) {
                        if (tipo == 1 || tipo == 2) {
                            //Ordenamos a la lista cola por T.exe (ligero)
                            ordenarLista(cola, 1);
                            //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                            auxProceso = procesoBusqueda1(cola, cola->Texe, tipo);
                            //Buscamos el tiempo de ejecucion segun el exe
                            tiempoA = numTexeBusqueda(cola, auxProceso);
                            //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion
                            j = ingresarMatriz2(resultado, auxProceso);
                            //std::cout << "T fin: " << j << std::endl;
                            max = j;
                            //Lo eliminamos de la cola una vez finalizado
                            tiempoB = checarRepeticiones(resultado, auxProceso);

                            if (tiempoA != tiempoB) {
                                pausa = true;
                                tiempoPausa = tiempoA - 1;
                                repetirCola(cola, colaAux, auxProceso, j);
                                ingresarMatriz3(reingreso, auxProceso);
                            } else {
                                //Actualizamos los datos en la tabla
                                actualizarProceso(cola, lista, auxProceso, j);
                            }
                            eliminar(cola, auxProceso);
                            num = num + 1;

                        } else {
                            //Ordenamos a la lista cola por Prioridad(Alta)
                            ordenarLista(cola, 2);
                            //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                            auxProceso = procesoBusqueda2(cola, cola->prioridad, tipo);
                            //Buscamos el tiempo de ejecucion segun el exe
                            tiempoA = numTexeBusqueda(cola, auxProceso);
                            //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion
                            j = ingresarMatriz2(resultado, auxProceso);
                            max = j;
                            tiempoB = checarRepeticiones(resultado, auxProceso);

                            if (tiempoA != tiempoB) {
                                pausa = true;
                                tiempoPausa = tiempoA - 1;
                                repetirCola(cola, colaAux, auxProceso, j);
                                ingresarMatriz3(reingreso, auxProceso);
                            } else {
                                //Actualizamos los datos en la tabla
                                actualizarProceso(cola, lista, auxProceso, j);
                            }
                            eliminar(cola, auxProceso);
                            num = num + 1;

                        }
                    } else {
                        auxPausa = auxPausa + 1;
                        num = num + 1;
                    }

                    //Condicion de paro , se detendra hasta que la cola se resuelva
                    if (listaVacia(cola) == true) {
                        band = true;
                        if (listaVacia(colaAux) != true) {
                            for (i = 0; i < 50; i++) {
                                if (reingreso[ i ] != -1) {
                                    actualizarCola(colaAux, cola, reingreso[ i ]);
                                    reingreso[ i ] = -1;
                                }
                            }
                        }
                    }
                } while (band == false);
            }

            band = false;
            if (listaVacia(cola) == true) {

            } else {
                do {
                    if (tiempoPausa == auxPausa) {
                        pausa = false;
                    }
                    if (pausa == false) {
                        if (tipo == 1 || tipo == 2) {
                            //Ordenamos a la lista cola por T.exe (ligero)
                            ordenarLista(cola, 1);
                            //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                            auxProceso = procesoBusqueda1(cola, cola->Texe, tipo);
                            //Buscamos el tiempo de ejecucion segun el exe
                            tiempoA = numTexeBusqueda(cola, auxProceso);
                            //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion
                            j = ingresarMatriz2(resultado, auxProceso);
                            max = j;
                            //Lo eliminamos de la cola una vez finalizado
                            tiempoB = checarRepeticiones(resultado, auxProceso);

                            if (tiempoA != tiempoB) {
                                pausa = true;
                                tiempoPausa = tiempoA - 1;
                                repetirCola(cola, colaAux, auxProceso, j);
                                ingresarMatriz3(reingreso, auxProceso);
                            } else {
                                //Actualizamos los datos en la tabla
                                actualizarProceso(cola, lista, auxProceso, j);
                            }
                            eliminar(cola, auxProceso);
                            num = num + 1;

                        } else {
                            //Ordenamos a la lista cola por Prioridad(Alta)
                            ordenarLista(cola, 2);
                            //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                            auxProceso = procesoBusqueda2(cola, cola->prioridad, tipo);
                            //Buscamos el tiempo de ejecucion segun el exe
                            tiempoA = numTexeBusqueda(cola, auxProceso);
                            //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion
                            j = ingresarMatriz2(resultado, auxProceso);
                            max = j;
                            tiempoB = checarRepeticiones(resultado, auxProceso);

                            if (tiempoA != tiempoB) {
                                pausa = true;
                                tiempoPausa = tiempoA - 1;
                                repetirCola(cola, colaAux, auxProceso, j);
                                ingresarMatriz3(reingreso, auxProceso);
                            } else {
                                //Actualizamos los datos en la tabla
                                actualizarProceso(cola, lista, auxProceso, j);
                            }
                            eliminar(cola, auxProceso);
                            num = num + 1;
                        }
                    } else {
                        auxPausa = auxPausa + 1;
                        num = num + 1;
                    }
                    //Condicion de paro , se detendra hasta que la cola se resuelva
                    if (listaVacia(cola) == true) {
                        band = true;
                        if (listaVacia(colaAux) != true) {
                            for (i = 0; i < 50; i++) {
                                if (reingreso[ i ] != -1) {
                                    actualizarCola(colaAux, cola, reingreso[ i ]);
                                    reingreso[ i ] = -1;
                                }
                            }
                        }
                    }
                } while (band == false);
            }

            ordenarLista(lista, 5);

            for (i = 0; i < 50; i++) {
                if (resultado[ i ] != -1) {
                    std::cout << "CPU1 [" << i << "] : " << resultado[ i ] << std::endl;
                }
            }

            totalPromedio = checarLista(lista);
            sumaPromedio = sumaEspera(lista);
            promedioG = (sumaPromedio / totalPromedio);
            Espacio();
            std::cout << "Total: " << sumaPromedio << std::endl;
            std::cout << "Promedio: " << promedioG << std::endl;
            break;

            //TRABAJAR
            //Multitarea-MonoProceso
        case 2:
            num = 0;
            max = 0;

            do {
                ordenarLista(lista, 5);
                p = lista;

                if ((listaVacia(lista) != true) && num <= maxLlegada) {
                    while (p != NULL) {
                        //Muestra los campos de la lista
                        if (p->Tllegada == num && p->fin == false) {
                            if (cola == NULL) {
                                autoListaInicio(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, p->Tespera, p->fin,
                                                p->Tfin);
                                colaSig = p;
                                eliminar(lista, colaSig->pid);
                            } else {
                                autoListaFinal(cola, p->pid, p->Tllegada, p->Texe, p->prioridad, p->Tespera, p->fin,
                                               p->Tfin);
                                colaSig = p;
                                eliminar(lista, colaSig->pid);
                            }
                        }
                        p = p->sig;
                    }
                }

                if (tiempoPausa == auxPausa) {
                    pausa = false;
                }

                if (pausa == false) {
                    if (tipo == 1 || tipo == 2) {
                        //Ordenamos a la lista cola por T.exe (ligero)
                        ordenarLista(cola, 1);
                        //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                        auxProceso = procesoBusqueda1(cola, cola->Texe, tipo);
                        //Buscamos el tiempo de ejecucion segun el exe
                        tiempoA = numTexeBusqueda(cola, auxProceso);
                        //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion
                        j = ingresarMatriz2(resultado, auxProceso);
                        max = j;

                        //Lo eliminamos de la cola una vez finalizado
                        tiempoB = checarRepeticiones(resultado, auxProceso);
                        if (tiempoA != tiempoB) {
                            pausa = true;
                            tiempoPausa = tiempoA - 1;
                            repetirCola(cola, colaAux, auxProceso, j);
                            ingresarMatriz3(reingreso, auxProceso);
                        } else {
                            //Actualizamos los datos en la tabla
                            actualizarProceso(cola, lista, auxProceso, j);
                        }
                        eliminar(cola, auxProceso);
                        num = num + 1;

                    } else {
                        //Ordenamos a la lista cola por Prioridad(Alta)
                        ordenarLista(cola, 2);
                        //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                        auxProceso = procesoBusqueda2(cola, cola->prioridad, tipo);
                        //Buscamos el tiempo de ejecucion segun el exe
                        tiempoA = numTexeBusqueda(cola, auxProceso);
                        //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion

                        j = ingresarMatriz2(resultado, auxProceso);
                        max = j;
                        tiempoB = checarRepeticiones(resultado, auxProceso);

                        if (tiempoA != tiempoB) {
                            pausa = true;
                            tiempoPausa = tiempoA - 1;
                            repetirCola(cola, colaAux, auxProceso, j);
                            ingresarMatriz3(reingreso, auxProceso);
                        } else {
                            //Actualizamos los datos en la tabla
                            actualizarProceso(cola, lista, auxProceso, j);
                        }
                        eliminar(cola, auxProceso);
                        num = num + 1;

                    }
                } else {
                    auxPausa = auxPausa + 1;
                    num = num + 1;
                }

                //Condicion de paro , se detendra hasta que la cola se resuelva
                if (listaVacia(cola) == true) {
                    band = true;
                    if (listaVacia(colaAux) != true) {
                        for (i = 0; i < 50; i++) {
                            if (reingreso[ i ] != -1) {
                                actualizarCola(colaAux, cola, reingreso[ i ]);
                                reingreso[ i ] = -1;
                            }
                        }
                    }
                }
            } while (band == false);

            band = false;
            if (listaVacia(cola) == true) {

            } else {
                do {
                    if (tiempoPausa == auxPausa) {
                        pausa = false;
                    }

                    if (pausa == false) {
                        if (tipo == 1 || tipo == 2) {
                            //Ordenamos a la lista cola por T.exe (ligero)
                            ordenarLista(cola, 1);
                            //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                            auxProceso = procesoBusqueda1(cola, cola->Texe, tipo);
                            //Buscamos el tiempo de ejecucion segun el exe
                            tiempoA = numTexeBusqueda(cola, auxProceso);
                            //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion
                            j = ingresarMatriz2(resultado, auxProceso);
                            max = j;

                            //Lo eliminamos de la cola una vez finalizado
                            tiempoB = checarRepeticiones(resultado, auxProceso);
                            if (tiempoA != tiempoB) {
                                pausa = true;
                                tiempoPausa = tiempoA - 1;
                                repetirCola(cola, colaAux, auxProceso, j);
                                ingresarMatriz3(reingreso, auxProceso);
                            } else {
                                //Actualizamos los datos en la tabla
                                actualizarProceso(cola, lista, auxProceso, j);
                            }
                            eliminar(cola, auxProceso);
                            num = num + 1;

                        } else {
                            //Ordenamos a la lista cola por Prioridad(Alta)
                            ordenarLista(cola, 2);
                            //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                            auxProceso = procesoBusqueda2(cola, cola->prioridad, tipo);
                            //Buscamos el tiempo de ejecucion segun el exe
                            tiempoA = numTexeBusqueda(cola, auxProceso);
                            //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion

                            j = ingresarMatriz2(resultado, auxProceso);
                            max = j;
                            tiempoB = checarRepeticiones(resultado, auxProceso);

                            if (tiempoA != tiempoB) {
                                pausa = true;
                                tiempoPausa = tiempoA - 1;
                                repetirCola(cola, colaAux, auxProceso, j);
                                ingresarMatriz3(reingreso, auxProceso);
                            } else {
                                //Actualizamos los datos en la tabla
                                actualizarProceso(cola, lista, auxProceso, j);
                            }
                            eliminar(cola, auxProceso);
                            num = num + 1;

                        }
                    } else {
                        auxPausa = auxPausa + 1;
                        num = num + 1;
                    }

                    //Condicion de paro , se detendra hasta que la cola se resuelva
                    if (listaVacia(cola) == true) {
                        band = true;
                        if (listaVacia(colaAux) != true) {
                            for (i = 0; i < 50; i++) {
                                if (reingreso[ i ] != -1) {
                                    actualizarCola(colaAux, cola, reingreso[ i ]);
                                    reingreso[ i ] = -1;
                                }
                            }
                        }
                    }
                } while (band == false);
            }

            band = false;
            if (listaVacia(cola) == true) {

            } else {
                do {
                    if (tiempoPausa == auxPausa) {
                        pausa = false;
                    }
                    if (pausa == false) {
                        if (tipo == 1 || tipo == 2) {
                            //Ordenamos a la lista cola por T.exe (ligero)
                            ordenarLista(cola, 1);
                            //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                            auxProceso = procesoBusqueda1(cola, cola->Texe, tipo);
                            //Buscamos el tiempo de ejecucion segun el exe
                            tiempoA = numTexeBusqueda(cola, auxProceso);
                            //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion
                            j = ingresarMatriz2(resultado, auxProceso);
                            max = j;

                            //Lo eliminamos de la cola una vez finalizado
                            tiempoB = checarRepeticiones(resultado, auxProceso);

                            if (tiempoA != tiempoB) {
                                pausa = true;
                                tiempoPausa = tiempoA - 1;
                                repetirCola(cola, colaAux, auxProceso, j);
                                ingresarMatriz3(reingreso, auxProceso);
                            } else {
                                //Actualizamos los datos en la tabla
                                actualizarProceso(cola, lista, auxProceso, j);
                            }
                            eliminar(cola, auxProceso);
                            num = num + 1;

                        } else {
                            //Ordenamos a la lista cola por Prioridad(Alta)
                            ordenarLista(cola, 2);
                            //Buscamos el pid del proceso que segun el 1er algoritmo es T.exe(ligero) - Prioridad(Alta) - Pid(ASC)
                            auxProceso = procesoBusqueda2(cola, cola->prioridad, tipo);
                            //Buscamos el tiempo de ejecucion segun el exe
                            tiempoA = numTexeBusqueda(cola, auxProceso);
                            //Guardamos en el arreglo su ejecucion del proceso almacenando el pid dependiendo el tiempo de ejecucion
                            j = ingresarMatriz2(resultado, auxProceso);
                            max = j;

                            tiempoB = checarRepeticiones(resultado, auxProceso);
                            if (tiempoA != tiempoB) {
                                pausa = true;
                                tiempoPausa = tiempoA - 1;
                                repetirCola(cola, colaAux, auxProceso, j);
                                ingresarMatriz3(reingreso, auxProceso);
                            } else {
                                //Actualizamos los datos en la tabla
                                actualizarProceso(cola, lista, auxProceso, j);
                            }
                            eliminar(cola, auxProceso);
                            num = num + 1;
                        }
                    } else {
                        auxPausa = auxPausa + 1;
                        num = num + 1;
                    }

                    //Condicion de paro , se detendra hasta que la cola se resuelva
                    if (listaVacia(cola) == true) {
                        band = true;
                        if (listaVacia(colaAux) != true) {
                            for (i = 0; i < 50; i++) {
                                if (reingreso[ i ] != -1) {
                                    actualizarCola(colaAux, cola, reingreso[ i ]);
                                    reingreso[ i ] = -1;
                                }
                            }
                        }
                    }
                } while (band == false);
            }
            ordenarLista(lista, 5);
            j = 0;
            for (i = 0; i < 50; i++) {
                if ((resultado[ i ] != -1)) {
                    j = ingresarMatrizMulti2(resultadoMulti, resultado[ i ]);
                    actualizarProcesoMulti(lista, resultado[ i ], j);
                }
            }
            for (i = 0; i < j; i++) {
                std::cout << "CPU1 [" << i << "] : " << resultadoMulti[ i ][ 0 ] << std::endl;
                std::cout << "CPU2 [" << i << "] : " << resultadoMulti[ i ][ 1 ] << std::endl;
            }
            totalPromedio = checarLista(lista);
            sumaPromedio = sumaEspera(lista);
            promedioG = (sumaPromedio / totalPromedio);
            Espacio();
            std::cout << "Total: " << sumaPromedio << std::endl;
            std::cout << "Promedio: " << promedioG << std::endl;
            break;
        default:
            std::cout << "Opcion invalida!" << std::endl;
            break;
    }
}

//Clase main donde creamos un objeto de tipo claseNodo llamando lista y llamamos al método menu de lista
int main() {
    //SE CREA UN OBJETO LLAMADO LISTA
    claseNodo Lista;
    //SE INVOCA EL METODO MENU DEL OBJETO LISTA
    Lista.menu();
    return 0;
}

