/*//////////////   LABORATORIO 10   //////////////////////////////

    -RUSHELL VANESSA ZAVALAGA OROZCO 

*/

/*////////////////          ACTIVIDADES                    ///////////////////////////////////////

	4) Escriba un programa que realice las cuatro operaciones aritméticas 
        fundamentales a través de un array de punteros a funciones.

    5) Escriba el programa que a través de punteros a funciones halle la suma
        de los elementos de las posiciones pares y el producto de las posiciones
        impares de un vector dinámico de enteros.

    6) Escriba un programa que a través de punteros a funciones halle la suma de
        los elementos de la fila x y el producto de la columna y de una matriz 
        dinámica de enteros.

    7) Escriba un programa que a través de punteros a funciones halle la longitud
        de una cadena y la posición en la que se encuentra el carácter mayor en 
        orden lexicográfico.

*/

#include <iostream>

using namespace std;

//     4                                    ///////////////////////
/* 	4) Escriba un programa que realice las cuatro operaciones aritméticas 
        fundamentales a través de un array de punteros a funciones. */

float suma(float a, float b){
    return a+b;
}

float resta(float a, float b){
    return a-b;
}

float multiplicacion(float a, float b){
    return a*b;
}

float division(float a, float b){
    return a/b;
}

void ejercicio4(){
    cout<<"\n //     4    /////////////////////////////////////////////////////// \n";
    float (*f[4])(float, float)={suma , resta , multiplicacion, division};
    int a, b;
    cout<<"\n    INTRODUZCA A y B >> . . . " <<endl;
    cout<<"      A . . . >> "; cin>>a;
    cout<<"      B . . . >> "; cin>>b;

    cout<<"\n    RESULTADO SUMA >> "<< (*f[0])(a , b);
    cout<<"\n    RESULTADO RESTA >> "<< (*f[1])(a , b);
    cout<<"\n    RESULTADO MULTIPLICACION >> "<< (*f[2])(a , b);
    cout<<"\n    RESULTADO DIVISION >> "<< (*f[3])(a , b)<<endl;
}

//     5                                    ///////////////////////
/*  5) Escriba el programa que a través de punteros a funciones halle la suma
        de los elementos de las posiciones pares y el producto de las posiciones
        impares de un vector dinámico de enteros.*/

void leerVector(int *V, int t){
	for(int i=0; i<t; i++){
		cout<<"       INGRESAR VALOR "<<i+1<<" >>  "; cin >>*(V+i);
	}
}

int sumaPares(int *V, int tam){
    int suma = 0;
    for(int i=1; i<tam; i+=2){
        suma += *(V + i);
    }
    return suma;
}

int productoImpares(int *V, int tam){
    int producto = 1;
    for(int i=0;  i < tam; i += 2){
        producto *=  *(V + i);
    }
    return producto;  
}

void ejercicio5(){
    cout<<"\n //     5    /////////////////////////////////////////////////////// \n";
	int ta;
	cout<<"\n    INGRESE EL TAMAÑO DEL VECTOR >> . . . "; cin >>ta;
	int *vector;
	vector= new int[ta];

    leerVector(vector, ta);

    int (*p)(int *V, int tam) = {sumaPares};
    int (*p1)(int *V, int tam) = {productoImpares};

    cout<<"\n      RESULTADO SUMA PARES >> "<< (*p)(vector , ta);
    cout<<"\n      RESULTADO PRODUCTO IMPARES >> "<< (*p1)(vector , ta)<<endl;

    delete[] vector;
}

//     6                                    ///////////////////////
/*  6) Escriba un programa que a través de punteros a funciones halle la suma de
        los elementos de la fila x y el producto de la columna y de una matriz 
        dinámica de enteros.*/

