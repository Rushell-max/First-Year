/*/////////////                LABORATORIO 8               /////////////////////////////////////////
    
    -ERICK KLENDORT HUALLA PUELLES 
    -RUSHELL VANESSA ZAVALAGA OROZCO  */

/*////////////////          ACTIVIDADES                    ///////////////////////////////////////

    2. Escribir funciones para crear dinámicamente 2 vectores de enteros de tamaño N, y crear otros
        que guarden la suma, la resta y el producto por un escalar, los muestre y luego los destruya.

    3. Escribir la clase Cola en la cual se implemente una estructura dinámica que permita guardar la
        información de varios pacientes que llegan a un consultorio para ser atendidos. El programa
        debe permitir el registro del paciente en la Cola y también indicar a qué paciente le toca ser
        atendido en un determinado momento.

    4. Escriba una clase y los métodos necesarios para cada una de las tareas pedidas en el siguiente
        problema, utilice asignación dinámica de memoria y notación de punteros.
        Una empresa de consultoría sentimental se encarga de poner en contacto personas que podrían
        tener afinidad para que se conozcan. Para esto tienen un programa en C++ (de miles de líneas
        de código) que se encarga de procesar toda la información sobre los clientes para encontrar
        quiénes podrían entablar una buena relación.
        El programa entrega como resultado, un arreglo de datos enteros de tamaño NPERSONAS
        llamado compatible[ ], en el que en cada posición se guarda un índice para el arreglo de
        personas que indica la persona con que tiene afinidad. (No se almacena el nombre para
        mantener el anonimato).
        Por ejemplo, si compatible[10]=25 quiere decir que a la persona 10 le agradaría la persona 25,
        pero no necesariamente al revés.
        Para terminar el programa, falta escribir las partes que permitan hacer ciertas consultas:
            • Escribir la función que permita encontrar todas las parejas mutuamente compatibles.
            • Escribir la función que encuentre la persona con quien más personas son compatibles.
            • Escribir la función que encuentre aquellas personas con quienes nadie es compatible. 
*/

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//   2        /////////////////////////////////////////////////////////////////////////////////////
/*2. Escribir funciones para crear dinámicamente 2 vectores de enteros de tamaño N, y crear otros
que guarden la suma, la resta y el producto por un escalar, los muestre y luego los destruya.*/

// Función para crear el vector dinámico
void crear(int *&VECTOR, int n){
    VECTOR = new int[n];
}

// Función para ingresar datos al vector dinámico
void leer(int *VECTOR, int n){
	for(int i=0; i<n;i++){
		cout<<"Ingrese un valor: "; cin >>*(VECTOR+i);
	}
}

// Función para mostrar el vector dinámico
void mostrar(int *VECTOR, int n){
    for (int i=0; i<n ; i++){
        cout<<*(VECTOR + i)<<" ";
    } 
    cout<<endl;
}

// Función para la suma de los vectores
void suma(int *PRINC, int *PRINC2, int n){
    int *SUMA;
	crear(SUMA, n);
    for (int i=0; i<n ; i++){
        *(SUMA + i) = *(PRINC + i) + *(PRINC2 + i);
    }
    cout<<"Mostrando suma: "<<endl;
    mostrar(SUMA, n);
    delete [] SUMA;
}

// Función para la resta de los vectores
void resta(int *PRINC, int *PRINC2, int n){
    int *RESTA;
	crear(RESTA, n);
    for (int i=0; i<n ; i++){
        *(RESTA + i) = *(PRINC + i) - *(PRINC2 + i);
    }
    cout<<"Mostrando resta: "<<endl;
    mostrar(RESTA, n);
    delete [] RESTA;
}

// Función para la multiplicación de un vector
void producto(int *PRINC, int n){
    int *PRODUCTO;
    int escalar;
    cout<<"Ingrese un número por el cual multiplicar ";cin>>escalar;
	PRODUCTO = new int[n];
    for(int i=0;i<n;i++){
        *(PRODUCTO+i)=*(PRINC+i)*escalar;
    }
    cout<<"Mostrando producto: "<<endl;
    mostrar(PRODUCTO, n);
    delete [] PRODUCTO;
}

