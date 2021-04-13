///////////////////// LABORATORIO 5 //////////////////////////
/*9. Copiar el contenido de dos arrays a un tercero.

12. Eliminar un valor de la posición P de un arreglo, 
desplazando los elementos una posición hacia delante 
a partir de la posición donde fue eliminado un elemento 
para que no haya espacios libres entre valores. 

14. Pasar los elementos de un vector a otro, verificando 
que en el segundo vector no queden valores repetidos.*/

///RUSHELL VANESSA ZAVALAGA OROZCO

#include <iostream>
using namespace std;
 
void ingresar(int A[],int n){
    for (int i=0; i<n; i++){
        cin>>A[i];
    }
}

void mostrar(int C[], int n){
    for(int i=0; i<n; i++){
        cout<<C[i]<<" ";
    }
}

// 9
void copiar(int A[], int n, int B[], int n1, int C[]){
    for(int i=0; i<n; i++){
        C[i]=A[i];
    }
    int a=0;
    for (int i=n; i<n+n1; i++){
        C[i]=B[a];
        a++;
    }
}
 
//12
void eliminar(int P, int C[], int n){
    for(int i=P; i<n; i++){
        C[i] = C[i+1];  
    }
}

// 14
bool repeticiones(int C[], int n, int i){
    for(int j=0;j<n;j++){
        if(i == C[j]){
            return true;
        }
    }
    return false;
}

void pasar(int C[], int D[], int n){
    int a = 0;
    for(int i=0; i<n; i++){
        if(!repeticiones(C, i, C[i])){
            D[a] = C[i];
            a++;
        }
    }
}

int pasarTamano(int C[], int D[], int n){
    int a = 0;
    for(int i=0; i<n; i++){
        if(!repeticiones(C, i, C[i])){
            D[a] = C[i];
            a++;
        }
    }
    return a;
}

int main(){
    int n=10;
    int n1=10;
    int A[n], B[n1];
    int C[n+n1];
    int D[10];
    int eliminado;

    cout<<"Cuantos valores ingresara en el primer arreglo? ";cin>>n;
    cout<<"Ingresar valores primer array: ";
    ingresar(A, n);
    cout<<"Cuantos valores ingresara en el primer arreglo? ";cin>>n1;
    cout<<"Ingresar valores segundo array: ";
    ingresar(B, n1);

    //9
    copiar(A, n, B, n1, C);
    cout<<"Mostrando C: ";
    mostrar(C, n+n1);
    cout<<endl;
    
    //12
    cout<<"Posición a eliminar? ";cin>>eliminado;
    eliminar(eliminado-1, C , n+n1);
    cout<<"Mostrando C con el eliminado: ";
    mostrar(C, n+n1-1);

    //14
    pasar(C, D, n+n1-1);
    cout<<"Mostrando D: ";
    mostrar(D, pasarTamano(C, D, n+n1-1));
}