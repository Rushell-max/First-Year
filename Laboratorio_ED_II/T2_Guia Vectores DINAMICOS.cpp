#include <iostream>
#include<stdlib.h>
#include <fstream>

using namespace std;

void leer(int *V, int t){
	for(int i=0; i<t;i++){
		cout<<"Ingrese un valor"; cin >>V[i];
	}
}

void mostrar(int *V, int t){
	for(int i=0; i<t;i++){
		cout<<V[i]<<" ";
	}
}

int suma(int *V, int t){
	int s=0;
	for(int j=0; j<t; j++){
		s=s+V[j];
	}
	return s;
}

int aprobado(int *V, int t){
	int s=0;
	for(int i=0; i<t; i++){
		if(V[i]>=11){
			s++;
		}
	}
	return s;
}


float promedio (int *V,int t){
	float supro;
	supro=(float) suma(V,t)/t;
	return (supro);
}

int mayor(int *V, int t){
	int may=V[0];
 	for(int i=0;i<t;i++){
		if (V[i]>may)
			may=V[i];}
 	return may;
}

int menor(int *V, int t){
	int men=V[0];
 	for(int i=0;i<t;i++){
		if (V[i]<men)
			men=V[i];}
 	return men;
}

int desaprobado(int *V, int t){
	int s=0;
	for(int i=0; i<t; i++){
		if(V[i]<11){
			s++;
		}
	}
	return s;
}


int main(int argc, char *argv[]) {
	int ta;
	cout<<"Ingrese el tamaño:"; cin >>ta;

	//PUNTEROO
	/*int *vector;
	vector= new int[ta];
*/

	//FICHEROS
	/*int vector[ta];
	ifstream f;

	f.open("F:\\Unsa\\S2\\Laboratorio ED\\T2_Practica Vector.txt");

	for(int i=0; i<ta; i++){
		f >> vector[i];
	}
 */
	cout<<"Los datos ingresados fueron"<<endl;
	mostrar(vector, ta);

	cout<<endl<<"La suma de los elementos ingresados es: "<<suma(vector, ta)<<endl;
	cout<<"El promedio de sus notas es : "<<promedio(vector, ta)<<endl;
	cout<<"el mayor de los elementos es: "<<mayor(vector, ta)<<endl;
    cout<<"el menor de los elementos es: "<<menor(vector, ta)<<endl;
    cout<<"El número de aprobados es : "<<aprobado(vector, ta)<<endl;
    cout<<"El número de desaprobados es : "<<desaprobado(vector, ta)<<endl;

	//PUNTERO
	//delete [] vector;
	
	//FICHERO
	//f.close();
	system("PAUSE");
	return 0;
}
