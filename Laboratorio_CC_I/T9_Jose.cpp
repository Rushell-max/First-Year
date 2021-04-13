/*
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void crear(int *&VECTOR, int n){
    VECTOR = new int[n];
}

void leer(int *VECTOR, int n){
	for(int i=0; i<n;i++){
		cout<<"Ingrese un valor: "; cin >>*(VECTOR+i);
	}
}

void mostrar(int *VECTOR, int n){
    for (int i=0; i<n ; i++){
        cout<<i<<" a "<<*(VECTOR + i)<<endl;
    } 
    cout<<endl;
}

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

void producto(int *PRINC, int *PRINC2, int n){
    int *PRODUCTO;
	PRODUCTO = new int[n];
    for (int i=0; i<n ; i++){
        *(PRODUCTO + i) = (*(PRINC + i)) * (*(PRINC2 + i));
    }
    cout<<"Mostrando producto: "<<endl;
    mostrar(PRODUCTO, n);
    delete [] PRODUCTO;
}
/*
int main(){
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
    producto(PRINC, PRINC2, n);   
}


void IngresarPacientes(string *&VECTOR, int &n){
    int numpacientes;
    if(n == 0){
        cout<<"Cuantos pacientes ingresara? ";cin>>n;
        for(int i=0; i<n;i++){
		    cout<<"Ingrese nombre: "; cin >>*(VECTOR+i);
        }
    }else{
        cout<<"Cuantos pacientes ingresara? ";cin>>numpacientes;
        for(int j=n; j<numpacientes+n; j++){
            cout<<"Ingrese nombre: "; cin >>*(VECTOR+j);
        }
        n += numpacientes;
    }
}

void letoca(string *&VECTOR, int &n){
    if (n>0){
        cout<<"Le toca a: "<<*(VECTOR);
        *VECTOR++;
        n--;
    }else
        cout<<"No le toca a nadie "<<endl;
}

void mostrarCola(string *VECTOR, int n){
    if (n>0){
        for (int i=0; i<n ; i++){
            cout<<i+1<<" - "<<*(VECTOR + i)<<endl;
        }
        cout<<endl;
    }else{  
        cout<<"La cola esta vacia "<<endl;
        int decision;
        cout<<"Quiere agregar más pacientes?  1/Si   2/No ";cin>>decision;
        if (decision == 1){
            IngresarPacientes(VECTOR, n);
        }
    }
}
/*
int main(){
    int opcion;
    string* COLA = NULL;
    int n = 0;
    
    do{
    cout<<"\t\t\tElija una opcion\n\n";
    cout<<"1  Ingresar pacientes\n";
    cout<<"2  ¿A quien le toca? \n";
    cout<<"3  Ver cola \n";
    cout<<"4  Salir\n\n";
    cin>>opcion;
    
    switch(opcion){
        case 1:
            COLA = new string [100];
            IngresarPacientes(COLA, n);
        break;
        case 2:
            letoca(COLA, n);
        break;
        case 3:
            mostrarCola(COLA, n);
        break;
        case 4: 
            cout<<"Saliendo "<<endl;
        break;
        default: cout<<"El valor ingresado no esta en el menu"<<endl;
    }
    cout<<endl;
    }while(opcion != 4);

}


void leer4(int *VECTOR, int n){
	int a;
    for(int i=0; i<n;i++){
		cout<<"Ingresar de quien gusta la persona "<<i+1<<" : "; cin >>a;
        *(VECTOR+i) = a - 1; 
	}
}

void mostrar4(int *VECTOR, int n){
    for (int i=0; i<n ; i++){
        cout<<"Persona "<<i+1<<" gusta de "<<(*(VECTOR + i))+1<<endl;
    }
    cout<<endl;
}

bool esta(int *VECTOR, int n, int x){
    for(int i=0;i<n;i++)
        if(i==x)
            return true;
    return false;
}
void encontrarParejas(int *VECTOR, int n){
    for (int i=0; i<n ; i++){
        //cout<<"Vector i = "<<i<<" I = "<<*(VECTOR+*(VECTOR+i))<<endl;
        int elem = *(VECTOR+i);
        if(esta(VECTOR, i, elem) == false){
            if (i == *(VECTOR+*(VECTOR+i)) && i != *(VECTOR+i) ){
                cout<<"Pareja compatible "<<i+1<<" con "<<(*(VECTOR+i))+1<<endl;
            }
        }
    }
}
void personaMasCompatible(int *VECTOR, int n){
    int mayor = 0;
    int posicion;
    for(int i=0; i<n; i++){
        int s=0;
        for(int j=0; j<n; j++){
            //cout<<"i: "<<i+1<<" - "<<(*(VECTOR+i))+1<<" J: "<<j+1<<" - "<<(*(VECTOR+j))+1<<endl;
            if(*(VECTOR+i) == *(VECTOR+j) && i!=j ){
                s ++;
            }
        }
        //cout<<" s = "<<s<<endl;
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


int main(){
    int n;
    int *Compatible;
    cout<<"Ingrese n: "; cin>>n;
    crear(Compatible, n);
    leer4(Compatible, n);
    mostrar4(Compatible, n);
    encontrarParejas(Compatible, n);
    personaMasCompatible(Compatible, n);
    personasNoCompatibles(Compatible, n);
    return 0;
}

*/
