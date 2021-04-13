#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

int **crearGrafo(){
    int vertic_max=20;
    int **grafo=new int *[vertic_max];
    for(int i=0; i<vertic_max;i++){
        grafo[i]=new int[2];
    }
    for(int i=0; i<vertic_max; i++){
        for( int j=0; j<vertic_max; j++){
            grafo[i][j]=0;
        }
    }
    return grafo;
}

int lugar(int** grafo){
    int lugar = 0;
    for(int i=0;i<20;i++){
        if(grafo[i][0]==0){
            lugar = i;
            return lugar;
        }
    }
}

void insertVert(int **grafo, int v){
    grafo[lugar(grafo)][0] = v;
}

void insertAris(int **grafo, int v1, int v2){
    bool encontro = false;

    for(int i=0; i<20; i++){
        if(grafo[i][0] == v1 && grafo[i][1] == 0){
            grafo[i][1] = v2;
            encontro = true;
            break;
        }
   }
    if(!encontro){
            //cout<<"ingresando"<<endl;
            int position = lugar(grafo);
            grafo[position][0]=v1;
            grafo[position][1]=v2;
    }

}


void eliminVert(int **grafo, int v1){
    for(int i=0; i<20; i++){
        if(grafo[i][0]==v1){
            grafo[i][0]=0;
            grafo[i][1]=0;
        }
    }
}

void eliminAris(int **grafo, int v1, int v2){
    for(int h=0; h<20; h++){
        if(grafo[h][0] == v1 && grafo[h][1] == v2){
            grafo[h][1] = 0;
            break;
        }
    }
}

bool vacio(int **grafo){
    int cont = 0;
    for (int i=0; i<20; i++){
        if(grafo[i][0]==0 && grafo[i][1] == 0){
            cont++;
        }
    }
    if(cont == 20){
        return true;
    }else
        return false;
}

int *adyacente(int **grafo, int v1){
    int *adya;
    adya = new int[20];

    for(int i=0; i<20; i++){
        adya[i] = 0;
    }

    for(int i=0; i<20; i++){
        if(grafo[i][0] == v1 && grafo[i][1]!=0){
            adya[i] = grafo[i][1];
        }else
            if(grafo[i][1] == v1){
                adya[i] = grafo[i][0];
            }
    }
    return adya;
}

void verGraf(int **grafo){
    ofstream archivo;
    archivo.open("D:\\Graphviz\\bin\\T3B_Grafo.dot");
    archivo<< "graph G {"<< endl;
    cout<<"mostrando grafo"<<endl;
    for(int i=0; i<20; i++){
        if(grafo[i][0] != 0 && grafo[i][1] != 0){
            cout << grafo[i][0] << " -- "<< grafo[i][1]<<";"<<endl;
            archivo << grafo[i][0] << " -- "<< grafo[i][1]<<";"<<endl;
        }
        if(grafo[i][0] != 0 && grafo[i][1] == 0){
            cout << grafo[i][0] << " -- "<< grafo[i][1]<<";"<<endl;
            archivo << grafo[i][0] << ";"<<endl;
        }
    }
    archivo << "}";
    archivo.close();
    system("D: & cd Graphviz & cd bin & dot T3B_Grafo.dot -o T3B_Grafo.png -Tpng & T3B_Grafo.png");
}

void mostrarAd(int *adya){
    for(int i=0; i<20; i++){
        if(adya[i]!=0){
            cout<<adya[i]<<" ";
        }
    }
}
int main(){
    int inp=0;
    int vertic_max=20;
    int **grafo=new int *[vertic_max];
    for(int i=0; i<vertic_max;i++){
        grafo[i]=new int[2];
    }
    int *adya;
    adya = new int[20];

    grafo = crearGrafo();
    if (vacio(grafo)){
        cout<<"El grafo esta vacio "<<endl;
    }else{
        cout<<"El grafo no esta vacio "<<endl;
    }
    insertVert(grafo, 5);
    insertVert(grafo, 7);
    insertVert(grafo, 1);
    insertVert(grafo, 3);
    insertVert(grafo, 2);
    insertVert(grafo, 4);
     verGraf(grafo);
    insertAris(grafo, 5, 1);
    insertAris(grafo, 5, 3);
    insertAris(grafo, 5, 7);
    insertAris(grafo, 7, 1);
    insertAris(grafo,4,1);
    verGraf(grafo);
    adya = adyacente(grafo, 5);
    cout<<"Mostrando adyacencia: "<<endl;
    mostrarAd(adya);
    cout<<endl;

    eliminAris(grafo, 7, 1);
    eliminAris(grafo,4,1);
    verGraf(grafo);
    eliminVert(grafo, 4);
    eliminVert(grafo, 5);
    verGraf(grafo);
    if (vacio(grafo)){
        cout<<"El grafo esta vacio "<<endl;
    }else{
        cout<<"El grafo no esta vacio "<<endl;
    }


    for(int i=0;i<vertic_max;i++){
        delete [] grafo[i];
    }
    delete [] grafo;
    delete [] adya;

    return 0;
}
