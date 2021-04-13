#include <iostream>
#include<stdlib.h>

using namespace std;

void leer(int **Ma, int fi,int co){
	cout<<"Ingrese "<<fi*co<<" valores: "<<endl;
	for(int i=0; i<fi;i++)
 		for(int j=0; j<co; j++)
			cin >>Ma[i][j];
}

void mostrar(int **Ma, int fi,int co){
	for(int i=0; i<fi;i++){
		for(int j=0; j<co;j++)
 			cout<<Ma[i][j]<<" ";
  		cout<<endl;
 	}
}

int suma(int **Ma, int fi,int co){
	int s=0;
 	for(int i=0; i<fi;i++)
 		for(int j=0; j<co;j++)
 			s=s+Ma[i][j];
	return s;
}

float promedio (int **Ma, int fi,int co){
	float supro;
	supro=(float) suma(Ma,fi,co)/(fi*co);
	return (supro);
}

int mayor(int **Ma, int fi,int co){
	int may=Ma[0][0];
 	for(int i=0; i<fi;i++)
 		for(int j=0; j<co;j++){
			if (Ma[i][j]>may)
 				may=Ma[i][j];}
 	return may;
}

int sumaDiagPrinc(int **Ma, int fi, int co){
	int s=0;
	for(int i=0; i<fi; i++){
		s += Ma[i][i];
	}
	return s;
}

int sumaDiagSecun(int **Ma, int fi, int co){
	int s=0;
	for(int i=0; i<fi; i++){
		s += Ma[i][co-1];
		co -= 1;
	}
	return s;
}

int main(int argc, char *argv[]) {
	int fi=3, col=3;
	//int matriz[fi][col];

	int **matriz=new int *[fi]; //puntero que apunta a un array de punteros
	for(int i=0; i<fi;i++)
		matriz[i]=new int[col];
////////////

	leer(matriz, fi, col);
	cout<<"Los datos ingresados fueron"<<endl;
	mostrar(matriz, fi, col);
	cout<<endl<<"La suma de los elementos ingresados es: "<<suma(matriz, fi, col)<<endl;
	cout<<"El promedio de sus notas es : "<<promedio(matriz, fi, col)<<endl;
	cout<<"el mayor de los elementos es: "<<mayor(matriz, fi, col)<<endl;
    cout<<"La suma de la diag. principal es: "<<sumaDiagPrinc(matriz, fi, col)<<endl;
    cout<<"La suma de la diag. secundaria es: "<<sumaDiagSecun(matriz, fi, col)<<endl;

 	for(int i=0;i<fi;i++){
		delete [] matriz[i];
	}

	delete [] matriz;

	system("PAUSE");
	return 0;
}
