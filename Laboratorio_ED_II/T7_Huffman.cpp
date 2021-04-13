/*//////////////   GUIA ARBOLES HUFFMAN   //////////////////////////////

    -RUSHELL VANESSA ZAVALAGA OROZCO    */

/*////////////////          ACTIVIDADES           /////////////////////
    
    a) Crear un archivo de texto plano formado por la combinación de letras
        “a”,”b”,”c”,”d,”e” y “f” en las siguientes cantidades:
            
            Letras      a    b    c    d    e    F
            Cantidades  45   13   12   16   9    5
    
    b) Crear una estructura de datos como se muestra a continuación:
        ---
    c) Leer el archivo de texto plano creado en el paso 1 y crear una lista ordenada. 
        Observe que la lista se encuentra ordenada por la frecuencia de aparición de 
        los caracteres.
    
    d) Diseñe un algoritmo de tal manera que forme un árbol de Huffman.
        Se sugiere:
            - Crear un nuevo nodo.
            - Leer los dos primeros elementos de la lista
            - Formar el árbol
            - Ajustar los punteros, y
            - Reordenarlo en la lista.

    e) Recorra el árbol y reconozca las siguientes cadenas.
        W1 = 000
        W2 = 100011001101
        W3 = 110001001101

    f) Proponga y diseñe un algoritmo, en referencia al árbol de Huffman, que codifique un
        archivo de texto plano.

    g) Proponga y diseñe un algoritmo, en referencia al árbol de Huffman, que decodifique
        un archivo de texto plano.

    h) Proponga y diseñe un algoritmo, que permita grabar y recuperar el árbol de hufman en
        un archivo de texto plano

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//     B                                    ///////////////////////
// b) Crear una estructura de datos como se muestra a continuación.

struct nodo{
    char letra;
    int cantidad;
    struct nodo *sig; 
    struct nodo *izq, *der;
};

typedef struct nodo *Inicio;

Inicio crearNodo(char a){
    Inicio nuevoNodo = new(struct nodo);
    nuevoNodo->letra = a;
    nuevoNodo->cantidad = 1;
    nuevoNodo->sig = NULL;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

//     C                                    ///////////////////////
// c) Crear una estructura de datos como se muestra a continuación.

/*   - Conforme se vaya leyendo el archivo, crear el nodo y almacenar 
        las frecuencias de aparición.*/
void insertar(Inicio &arbol, char a){
    if(arbol==NULL)
        arbol = crearNodo(a);
    else if(a==arbol->letra)
        arbol->cantidad++;
    else 
        insertar(arbol->sig, a);
}

/*    - Aplicar un algoritmo de ordenación para obtener la lista ordenada en 
        base a la frecuencia. */

// Función booleana que verifica si esta ordenado o no
bool estaO(Inicio &arbol){
    if(arbol->sig != NULL){
        if(arbol->cantidad <= arbol->sig->cantidad)
            estaO(arbol->sig);
        else
            return false;
    }else{
        return true;
    }
}

// Función para ordenar con el método Burbuja
void ordenar(Inicio &arbol){
    int aux;
    char aux2;
    if(arbol->sig!=NULL){
        if(arbol->cantidad >= arbol->sig->cantidad){
            aux=arbol->sig->cantidad;
            arbol->sig->cantidad=arbol->cantidad;
            arbol->cantidad=aux;

            aux2=arbol->sig->letra;
            arbol->sig->letra=arbol->letra;
            arbol->letra=aux2;
        }
        ordenar(arbol->sig);
    }
}

//     D                                    ///////////////////////
// d) Diseñe un algoritmo de tal manera que forme un árbol de Huffman.

