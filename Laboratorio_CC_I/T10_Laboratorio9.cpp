/*/////////////                LABORATORIO 9               /////////////////////////////////////////
    
    -RUSHELL VANESSA ZAVALAGA OROZCO  */

/*////////////////          ACTIVIDADES                    ///////////////////////////////////////

    6. Generar una matriz dinámica que cumpla con el siguiente patrón, por ejemplo si la matriz 
        es de 4x4, será:
                    0   1   2   3
                    1   2   3   0
                A = 2   3   0   1
                    3   0   1   2

    7. Verificar si una matriz es cuadrado mágico.

    8. Cambiar la forma de de una matriz, manteniendo el orden (por filas) de sus elementos. 
*/

#include <iostream>

using namespace std;

// Función crear matriz
void crear_matriz(int**&M, int fi, int col){
    M = new int*[fi];
    for(int i=0;i<fi;i++)
        M[i]=new int[col];
}

// Función de ingreso de datos
void llenar(int **&M, int fi, int col){ 
    for(int i = 0; i < fi; i++)
        for(int j = 0; j < col; j++)
            cin>>*(*(M+i)+j);
}

// Función de impresión de datos
void mostrar(int **M, int fi, int col){ 
    for(int i = 0 ; i < fi ; i++){ 
        for(int j = 0 ; j < col ; j++)
            cout<<*(*(M+i)+j)<<"\t";
        cout<<"\n";
    }
}

// Función para eliminar matriz
void borrar(int **&M, int fi){
    for(int i=0; i<fi; i++)
        delete [] M[i];
    delete [] M;
}

// 6.    //////////////////////////////////////////////////////////////////
/*    6. Generar una matriz dinámica que cumpla con el siguiente patrón, por ejemplo si 
    la matriz es de 4x4, será:
                    0   1   2   3
                    1   2   3   0
                A = 2   3   0   1
                    3   0   1   2
*/

void patron(int **&M, int fi, int col){
    int k = 0;
    for(int i = 0 ; i < fi ; i++){
        k = i;
        for(int j = 0 ; j < col ; j ++){
            if(k < fi){
                *(*(M+i)+j) = k;
                k++;
            }else{
                k = 0;
                *(*(M+i)+j) = k;
                k++;
            }
        }
    }
}

void ejercicio6(int fi, int col){
    int **M;
    crear_matriz(M, fi, col);
    patron(M, fi, col);

    cout<<"\n>> MOSTRANDO MATRIZ :  \n"; 
    mostrar(M, fi, col);

    borrar(M, fi);
}

// 7.    //////////////////////////////////////////////////////////////////
//  7. Verificar si una matriz es cuadrado mágico.

//Se extrae el valor
int sumaDiagPrinc(int **&M, int fi){
	int suma=0;
	for(int i=0; i<fi; i++){
		suma += *(*(M+i)+i);
	}
    return suma;
}

// Bool para verificar si las sumas de las filas son iguales al valor
bool sFilasI(int **&M, int fi, int col, int valor){
    int suma;
    for(int i = 0 ; i < fi ; i++){ 
        suma = 0; 
        for(int j = 0 ; j < col ; j++){
            suma += *(*(M+i)+j);
        }
        if (suma != valor){
            return false;
        }
    }
    return true;
}

// Bool para verificar si las sumas de las columnas son iguales al valor
bool sColumnasI(int **&M, int fi, int col,int valor){
    int suma;
    for(int i = 0 ; i < fi ; i++){ 
        suma = 0; 
        for(int j = 0 ; j < col ; j++){
            suma += *(*(M+i)+j);
        }
        if (suma != valor){
            return false;
        }
    }
    return true;
}

// Bool para verificar si las suma de la diagonal secundaria es igual al valor
bool sumaDiagSecun(int **&M, int fi, int col , int valor){
	int suma=0;
	for(int i=0; i<fi; i++){
		suma += *(*(M+i)+(col-1));
		col -= 1;
	}
	if (suma == valor){
        return true; 
    }return false;
}

//Función principal ejercicio 7
void cuadradoMag(int **&M, int fi, int col){
    int valor = sumaDiagPrinc(M, fi);
    if(sFilasI(M, fi, col, valor) && sColumnasI(M, fi, col, valor) && sumaDiagSecun(M, fi, col, valor)){
        cout<<"Es un cuadrado mágico "<<endl;
    }else{
        cout<<"No es un cuadrado mágico :/ "<<endl;
    }
}

void ejercicio7(int fi, int col){
    int **M;
    crear_matriz(M, fi, col);

    llenar(M, fi, col);

    cout<<"\n>> MOSTRANDO MATRIZ :  \n"; 
    mostrar(M, fi, col);

    cuadradoMag(M, fi, col);

    borrar(M, fi);
}

// 8.    //////////////////////////////////////////////////////////////////
// 8. Cambiar la forma de de una matriz, manteniendo el orden (por filas) de sus elementos. 

// Funcion que verifica si pxq = mxn
bool verificar(int fi, int col, int p, int q){
    if((fi*col) == (p*q)){
        return true;
    }
    return false;
}

// Funcion que llena en un vector la matriz
void llenarVector(int **M, int *&Vector, int fi, int col){
    int cont = 0;
    for(int i = 0; i < fi; i++){
        for(int j = 0; j < col; j++ ){
            *(Vector+cont) = *(*(M+i)+j);
            cont++;
        }
    }
}

// Función que ingresa datos a la matriz que se dara
void ordenar(int *&Vector, int **&M2, int p, int q){
    int cont = 0;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++ ){
            *(*(M2+i)+j)= *(Vector+cont);
            cont++; 
        }
    }
}

// Función principal del ejercicio 8
void ejercicio8(int fi, int col){
    int **M, p, q, **M2, *Vector;
    Vector= new int[fi*col];

    crear_matriz(M, fi, col);
    cout<<"\n>> LLENANDO MATRIZ:  \n"; 
    llenar(M, fi, col);

    do{
        cout<<">> INGRESE FILAS: ";cin>>p;
        cout<<">> INGRESE COLUMNAS :  ";cin>>q; 
    }while(!verificar(fi, col, p, q));

    llenarVector(M, Vector, fi, col);

    crear_matriz(M2, p, q);
    ordenar(Vector, M2, p, q);

    cout<<"\n>> MOSTRANDO MATRIZ ORIGINAL:  \n"; 
    mostrar(M, fi, col);

    cout<<"\n>> MOSTRANDO MATRIZ CON CAMBIOS:  \n"; 
    mostrar(M2, p, q);

    borrar(M, fi);
    borrar(M2, p);
}

//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
int main(){ 
    int fi, col;
    cout<<">> INGRESE FILAS: ";cin>>fi;
    cout<<">> INGRESE COLUMNAS :  ";cin>>col;

    //ejercicio6(fi, col);
    //ejercicio7(fi, col);
    ejercicio8(fi, col);
    return 0;
}
