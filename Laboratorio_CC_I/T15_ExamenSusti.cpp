
#include <iostream>
#include <stdlib.h>

using namespace std;

void leer(int **Ma, int fi,int co){
	cout<<"Ingrese "<<fi*co<<" valores: "<<endl;
	for(int i=0; i<fi;i++){
 		for(int j=0; j<co; j++){
            cout<<"Fila "<<i+1<<" / columna "<<j+1<<": ";cin >>*(*(Ma+i)+j);
        }
    }
}

void mostrar(int **Ma, int fi,int co){
    cout<<"  Mostrando datos: "<<endl;
	for(int i=0; i<fi;i++){
		for(int j=0; j<co;j++)
 			cout<<*(*(Ma+i)+j)<<"  ";
  		cout<<endl;
 	}
}

void DiagPrinc(int **Ma, int fi, int co){
	for(int i=0; i<fi; i++){
		*(*(Ma+i)+i) = 0;
	}
}

void DiagSecun(int **Ma, int fi, int co){
	for(int i=0; i<fi; i++){
		*(*(Ma+i)+co-1) = 0;
		co -= 1;
	}
}

void eliminar(int **Ma, int fi, int co){
    DiagPrinc(Ma, fi, co);
    DiagSecun(Ma, fi, co);
}

void matriz() {
	int fi=3, col=3;
    cout<<" Filas: ";cin>>fi;
    cout<<" Columnas: ";cin>>col;

	int **matriz=new int *[fi]; 
	for(int i=0; i<fi;i++){
		matriz[i]=new int[col];
    }

	leer(matriz, fi, col);
	mostrar(matriz, fi, col);
    eliminar(matriz, fi, col);
    mostrar(matriz, fi, col);

 	for(int i=0;i<fi;i++){
		delete [] matriz[i];
	}

	delete [] matriz;
}

/////////////////////////////////////////////////////////////////////////

class Tiempo{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        Tiempo(int, int, int);

        int getHORA(){ return hora ; }
        int getMINUTO(){ return minuto; }
        int getSEGUNDO(){ return segundo; }

        void mostrar();
        void comparar(Tiempo);
        void sumar(Tiempo);
};

Tiempo :: Tiempo(int a, int b, int c){
    hora = a;
    minuto = b;
    segundo = c;
}

void Tiempo :: mostrar(){
    cout.fill('0');cout.width (2);cout<<hora;
    cout<<" : ";
    cout.fill('0');cout.width (2);cout<<minuto;
    cout<<" : ";
    cout.fill('0');cout.width(2);cout<<segundo<<endl;
}

void Tiempo :: comparar(Tiempo Temp){
    int hora1 = abs(hora - Temp.getHORA());
    int minuto1 = abs(minuto - Temp.getMINUTO());
    int segundo1 = abs(segundo - Temp.getSEGUNDO());
    cout<<" Tienen diferencia de ";
    cout.fill('0');cout.width (2);cout<<hora1;
    cout<<" : ";
    cout.fill('0');cout.width (2);cout<<minuto1;
    cout<<" : ";
    cout.fill('0');cout.width(2);cout<<segundo1<<endl;
}

void Tiempo :: sumar(Tiempo temp){
    int segundo1 = (segundo + temp.getSEGUNDO())%60;
    int minuto1 = (minuto + temp.getMINUTO() + (((segundo + temp.getSEGUNDO())/60)-segundo1/60))%60;
    int hora1 = (hora + temp.getHORA() + (((minuto + temp.getMINUTO())/60)-minuto1/60))%24;
    cout<<" La suma es ";
    cout.fill('0');cout.width (2);cout<<hora1;
    cout<<" : ";
    cout.fill('0');cout.width (2);cout<<minuto1;
    cout<<" : ";
    cout.fill('0');cout.width(2);cout<<segundo1<<endl;
}

void tiempo(){
    Tiempo temp1 = Tiempo(12, 30, 25);
    Tiempo temp2 = Tiempo(15, 32, 36);
    temp1.mostrar();
    temp2.mostrar();

    temp1.comparar(temp2);
    temp1.sumar(temp2);
}

int main(){
    matriz();
    tiempo();
}