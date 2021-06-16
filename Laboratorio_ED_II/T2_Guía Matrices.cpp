#include <iostream>
#include<stdlib.h>
#include <fstream>

using namespace std;

void leer(int Ma[][4], int fi,int co){
	cout<<"Ingrese valores: "<<endl;
	for(int i=0; i<fi;i++){
		for(int j=0; j<co; j++){
			cin >>Ma[i][j];
		}
	}
}

void insertarValores(int Ma[][4], int fi,int co){
    ifstream fichero;
	fichero.open("<UBICACION>");

	for(int i=0; i<fi; i++)
		for(int j=0; j<co; j++){
			fichero >> Ma[i][j];
	}
	fichero.close();
}

void mostrar(int Ma[][4], int fi,int co){
	for(int i=0; i<fi;i++){
		for(int j=0; j<co;j++)
			cout<<Ma[i][j]<<" ";
	cout<<endl;
	}
}

int suma(int Ma[][4], int fi,int co){
	int s=0;
	for(int i=0; i<fi;i++){
		for(int j=0; j<co;j++){
			s=s+Ma[i][j];
		}
	}
	return s;
}

float promedio (int Ma[][4], int fi,int co){
	float supro;
	supro=(float) suma(Ma,fi,co)/(fi*co);
	return (supro);
}

int mayor(int Ma[][4], int fi,int co){
	int may=Ma[0][0];
	for(int i=0; i<fi;i++){
		for(int j=0; j<co;j++){
			if (Ma[i][j]>may){
				may=Ma[i][j];
			}
		}
	}
	return may;
}

void eliminar(int Ma[][4], int fi, int co){
	for(int i=0; i<fi;i++){
		for(int j=0; j<co;j++){
			Ma[i][j]=0;
		}
	}	
}

void duplicar(int Ma[][4], int fi, int co){
	for(int i=0; i<fi;i++){
		for(int j=0; j<co;j++){
			Ma[i][j]*=2;
		}
	}	
}

float SumaDiagonalP(int Ma[][4], int fi, int co){
    float suma = 0;
    for (int i=0 ; i<fi ; i++){
		suma+=Ma[i][i];
    }
    return suma;
}

int main(int argc, char *argv[]) {
	const int fi=4, col=4;
	int matriz[fi][col];
	leer(matriz, fi, col);
	cout<<"Los datos ingresados fueron"<<endl;
	mostrar(matriz, fi, col);
	cout<<endl<<"La suma de los elementos ingresados es: "<<suma(matriz, fi, col)<<endl;
	cout<<"El promedio de sus notas es : "<<promedio(matriz, fi, col)<<endl;
	cout<<"el mayor de los elementos es: "<<mayor(matriz, fi, col)<<endl;
    cout<<"La suma de la diagonal principal es: "<<SumaDiagonalP(matriz, fi, col)<<endl;
	system("PAUSE");
	return 0;
}
