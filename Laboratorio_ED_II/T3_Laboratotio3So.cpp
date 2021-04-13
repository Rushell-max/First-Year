#include<iostream>
#include<stdlib.h>
#include <fstream>

using namespace std;

void leer(int **M, int n){
    ifstream f;
	f.open("F:\\Unsa\\S2\\Laboratorio ED\\T3_Practica Matriz.txt");

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			f >> M[i][j];
	}
	f.close();
}

	
void mostrar(int **M, int n){
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++)
 			cout<<M[i][j]<<" ";
  		cout<<endl;
 	}
}

int valencia(int **M,int n, int i){
	int s=0;
	for(int j=0; j<n; j++){
	    s+=M[i][j];
	}
	cout<<"La valencia de "<<i+1<<" es: "<<s<<endl;
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
	int n=6;
	int **M=new int *[n];
	for(int i=0; i<n;i++)
		M[i]=new int[n];

	int **MC=new int *[n];
	for(int i=0; i<n;i++)
		MC[i]=new int[n];
	leer(M,n);

	cout<<"Los datos ingresados fueron"<<endl;
	mostrar(M, n);

	for(int i=0; i<n;i++)
		valencia(M,n,i);
    cuadrado(M, MC, n);
    mostrar(MC, n);
 	for(int i=0;i<n;i++){
		delete [] M[i];
	}

	delete [] M;

	system("PAUSE");
	return 0;
}