// Función principal del ejercicio 2
void ejercicio2(){
    int n;
    int *PRINC, *PRINC2;
    cout<<"Ingrese n: "; cin>>n;

    crear(PRINC, n);
    cout<<"Valores primer vector "<<endl;
    leer(PRINC, n);


    crear(PRINC2, n);
    cout<<"Valores segundo vector "<<endl;
    leer(PRINC2, n);

    mostrar(PRINC, n);
    mostrar(PRINC2, n);

    suma(PRINC, PRINC2, n);
    resta(PRINC, PRINC2, n);
    producto(PRINC, n);   
}

//   3        /////////////////////////////////////////////////////////////////////////////////////
/* 3. Escribir la clase Cola en la cual se implemente una estructura dinámica que permita guardar la
información de varios pacientes que llegan a un consultorio para ser atendidos. El programa
debe permitir el registro del paciente en la Cola y también indicar a qué paciente le toca ser
atendido en un determinado momento. */

// -Función para mostrar la cola
void menuPacientes(string *&cola,int &pacientes){
    if(pacientes>0){
        for(int i=0;i<pacientes;i++){
            cout<<"\n\tPACIENTE "<<i+1<<": "<<*(cola+i)<<endl;
        }
    }else{
        cout<<"\n\tNO HAY PACIENTES REGISTRADOS "<<endl;}
}

// -Función para registrar a los pacientes
void menuRegistro(string *&cola,int &pacientes){
    int n;
    string *aux;
    cout<<"\n\tCUANTOS PACIENTES SE REGISTRARAN? ";cin>>n;
    if(pacientes>0){
        aux = new string[pacientes];
        for(int i=0;i<pacientes;i++){
            *(aux+i)=*(cola+i);
        }
    }
    pacientes+=n;
    cola=new string[pacientes];

    for(int i=0;i<(pacientes-n);i++){
        *(cola+i)=*(aux+i);
    }
    for(int i=0;i<n;i++){
        cout<<"\n\tINGRESAR NOMBRE DEL PACIENTE "<<i+1<<" : ";cin>>cola[pacientes-n+i];
    }
}

// -Función para mostrar a quien atender
void menuAtender(string *&cola, int &pacientes){
    int resp;
    string *aux;
    cout<<"\n\tATENDER A "<<*(cola)<<"? (S=1/N=0): ";cin>>resp;
    if(resp==1){
        aux = new string[pacientes-1];
        cout<<"\n\tSE ATENDIO A "<<*(cola)<<", GRACIAS POR SU VISITA!!\n"<<endl;
        for(int i=1;i<pacientes;i++){
            *(aux+i-1)=*(cola+i);
        }
        pacientes--;
        cola = new string[pacientes];

        for(int i=0;i<pacientes;i++){
            *(cola+i)=*(aux+i);
        }
    }else{cout<<"\n\tNO SE ATENDIO A NADIE\n";}
}

// Función principal del ejercicio 3
void ejercicio3(){
    bool repite=true;
    int opcion, pacientes=0;
    string *cola=new string[pacientes];

    do{
        cout<<"\n\t\tMENU PRINCIPAL"<<endl;
        cout<<"\n\t1. CONSULTAR LISTA DE PACIENTES (COLA)"<<endl;
        cout<<"\n\t2. AÑADIR NUEVOS PACIENTES"<<endl;
        cout<<"\n\t3. ATENDER AL PRIMER PACIENTE"<<endl;
        cout<<"\n\t0. SALIR"<<endl;

        cout<<"\n\n\tDIGITAR OPCION: ";cin>>opcion;

        switch(opcion){
            case 1:
                menuPacientes(cola,pacientes);
            break;
            case 2:
                menuRegistro(cola,pacientes);
            break;
            case 3:
                menuAtender(cola,pacientes);
            break;
            case 0:
                cout<<"\n\tGRACIAS POR USAR NUESTRO ASISTENTE!!"<<endl;
                repite=false;
            break;
            default:
                cout<<"\n\tLA OPCION DIGITADA NO ES CORRECTA!!"<<endl;
        }
    }while(repite);
    cout<<endl;
}

