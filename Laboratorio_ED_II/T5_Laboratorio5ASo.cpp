#include <iostream>
#include <fstream>

using namespace std;

struct nodo{
    int nro;
    struct nodo *izq, *der;
};

typedef struct nodo *ArbolBinario;

ArbolBinario crearNodo(int x){
    ArbolBinario nuevoNodo = new(struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

void insertar(ArbolBinario &arbol, int x){
    if(arbol==NULL)
        arbol = crearNodo(x);
    else if(x < arbol->nro)
        insertar(arbol->izq, x);
    else if(x > arbol->nro)
        insertar(arbol->der, x);
}

void preOrden(ArbolBinario arbol){
    if(arbol!=NULL){
        cout << arbol->nro <<" ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void enOrden(ArbolBinario arbol){
    if(arbol!=NULL){
        enOrden(arbol->izq);
        cout << arbol->nro << " ";
        enOrden(arbol->der);
    }
}

void postOrden(ArbolBinario arbol){
    if(arbol!=NULL){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->nro << " ";
    }
}

void mostrarGrafo(ArbolBinario arbol){
    ofstream archivo;
    archivo.open("D:\\Graphviz\\bin\\T5_ArbolBi.dot", ios::app);
    if(arbol!=NULL){
        if(arbol->izq!=NULL){
            archivo << arbol->nro << " -- " <<arbol->izq->nro<< ";"<<endl;
        }
        if(arbol->der!=NULL){
            archivo << arbol->nro << " -- " <<arbol->der->nro<<";"<<endl;
        }
        mostrarGrafo(arbol->izq);
        mostrarGrafo(arbol->der);
    }
}

void mostrar(ArbolBinario arbol){
    ofstream archivo;
    archivo.open("D:\\Graphviz\\bin\\T5_ArbolBi.dot", ios::app);
    archivo<<"}";
    archivo.close();
    system("D: & cd Graphviz & cd bin & dot T5_ArbolBi.dot -o T5_ArbolBi.png -Tpng & T5_ArbolBi.png");
}

void creargrafo(ArbolBinario arbol){
    ofstream archivo;
    archivo.open("D:\\Graphviz\\bin\\T5_ArbolBi.dot");
    archivo<< "graph G {"<< endl;
    mostrarGrafo(arbol);
    mostrar(arbol);
}

int main(){

    ArbolBinario arbol = NULL;
    cout << "\n ...EJEMPLO DE ARBOL BINARIO... \n";
    insertar(arbol, 10);
    insertar(arbol, 5);
    insertar(arbol, 4);
    insertar(arbol, 9);
    insertar(arbol, 3);
    insertar(arbol, 6);
    insertar(arbol, 1);
    insertar(arbol, 7);
    insertar(arbol, 5);
    cout << "\nRecorridos del ArbolBinario\n";
    cout << "\nEn orden : "; enOrden(arbol);
    cout << "\nPre Orden : "; preOrden(arbol);
    cout << "\nPost Orden : "; postOrden(arbol);
    cout << endl << endl;
    creargrafo(arbol);
    return 0;

}