void leerMatriz(int **&M, int filas, int columnas){ 
    cout<<"\n    INGRESANDO MATRIZ >> . . . "<<endl;
    for(int i = 0; i < filas; i++){
        cout<<"      FILA "<< i+1 <<" >> "<<endl;
        for(int j = 0; j < columnas; j++){
            cout<<"      COLUMNA "<< j+1 <<" >> ";cin>>*(*(M+i)+j);
        }
    }
}

void mostrarMatriz(int **M, int fi, int col){ 
    cout<<"\n    MOSTRANDO MATRIZ >> . . . "<<endl;
    for(int i = 0 ; i < fi ; i++){ 
        for(int j = 0 ; j < col ; j++)
            cout<<"      "<<*(*(M+i)+j)<<"\t";
        cout<<"\n";
    }
}

int sumaFilaX(int **Matriz, int columnas, int x){
    int suma = 0;
    for(int i = 0; i < columnas; i++){
        suma += *(*(Matriz+x)+i); 
    }
    return suma;
}

int productoColumnaY(int **Matriz,  int filas, int y){
    int producto = 1;
    for(int i = 0; i < filas; i++){
        producto *= *(*(Matriz+i)+y); 
    }
    return producto;
}

void ejercicio6(){
    cout<<"\n //     6    /////////////////////////////////////////////////////// \n";
	int filas, columnas, x, y;
	cout<<"\n    INGRESE EL NUMERO DE FILAS DE LA MATRIZ >> . . . "; cin >>filas;
    cout<<"    INGRESE EL NUMERO DE COLUMNAS DE LA MATRIZ >> . . . "; cin >>columnas;
    cout<<endl;

	int **matriz=new int *[filas];
	for(int i=0; i<filas ;i++)
		matriz[i]=new int[columnas];

    leerMatriz(matriz, filas, columnas);
    mostrarMatriz(matriz, filas, columnas);

	cout<<"\n    INGRESE FILA A SUMAR (x) >> . . . "; cin >>x;
    cout<<"    INGRESE COLUMNA A MULTIPLICAR (y) >> . . . "; cin >>y;
    x--; y--;

    int (*p)(int **matriz, int columnas,  int x) = {sumaFilaX};
    int (*p1)(int **matriz,  int filas, int y) = {productoColumnaY}; 

    cout<<"\n    RESULTADO SUMA FILA "<<x+1<<" >> "<< (*p)(matriz , columnas, x);
    cout<<"\n    RESULTADO PRODUCTO COLUMNA "<<y+1<<" >> "<< (*p1)(matriz, filas, y)<<endl;

 	for(int i=0;i<filas ;i++){
		delete [] matriz[i];
	}

	delete [] matriz;

}

//     7                                    ///////////////////////
/*  7) Escriba un programa que a través de punteros a funciones halle la longitud
        de una cadena y la posición en la que se encuentra el carácter mayor en 
        orden lexicográfico.*/

int longitud(char *cadena, int i){
    if (cadena[i] == '\0'){
        return i;
    }else{
        i++;
        longitud(cadena, i);
    }
}

int posicion(char *cadena){
    int i = 0, posicion = 0; 
    char mayor = 'z'; 
    while( cadena [i] != '\0'){
        if (cadena[i] <= mayor){
            mayor = cadena[i];
            posicion = i;
        }i++;
    }
    return posicion+1;
}

void ejercicio7(){
    cout<<"\n //     7    /////////////////////////////////////////////////////// \n";
    char cadena[100];
    int i = 0;
    cout<<"\n    INGRESE CADENA >> . . . ";cin>>cadena;

    int (*p)(char *cadena, int i) = {longitud};
    int (*p1)(char *cadena) = {posicion};

    cout<<"\n    LONGITUD >> "<<(*p)(cadena, i);
    cout<<"\n    POSICION EN LA QUE SE ENCUENTRA EL CARACTER MAYOR EN ORDEN LEXICOGRÁFICO >> "<<(*p1)(cadena)<<endl;
    cout<<endl;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
int main(){
    ejercicio4();
    ejercicio5();
    ejercicio6();
    ejercicio7();
}