//  - Crear un nuevo nodo.
Inicio crearNodoTemp(Inicio &arbol){
    Inicio nuevoNodo = new(struct nodo);
    nuevoNodo->letra = NULL;
    nuevoNodo->cantidad = arbol->cantidad + arbol->sig->cantidad;
    nuevoNodo->sig = NULL;    
    nuevoNodo->izq = arbol;
    nuevoNodo->der = arbol->sig;

    cout<<endl;
    cout<<"NODO TEMPORAL CREADO: "<<endl;
    cout<<"Cantidad "<< nuevoNodo->cantidad<<endl;
    cout<<"Izquierdo "<< nuevoNodo->izq->cantidad<<endl;
    cout<<"Derecho "<< nuevoNodo->der->cantidad<<endl;
    cout<<endl;

    return nuevoNodo;
}

//  - Ajustar los punteros, y
//  - Reordenarlo en la lista.
void insertarNodoTemp(Inicio &arbol, Inicio &Temp){
    if(arbol->sig != NULL){
        cout<<arbol->cantidad<<" < "<<Temp->cantidad<<"(Nodo Temporal) < "<<arbol->sig->cantidad<<endl;
        if(arbol->cantidad < Temp->cantidad && Temp->cantidad < arbol->sig->cantidad){
            Temp->sig = arbol->sig;
            arbol->sig = Temp;
            cout<<"      VERDADERO "<<endl;
        }
        else
            insertarNodoTemp(arbol->sig, Temp); 
    }else
        arbol->sig = Temp;
}

//  - Leer los dos primeros elementos de la lista
//  - Formar el árbol
//  - Función principal
void crearTemp(Inicio &arbol, Inicio &Temp){
    Temp = crearNodoTemp(arbol);
    if (arbol->sig->sig != NULL){
        arbol = arbol->sig->sig;
        cout<<"Insertando Nodo Temporal "<<endl;
        insertarNodoTemp(arbol, Temp);
    }
    else  
        arbol = Temp;
}

//  - FUNCION INNECESARIA (muestra el arbol)
void mostrar(Inicio &arbol){
    if (arbol->sig!= NULL){
        cout<<arbol->letra<<" "<<arbol->cantidad<<" "<<endl;
        if(arbol)
            mostrar(arbol->sig);
    }else
        cout<<arbol->letra<<" "<<arbol->cantidad<<" "<<endl;
}

//     E                                    ///////////////////////
/* e) Recorra el árbol y reconozca las siguientes cadenas.
        W1 = 000
        W2 = 100011001101
        W3 = 110001001101  
*/

//   - Funcíón para saber cuantos digitos tiene la cadena
int num(char *a, int cont, int i){
    if (a[i] == '\0'){
        return cont;
    }else{
        cont++;
        i++;
        num(a, cont, i);
    }
}

//   - Función que devuelve la letra segun la cadena
char recorrerCHAR(Inicio &arbol, char *a, int i){
    if (arbol->der!= NULL || arbol->izq != NULL){
        if (a[i] == '0'){
            i++;
            recorrerCHAR(arbol->izq, a, i);
        }
        else if(a[i] == '1'){
            i++;
            recorrerCHAR(arbol->der, a, i);
        }
        else if(a[i] == ' '){
            i++;
            cout<<" ";
            recorrerCHAR(arbol, a, i);
        }
    }else
        return arbol->letra;
}

//   - Función que retorna la posición para comenzar de nuevo en caso ya haya sacado una letra
int recorrerINT(Inicio &arbol, char *a, int posicion){
    if (arbol->der!= NULL || arbol->izq != NULL){
        if (a[posicion] == '0'){
            posicion++;
            recorrerINT(arbol->izq, a, posicion);
        }
        else if(a[posicion] == '1'){
            posicion++;
            recorrerINT(arbol->der, a, posicion);
        }else if(a[posicion] == ' '){
            posicion++;
            recorrerINT(arbol, a, posicion);
        }
    }else
        return posicion;
}

//   - Función que construye a las tres funciones (PRINCIPAL)
void recorrer(Inicio &arbol, char *a){
    int cont1 = 0, inicial = 0;
    int nm = num(a, inicial, inicial);
    while(cont1 < nm){
        cout<<recorrerCHAR(arbol, a , cont1);
        cont1 = recorrerINT(arbol, a, cont1);
    }
}

