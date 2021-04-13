#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
/*
struct nodo{
    int nro;
    struct nodo *izq, *der, *medio;
};

typedef struct nodo *Arbol;

void insertarIzquierdo(Arbol &padre,int nro){
    if(padre->izq==NULL){
        padre->izq->nro=nro;
    }else{
        ordenar(padre->izq,nro);
    }
}

void insertarDerecho(Arbol &padre,int nro){
    if(padre->der==NULL){
        padre->der->nro = nro;
    }else{ 
        ordenar(padre->der,nro);
    }
}

void insertarMedio(Arbol &padre,int nro){
    if(padre->medio == NULL){
        padre->medio->nro = nro;
    }else{
        ordenar(padre->medio,nro);
    }
}

void ordenar(Arbol &padre,int nro){
    if(padre->nro < nro){
        insertarDerecho(padre,nro);}
    else if(padre->nro > nro){
        insertarIzquierdo(padre,nro);}
    else{
        insertarMedio(padre,nro);}
}
*/
int division (int a, int b, int cont) {
    if(b > a) {
         return cont;
    }
    else {
        return division(a-b, b, cont+1) ;
    }
}

int main(){
    
    /*int padre, valorNodo;
    Arbol Arbol=NULL;
    cout<<"Ingresar nro del arbol padre: ";cin>>padre;
    crearArbol(Arbol,padre);

    ordenar(Arbol,valorNodo);
*/
    cout<<division(100,5,0);
    return 0;
}