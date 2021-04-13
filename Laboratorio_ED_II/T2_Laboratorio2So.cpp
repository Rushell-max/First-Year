/* 1. Hacer un programa para calcular el número de
aristas que tiene un grafo completo, dado
como entrada el número de vértices de un grafo.

2. Crear una matriz cuadrada para almacenar la
matriz de adyacencia de un grafo.
*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<conio.h>

using namespace std;
/*1. Hacer un programa para calcular el número de
aristas que tiene un grafo completo, dado
como entrada el número de vértices de un grafo.

int main(){
	int arista, vertice;
	cout<<"Cuantos vertices tiene el grafo?: ";cin>>vertice;
	
	arista=(vertice*(vertice-1))/2;
	cout<<"Tiene "<<arista<<" aristas."<<endl;
	
	system("PAUSE");
	return 0;
	
}

/*
int main(){
	int n, vertices, aristas;
	cout<<"Numero: ";cin>>n;

	int Vec[n];
	int Aris[n];
	for(int i=0; i<n; i++){
		Aris[i]=(n*(n-1))/2;
		cout<<Aris[i];
	}

    system("PAUSE");
	return 0;
}
*/
/*2. Crear una matriz cuadrada para almacenar la
matriz de adyacencia de un grafo.*/

int main(){
	int n;
	cout<<"\nCuantos vertices tiene el grafo: \n";cin>>n;

	//int M[n][n];
	
	int **M=new int *[n]; 
	for(int i=0; i<n;i++)
		M[i]=new int[n];

	int G[n];

    cout<<"\nValores del grafo \n";
	for(int i=0; i<n; i++){
		cout<<"\nValor: \n";cin>>G[i];
	}
	for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
		cout<<"\nExiste alguna relacion entre "<<G[i]<<" y "<<G[j]<<"\n";
		cout<<"En caso exista ingresar 1, sino 0 "<<endl;
		cin>>M[i][j];
    	}
	}
    cout<<endl;

    cout<<"Matriz anidada: "<<endl;
	for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cout<<M[i][j]<<" ";
    	}
    cout<<endl;
	}



    cout<<endl;
	system("PAUSE");
	return 0;
}


