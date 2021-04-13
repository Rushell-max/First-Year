/*//////////////////7   Examen   //////////////////////////////////////////

    -Nombre Completo: RUSHELL VANESSA ZAVALAGA OROZCO 
	-CUI: 20202227	
	-Email (Institucional):  rzavalaga@unsa.edu.pe

*/
/*////////////////          ACTIVIDADES           /////////////////////

	1. (2.5 pts.) Indicar si es Verdadero o Falso (en caso de ser falso, describir de forma correcta).	

        a.  int **p(char*);
            p es una función que recibe un puntero a char y devuelve un puntero a int.

            Falso, p es una función que recibe un puntero a char y devuelve dos punteros a int

        b.  string *p(int,*char);
            p es un puntero a una función que recibe un entero y un puntero a char y devuelve un string.

            Verdadero
	
    2. (2.5 pts.) Describir de forma correcta:

        a.  int*(*p)(int*[10],char**);

            p es un puntero que apunta a una funcion que recibe un array de punteros a int y dos punteros a char, 
            y devuelve un puntero a int.

        b.  int**(*p[10])(char*[],int*)

            p es un array de 10 punteros que apuntan a una funcion que recibe un array de punteros a char y un puntero 
            a int que devuelve dos punteros a int

	3. (7 pts.) Utilizando funciones, vectores dinámicos y notación de punteros, 
        escribir el programa completo para generar 20 números enteros aleatorios entre 1 y 10 e 
        ingresarlos a un vector dinámico. Indicar cuál de los números es el segundo que se repite 
        en más ocasiones.

        Ejemplo:

            Se genera al azar:
                4 2 2 2 2 3 5 7 10 9 8 2 2 2 2 2 1 1 1 1 
        
            El segundo número que se repite más veces es el: 1

    4. (8 ptos.) Escribir la clase Cadena que permita definir varios objetos Cadena con los 
        cuales se pueda guardar el valor del objeto cadena, consultar el valor del objeto, hallar 
        la longitud de la cadena y concatenar o unir dos objetos Cadena (el resultado debe ser otro 
        objeto Cadena). Implementar todo el programa que haga uso de la clase Cadena.

*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

/////////////////////////      3       //////////////////////////////////////

// Función para generar los n numeros aleatorios y guardarlos en un vector
void generarnumeros(int *&Vector, int n){
    srand(time(NULL));
    for(int i=0 ; i<n ; i++){
        *(Vector + i) = rand () % 10;
    }
}

// Función para mostrar Vector
void mostrar(int *Vector, int n){
	for(int i=0; i<n;i++){
		cout<<*(Vector+i)<<" ";
	}
}

// Función complementaria para las repeticiones
bool esta(int *Vector, int n, int x){
    for(int i=0;i<n;i++)
        if(*(Vector+i) == x)
            return true;
    return false;
}

// Función que saca el numero de repeticiones del segundo mayor
void segundoMayor(int *Repeticion, int contRep, int *Valores){
    int mayor = -1;
    int posicion;
    for(int i =0; i<contRep; i++){
        if( *(Repeticion+i) > mayor){
            mayor = *(Repeticion + i);
            posicion = i;
        }
    }
    *(Repeticion + posicion) = -1;
    mayor = -1;
    for(int i =0; i<contRep; i++){
        if( *(Repeticion+i) > mayor){
            mayor = *(Repeticion + i);
            posicion = i;
        }
    }
    cout<<"El segundo número que se repite más veces es el: "<<*(Valores+posicion)<<endl;
}

// Calcula cuantas veces esta repetido un número en el vector
void repeticiones(int *Vector, int n, int *&Repeticion, int *&Valores){
    int contRep = 0;
    for(int i=0;i<n;i++){
        int elem = *(Vector +i);
        if(esta( Vector , i , elem) == false){
            int cont=0;
            for(int j=0;j<n;j++)
                if(elem==*(Vector+j))
                    cont++;
            *(Repeticion + contRep) = cont;
            *(Valores + contRep) = elem;
            contRep++;
            //cout<<elem<<" aparece "<<cont<<" veces"<<endl;
        }
    }
    segundoMayor(Repeticion, contRep, Valores);
}

// FUNCION PRINCIPAL EJERCICIO 3
void ejercicio3(){
    int *vector, n, *repeticion, *valores;
    n = 20;
	vector= new int[n];
    repeticion = new int[n];
    valores = new int[n];

    generarnumeros(vector, n);
    mostrar(vector, n);
    cout<<endl;
    repeticiones(vector, n, repeticion, valores);

}

/////////////////////////      4       //////////////////////////////////////

// Clase cadena
class Cadena{
    private:
        char *cadena = nullptr;
        unsigned int size = 0;

    public:
    Cadena(){
        cadena = nullptr;
        size = 0;
    }
    void setCadena(const char * input){
        size = strlen(input);
        cadena = new char[size + 1];
        strncpy(cadena, input, size+1);
    }
    void printCadena(){
        unsigned int i =0;
        while(cadena[i] != '\0'){
            cout << cadena[i];
            i++;
        }
    }
};

int resul(int(*func)(Cadena), Cadena c1){
    return (*func)(c1);
}

// Halla la longitud
int longitud(Cadena c1){
    int cont = 0;
    while( c1 [cont] != '\0'){
        cont++;
    }
    return cont;
}

// Halla la posicion
int posicion(Cadena c1){
    int i = 0, posicion = 0; 
    char mayor = 'z'; 
    while( c1 [i] != '\0'){
        if (c1[i] <= mayor){
            mayor = c1[i];
            posicion = i;
        }i++;
    }
    return posicion+1;
}

// Combina dos cadenas
Cadena agregar(Cadena c1, Cadena c2){
    cout<<"Ingrese cadena a agregar "; c2.setCadena(); ;
    return c1+c2;
}

// FUNCION PRINCIPAL EJERCICIO 4
void ejerciocio4(){
    int opc;
    Cadena c1, c2;

    cout<<"Ingrese cadena: "; c1.setCadena(); 
    cout<<"\nIntroduzca        0:Longitud,    1:Posicion,     2: Agregar cadena   ";cin>>opc;

    if(opc==0)
        cout<<resul(longitud, c1);
    else if(opc==1)
        cout<<resul(posicion, c1);
    else if(opc==2)
        cout<<agregar(c1, c2);
    
}


//////////////////////////////////////////////////////////////////////////////////////////7
int main(){
    ejercicio3();
    ejerciocio4();
}