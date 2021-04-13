#include<iostream>
#include<stdlib.h>
#include <fstream>

using namespace std;
/*
void leerMA(int **M, int n){
    ifstream f;
	f.open("F:\\Unsa\\S2\\Laboratorio ED\\T3_Practica Matriz.txt");

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			f >> MA[i][j];
	}
	f.close();
}

int aristas(int **MA, int n){
	int suma=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++)
			suma += MA[i][j];
	}
}
*/
void leer(int** mat, int vertices, int aristas) {
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < aristas; j++) {
			cout << "Inserte su digito: ";
			cin >> mat[i][j];
		}
	}
}

void mostrar(int **mat, int vertices, int aristas){
	for(int i=0; i<vertices;i++){
		for(int j=0; j<aristas;j++)
 			cout<<mat[i][j]<<" ";
  		cout<<endl;
 	}
}

int main(){
	/*
    int vertices=6;
	int **MA=new int *[vertices];
	for(int i=0; i<n;i++)
		MA[i]=new int[vertices];

	int aristas(MA, n)
*/
	cout<<"Cuantos vertices tiene su grafo?: ";cin>>vertices;
	cout<<"Cuantas aristas tiene su grafo?: ";cin>>aristas;

	int **mat = new int * [vertices];
	for(int i=0; i<vertices; i++)
		mat[i]=new int[aristas];

	leer(mat, vertices, aristas);

	cout<<"Los datos ingresados fueron"<<endl;
	mostrar(mat, vertices, aristas);
	
 	for(int i=0;i<aristas;i++){
		delete [] mat[i];
	}

	delete [] mat;

	system("PAUSE");
	return 0;
}
