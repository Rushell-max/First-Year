#include<iostream>
#include<stdlib.h>
#include <fstream>

using namespace std;

void leer(int **M, int n){
    ifstream matriz;
	matriz.open("F:\\Unsa\\S2\\Laboratorio ED\\T4_Practica Matriz.txt");

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			matriz >> M[i][j];
	}
	matriz.close();
}

void leerG(int **M, int n){
    ifstream matriz;
	matriz.open("F:\\Unsa\\S2\\Laboratorio ED\\T4_Practica MatrizSG.txt");

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			matriz >> M[i][j];
	}
	matriz.close();
}

void mostrar(int **M, int n){
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++)
 			cout<<M[i][j]<<" ";
  		cout<<endl;
 	}
}

void complemento(int **M, int **MC, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if( M[i][j] == 1){
				MC[i][j] = 0;
			}else
			if( M[i][j] == 0){
				MC[i][j] = 1;
			}
			MC[i][i]=0;
		}
	}
}

void grafo(int **M, int n){
    ofstream grafo;
    grafo.open("D:\\Graphviz\\bin\\Grafo1.dot");
    grafo << "graph G{ " << endl;
	for(int i=0; i<n;i++){
		for(int j=0; j<i;j++){
			if(M[i][j]==1){
				grafo << i+1<< " -- " << j+1 <<";"<< endl;
			}
 		}
	}
	grafo << "}";
	grafo.close();
	system("D: & cd Graphviz & cd bin & dot Grafo1.dot -o Grafo1.png -Tpng & Grafo1.png");
}

int Subgrafo(int **M, int **MSG, int *verticesV, int vertices){
	int s = 0, a, b;
	for(int i=0; i<vertices; i++){
		for(int j=0; j<vertices; j++){
            a = (verticesV[i]);
            b = (verticesV[j]);
			if( M[a-1][b-1] == MSG[i][j]){
				s++;
			}
		}
	}
	if (s == vertices*vertices){
		return 1;
	}else
	    return 0;
}

int main(){

/////A
	int n=5;
	int **M=new int *[n];
	for(int i=0; i<n;i++)
		M[i]=new int[n];
		
	leer(M,n);
	cout<<"Los datos ingresados fueron"<<endl;
	mostrar(M, n);

    //grafo(M, n);
    
/////B
	int s=5;
	int **MC=new int *[s];
	for(int i=0; i<s;i++)
		MC[i]=new int[s];
	complemento(M,MC,n);
	cout<<endl;
	cout<<"La matriz complemento "<<endl;
	mostrar(MC, n);
	//grafo(MC, n);
	cout<<endl;

//////C

	int vertices;
	cout<<"Cuantos vertices tiene el subgrafo ingresado? ";cin>>vertices;
	cout<<endl;

	int **MSG=new int *[vertices];
	for(int i=0; i<vertices;i++)
		MSG[i]=new int[vertices];

	leerG(MSG, vertices);

	int *verticesV;
	verticesV = new int[vertices];

    cout<<"Cuales son los vertices del grafo ingresado? "<<endl;
    
	for(int i=0; i<vertices; i++){
		cout<<"Valor: ";cin>>verticesV[i];
	}
	if(Subgrafo(M, MSG, verticesV, vertices) == 1){
		cout<<"El grafo ingresado si es subgrafo de G ";
	}else
	    cout<<"El grafo ingresado no es subgrafo de G ";

	grafo(MSG, vertices);
    cout<<endl;

/////
 	for(int i=0;i<n;i++){
		delete [] M[i];
	}
	delete [] M;
	delete [] verticesV;

	return 0;
}
