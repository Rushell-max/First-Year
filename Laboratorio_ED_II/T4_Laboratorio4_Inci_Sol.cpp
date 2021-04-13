#include<iostream>
#include<stdlib.h>
#include <fstream>

using namespace std;

void matrizIncidencia(int **MI, int fi, int co){
	
	/*for(int j=0; j<fi-1;j++){
		MI[0][j]=1;
		MI[1][j+1]=1;
		MI[2][j+3]=1;
		MI[3][j+4]=1;
		//MI[2][j+6]=1;
	}
	*/
	for(int i=0; i<fi;i++){
		for(int j=0; j<co;j++){
			MI[i][j]=0;
		}
	}
	
	for(int i=0; i<fi;i++){
		for(int j=0; j<co ; j++){
			MI[i][j]=1;
			if (sumFil(MI, i, co)==fi-1){
				break;
			}
			if(sumaCol(MI, j ,fi)==2){
			break;
			}
		}

	}

	/*if ((sumFil(MI, fi,co)==((fi-1)*fi)) && (sumaCol(MI, fi,co)==(2*co))){
		return MI;
		*/
}

int sumFil(int **MI, int max, int co) {
	int s=0;
	for(int j=0; j<co;j++){
		s += MI[max][j];
	}
	return s;
}

int sumaCol(int **MI, int max, int fi){
	int s=0;
	for(int i=0; i<fi; i++){
		s += MI[i][max];
	}
	return s;
}

void mostrar(int **M, int fi, int co){
	for(int i=0; i<fi; i++){
		for(int j=0; j<co; j++){
 			cout<<M[i][j]<<" ";
		}
  		cout<<endl;
 	}
}

int main(){

	int fi=3;
	//cout<<"Ingrese un número: ";cin>>fi;

	int co =(fi*(fi-1))/2;

 	int **MI=new int *[fi];
	for(int i=0; i<fi;i++)
		MI[i]=new int[co];

	matrizIncidencia(MI, fi, co);

	mostrar(MI, fi, co);
	return 0;
}
