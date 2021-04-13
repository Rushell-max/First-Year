/*//////////////   ISOMORFISMO DE ARBOLES // LAB 9  //////////////////////////////

    -RUSHELL VANESSA ZAVALAGA OROZCO 
*/

/*////////////////          ACTIVIDADES                    ///////////////////////////////////////

	a) Considerando la estructura nodo generar un par de arboles binarios y mostrarlos
        gráficamente.
    
    b) Implementar el siguiente algoritmo y determinar si los arboles de la actividad a) son
        isomorfos.

*/

#include <iostream>
#include <fstream>

using namespace std;

//     A                                    ///////////////////////
/* 	a) Considerando la estructura nodo generar un par de arboles binarios y mostrarlos
        gráficamente.*/

struct nodo{
    string dato;
    struct nodo *izq, *der;
};

typedef struct nodo *ArbolBinario;

ArbolBinario crearNodo(string dato){
    ArbolBinario nuevoNodo = new(struct nodo);
    nuevoNodo->dato = dato;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

void insertar(ArbolBinario &arbol, string dato){
    if(arbol==NULL){
        arbol = crearNodo(dato);
    }else if(dato < arbol->dato){
        insertar(arbol->izq, dato);
    }else if(dato > arbol->dato){
        insertar(arbol->der, dato);
    }
}

void preOrden(ArbolBinario arbol){
    if(arbol!=NULL){
        cout << arbol->dato <<" ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
//////////////////         MOSTRAR GRAFO 1            ///////////////// 
void mostrarGrafo(ArbolBinario arbol, ofstream &archivo){
    if(arbol!=NULL){
        archivo << arbol->dato <<";"<<endl;
        if(arbol->izq!=NULL){
            archivo <<arbol->dato << " -- " <<arbol->izq->dato<< ";"<<endl;
        }
        if(arbol->der!=NULL){
            archivo <<arbol->dato << " -- " <<arbol->der->dato<<";"<<endl;
        }
        mostrarGrafo(arbol->izq, archivo);
        mostrarGrafo(arbol->der, archivo);
    }
}

void creargrafo(ArbolBinario arbol ){
    ofstream archivo;
    archivo.open("D:\\projects\\Laboratorio ED\\Graphviz\\bin\\T11_ArbolBi1.dot");
    archivo<< "graph G {"<< endl;
    mostrarGrafo(arbol, archivo);
    archivo<<"}";
    archivo.close();
    system("D: & cd Graphviz & cd bin & dot T11_ArbolBi1.dot -o T11_ArbolBi1.dot.png -Tpng & T11_ArbolBi1.dot.png");
}

//////////////////         MOSTRAR GRAFO 2            ///////////////// 

void creargrafo2(ArbolBinario arbol){
    ofstream archivo;
    archivo.open("D:\\projects\\Laboratorio ED\\Graphviz\\bin\\T11_ArbolBi2.dot");
    archivo<< "graph G {"<< endl;
    mostrarGrafo(arbol, archivo);
    archivo<<"}";
    archivo.close();
    system("D: & cd Graphviz & cd bin & dot T11_ArbolBi2.dot -o T11_ArbolBi2.dot.png -Tpng & T11_ArbolBi2.dot.png");
}

//     B                                    ///////////////////////
/*  b) Implementar el siguiente algoritmo y determinar si los arboles de la actividad a) son
        isomorfos.*/

bool ArbolIsomorfo(ArbolBinario arbol1, ArbolBinario arbol2){
    cout<<" arbol comparado "<<arbol1->dato<<" "<<arbol2->dato<<endl; 
    if(arbol1 == NULL && arbol2 == NULL){
        return true;
    }if (arbol1 == NULL || arbol2 == NULL){
        return false;
    }
    return ArbolIsomorfo(arbol1->izq, arbol2->izq) && ArbolIsomorfo(arbol1->der, arbol2->der);
}

int main(){
    ArbolBinario arbol1 = NULL;
    ArbolBinario arbol2 = NULL;
    insertar(arbol1, "v4");
    insertar(arbol1, "v2");
    insertar(arbol1, "v1");
    insertar(arbol1, "v3");

    insertar(arbol2, "w4");
    insertar(arbol2, "w2");
    insertar(arbol2, "w1");
    insertar(arbol2, "w3");

    //insertar(arbol2, "x3");
    //preOrden(arbol2);

    creargrafo(arbol1);
    creargrafo2(arbol2);

    if (ArbolIsomorfo(arbol1, arbol2)){
        cout<<"  >> SON IFOMORFOS  ";
    }else{
        cout<<"  >> NO SON ISOMORFOS  ";
    }
}