//     F                                    ///////////////////////
/* f) Proponga y diseñe un algoritmo, en referencia al árbol de Huffman, que codifique un
        archivo de texto plano 
*/

// Función que saca todas las codificaciones posibles
void codificacioNES(Inicio &arbol, char *cadena, int i, int &j, char **codificaciones){
    if(arbol!=NULL){
        if (arbol->letra == NULL){
            if (arbol->izq != NULL){
                cadena[i] = '0';
                i++;
                codificacioNES(arbol->izq, cadena, i, j, codificaciones);
                i--;
            }
            if (arbol->der != NULL){
                cadena[i] = '1';
                i++;
                codificacioNES(arbol->der, cadena, i, j, codificaciones);
                i--;
            }
        }else{
            codificaciones[j] = cadena;
            cout<<"Posi: "<<j<<" "<<codificaciones[j]<<endl;
            j++;
            cadena = NULL;
        }
    }
}

//Función principal
void codificarPr(Inicio &arbol, char a, int i, char **codificaciones){
    cout<<"En codificar "<<endl;
    int inicial = 0;
    if (recorrerCHAR(arbol, codificaciones[i] ,inicial) == a){
        cout<<codificaciones[i];
    }else{
        i++;
        codificarPr(arbol, a, i, codificaciones);
    }
}

// Abre fichero
void codificar(Inicio &arbol, int i, char **codificaciones){
    char a;
    ifstream archivo;
	archivo.open("D:\\projects\\Laboratorio ED\\T7_Huffman.txt");
    while(!archivo.eof()){
        archivo >> a; 
        codificarPr(arbol, a, i, codificaciones);
    }
    archivo.close();
}

//     G                                    ///////////////////////
/* g) Proponga y diseñe un algoritmo, en referencia al árbol de Huffman, que decodifique
        un archivo de texto plano.
*/

// Función principal G
void decodificar(Inicio &arbol){
    char cadena[1000];
    ifstream archivo;
    archivo.open("D:\\projects\\Laboratorio ED\\T7_HuffmanCodificado.txt");
    cout<<"Archivo codificado y descodificado "<<endl<<endl;
    while(!archivo.eof()){
        archivo.getline(cadena, 1000);
        cout<<cadena<<" = ";
        recorrer(arbol, cadena);
        cout<<endl;
    }
}

//     H                                    ///////////////////////
/* h) Proponga y diseñe un algoritmo, que permita grabar y recuperar el árbol de hufman en
        un archivo de texto plano.
*/

// Mostrar grafo construye la parte general del grafo 
void mostrarGrafo(Inicio &arbol){
    ofstream archivo;
    archivo.open("D:\\Graphviz\\bin\\T7_ArbolHUFFMAN.dot", ios::app);
    if(arbol!=NULL){
        if (arbol->letra == NULL)
            if(arbol->izq->letra !=NULL){
                cout << arbol->cantidad << " -> " <<arbol->izq->letra<< ";"<<endl;
                archivo << arbol->cantidad << " -> " <<arbol->izq->letra<< ";"<<endl;
            }else{
                cout << arbol->cantidad << " -> " <<arbol->izq->cantidad<< ";"<<endl;
                archivo << arbol->cantidad << " -> " <<arbol->izq->cantidad<< ";"<<endl;
                mostrarGrafo(arbol->izq);
            }if (arbol->der->letra != NULL){
                cout << arbol->cantidad << " -> " <<arbol->der->letra<< ";"<<endl;
                archivo << arbol->cantidad << " -> " <<arbol->der->letra<< ";"<<endl;
            }else{
                cout << arbol->cantidad << " -> " <<arbol->der->cantidad<< ";"<<endl;
                archivo << arbol->cantidad << " -> " <<arbol->der->cantidad<< ";"<<endl;
                mostrarGrafo(arbol->der);
            }
    }
    archivo.close();
}