//   4        /////////////////////////////////////////////////////////////////////////////////////
/* 4. Escriba una clase y los métodos necesarios para cada una de las tareas pedidas en el siguiente
problema, utilice asignación dinámica de memoria y notación de punteros.
Una empresa de consultoría sentimental se encarga de poner en contacto personas que podrían
tener afinidad para que se conozcan. Para esto tienen un programa en C++ (de miles de líneas
de código) que se encarga de procesar toda la información sobre los clientes para encontrar
quiénes podrían entablar una buena relación.
El programa entrega como resultado, un arreglo de datos enteros de tamaño NPERSONAS
llamado compatible[ ], en el que en cada posición se guarda un índice para el arreglo de
personas que indica la persona con que tiene afinidad. (No se almacena el nombre para
mantener el anonimato).
Por ejemplo, si compatible[10]=25 quiere decir que a la persona 10 le agradaría la persona 25,
pero no necesariamente al revés.
Para terminar el programa, falta escribir las partes que permitan hacer ciertas consultas:
• Escribir la función que permita encontrar todas las parejas mutuamente compatibles.
• Escribir la función que encuentre la persona con quien más personas son compatibles.
• Escribir la función que encuentre aquellas personas con quienes nadie es compatible.  */

// Función para ingresar datos
void leer4(int *VECTOR, int n){
	int a;
    for(int i=0; i<n;i++){
		cout<<"Ingresar de quien gusta la persona "<<i+1<<" : "; cin >>a;
        *(VECTOR+i) = a - 1; 
	}
}

// Función para mostrar los datos
void mostrar4(int *VECTOR, int n){
    for (int i=0; i<n ; i++){
        cout<<"Persona "<<i+1<<" gusta de "<<(*(VECTOR + i))+1<<endl;
    }
    cout<<endl;
}

// Función que ayuda a la función encontrar parejas
bool esta(int *VECTOR, int n, int x){
    for(int i=0;i<n;i++)
        if(i==x)
            return true;
    return false;
}

// Función que permita encontrar todas las parejas mutuamente compatibles.
void encontrarParejas(int *VECTOR, int n){
    for (int i=0; i<n ; i++){
        int elem = *(VECTOR+i);
        if(esta(VECTOR, i, elem) == false){
            if (i == *(VECTOR+*(VECTOR+i)) && i != *(VECTOR+i) ){
                cout<<"Pareja compatible "<<i+1<<" con "<<(*(VECTOR+i))+1<<endl;
            }
        }
    }
}

// Función que encuentre la persona con quien más personas son compatibles.
void personaMasCompatible(int *VECTOR, int n){
    int mayor = 0;
    int posicion;
    for(int i=0; i<n; i++){
        int s=0;
        for(int j=0; j<n; j++){
            if(*(VECTOR+i) == *(VECTOR+j) && i!=j ){
                s ++;
            }
        }
        if(s > mayor){
            mayor = s;
            posicion = i;
        }
    }
    if(mayor>0){
        cout<<"La persona mas compatible es "<<(VECTOR[posicion])+1<<" con "<<mayor+1<<" personas que gustan de ella"<<endl;
    }else
        cout<<"No hay persona más compatible que otra. "<<endl;
}

// Función que encuentre aquellas personas con quienes nadie es compatible.
void personasNoCompatibles(int *VECTOR, int n){
    int cont;
    for(int i=0; i<n ; i++){
        cont=0;
        for(int j=0;j<n;j++){
            if(i==*(VECTOR+j)){
                cont++;
            }
        }
        if(cont==0){
            cout<<"Nadie gusta de la persona "<<i+1<<endl;
        }
    }
}

// Función principal del ejercicio 4
void ejercicio4(){
    int n;
    int *Compatible;
    cout<<"Ingrese numero de personas: "; cin>>n;
    crear(Compatible, n);
    leer4(Compatible, n);
    //mostrar4(Compatible, n);    
    cout<<"Encontrando todas las parejas mutuamente compatibles. "<<endl;
    encontrarParejas(Compatible, n);
    cout<<endl;
 
    cout<<"Encontrando la persona con quien más personas son compatibles. "<<endl;
    personaMasCompatible(Compatible, n);
    cout<<endl;

    cout<<"Enconntrando aquellas personas con quienes nadie es compatible. "<<endl;
    personasNoCompatibles(Compatible, n);
    cout<<endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    ejercicio2();
    ejercicio3();
    ejercicio4();
    return 0;
}