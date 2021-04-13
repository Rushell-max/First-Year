#include<iostream>
#include<stdlib.h>
#include <fstream>

using namespace std;

void leer(int **M, int n){
    ifstream matriz;
	matriz.open("F:\\Unsa\\S2\\Laboratorio ED\\T4_Practica Matriz2.txt");

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

void cuadrado(int **M, int **MC, int n){
    int s = 0;
    for(int i=0; i<n;i++){
         for(int j=0; j<n; j++){
             for(int k=0; k<n; k++){
                s+=M[i][k]*M[k][j];
            }
            MC[i][j]=s;
            s=0;
        }
    }
}

int main(){

/////A
	int n=5;
	int **M=new int *[n];
	for(int i=0; i<n;i++)
		M[i]=new int[n];
		
    int **MC=new int *[n];
	for(int i=0; i<n;i++)
		MC[i]=new int[n];
		
    int **MAC=new int *[n];
	for(int i=0; i<n;i++)
		MAC[i]=new int[n];
		
	leer(M,n);
	cout<<"Los datos ingresados fueron"<<endl;
	mostrar(M, n);
	cout<<endl;
	
	cuadrado(M, MC, n);
	mostrar(MC, n);
	cout<<endl;
	cuadrado(MC, MAC, n);
	mostrar(MAC, n);
    cout<<endl;
	system("PAUSE");
	return 0;
}