// Info pasa la frecuencia de las letras para formar un nodo de doble espacio (letra, frecuencia)
void info(Inicio &arbol){
    ofstream archivo;
    archivo.open("D:\\Graphviz\\bin\\T7_ArbolHUFFMAN.dot", ios::app);
    if (arbol != NULL){
        if (arbol->letra != NULL){
            cout<<arbol->letra<<" [shape=record, label= \"{{" <<arbol->letra<<"|"<<arbol->cantidad<< "}}\"];"<<endl;
            archivo<<arbol->letra<<" [shape=record, label= \"{{" <<arbol->letra<<"|"<<arbol->cantidad<< "}}\"];"<<endl;
        }
        info(arbol->izq);
        info(arbol->der);
    }
    archivo.close();
}

// Termina de construir la función y la imprime
void mostrarGrafo1(){
    ofstream archivo;
    archivo.open("D:\\Graphviz\\bin\\T7_ArbolHUFFMAN.dot", ios::app);
    cout<<"}";
    archivo<<"}";
    archivo.close();
    system("D:  & cd Graphviz & cd bin & dot T7_ArbolHUFFMAN.dot -o T7_ArbolHUFFMAN.png -Tpng & T7_ArbolHUFFMAN.png ");
}

// Función principal que inicializa las demas funciones
void creargrafo(Inicio &arbol){
    ofstream archivo;
    archivo.open("D:\\Graphviz\\bin\\T7_ArbolHUFFMAN.dot");
    cout<< "digraph G {"<< endl;
    archivo<< "digraph G {"<< endl;
    mostrarGrafo(arbol);
    info(arbol);
    mostrarGrafo1();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    Inicio arbol = NULL;
    Inicio Temp = NULL;
    ifstream archivo;
	archivo.open("D:\\projects\\Laboratorio ED\\T7_Huffman.txt");
    char cad;
    char a[100];

    cout<<"////////////////    C)     INSERTAR ARBOL                 /////////////////"<<endl;
    while(!archivo.eof()){
        archivo >> cad; 
        insertar(arbol, cad);
    }
    archivo.close();
    mostrar(arbol);
    cout<<endl;

    cout<<"////////////////    C)     ORDENAR ARBOL                 /////////////////"<<endl;
    while (!estaO(arbol)){
        ordenar(arbol);
    }
    mostrar(arbol);
    cout<<endl;

    cout<<"////////////////    D)   FORMAR ARBOL DE HUFFMAN         /////////////////"<<endl;
    while (arbol->sig!= NULL){
        crearTemp(arbol, Temp);
        cout<<endl;
        cout<<"Mostrando arbol: "<<endl;  
        mostrar(arbol); 
    }
    cout<<endl;
    mostrarGrafo(arbol);

    /*cout<<"////////////////    E)     RECONOCER CADENA               /////////////////"<<endl;
    for(int i=0; i<3; i++){
        cout<<"Ingrese CADENA: ";cin>>a;
        recorrer(arbol, a);
        cout<<endl;
    }
    cout<<endl<<endl;

    cout<<"////////////////    F)      CODIFICANDO ARCHIVO TXT        /////////////////"<<endl;
    int i = 0, j = 0;
    char cadena[50];
    char *codificaciones[10];
    codificacioNES(arbol, cadena, i, j, codificaciones);
    codificar(arbol, i, codificaciones);
   
    cout<<"////////////////     G)      DECODIFICANDO ARCHIVO TXT     /////////////////"<<endl;
    decodificar(arbol);
    cout<<endl;

    cout<<"////////////////     H)     RECUPERAR ARBOL HUFFMAN TXT     /////////////////"<<endl;
    cout<<"Información guardada en el archivo de texto - dot"<<endl<<endl;
    creargrafo(arbol);
    cout<<endl;
*/
}