////////////////////// INTEGRANTES /////////////////////////
/*

-ANGIE ALEXANDRA PINO HUARSAYA
-RUSHELL VANESSA ZAVALAGA OROZCO

*////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

///////////////////////       3        ///////////////////////////

/*3. Recuperar el k-ésimo dígito menos significativo de un número natural N.*/

/*
void digi(int k, int n, int cont){
    if( cont+1 == k){
        cout << n%10;
    }else{
        n = n/10;
        cont ++;
        digi(k, n, cont);
    }
}

int main(){
    int k, n;
    int cont = 0;
    cout<<"Ingrese k: "; cin>>k;
    cout<<"Ingrese N: "; cin>>n;
    digi(k, n, cont);
}
*/

///////////////////////       4        /////////////////////////

//4. Sumar los dígitos de un número natural N.

/*
int digi(int n, int cont){
    if(n/10 == 0){
        return n + cont;
    }else{
        cont += n%10;
        digi(n/10, cont);
    }
}

int main(){
    int n;
    int cont = 0;
    cin>>n;
    cout<<digi(n, cont);
}
*/

///////////////////////       6        ///////////////////////

/*6. Construir una función recursiva que imprima la lista de números naturales 
comprendidos entre dos valores a y b dados por el usuario */

/*
int digi(int a, int b){
    if(b == a){
        cout<< a <<" ";
    }else{
        cout<< a <<" ";
        a++;
        digi(a, b);
    }
}

int main(){
    int a, b;
    int cont = 0;
    cin>>a>>b;
    digi(a,b);
}
*/
///////////////////////       11       ///////////////////////

/* 1. Escribir una función recursiva que cuente el número de secuencias de dos 1 
seguidos que hay en una cadena de caracteres que represente un número binario */


int numSE(char *n, int cont, int i){
    if (n[i] == '\0'){
        return cont;
    }else{
        if(n[i] == '1' && n[i+1]== '1'){
            cont++;
        }
        i++;
        numSE(n, cont, i);
    }
}

int main(){
    char num [100];
    int cont = 0;
    int i = 0;
    cin>>num;
    cout<<numSE(num, cont, i);
}
