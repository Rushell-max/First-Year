#include <iostream>
#include <math.h>

using namespace std;
///////////////            1         ////////////////////////////////////////////////
/*
bool isCommonDivisor(int a, int b, int c){
    if((b % a == 0) && (c % a == 0)){
        return true;
    }
    else{
        return false;
    }
}
*/
///////////////     1B     /////////////////////////////////////////////////////
/*
bool isCommoMult(int a, int b, int c){
    if((a % b == 0) && (a % c ==0)){
        return true;
    }
    else{
        return false;
    }
}
*/
///////////////     1C      /////////////////////////////////////////////////////
/*
int swap(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

int main(){
    int a, b;
    cout<<"Ingrese dos valores: ";cin>>a;cin>>b;
    swap(a, b);
    cout<<a<<" "<<b;
}
*/
///////////////         2            /////////////////////////////////////////////////
/*
float tempMedia(float max, float min){
    return (max + min)/2;
}

int main(){
    float max, min;
    int dias;
    cout<<"Cuantos dias ingresara?: ";cin>>dias;
    cout<<endl;

    for(int i=0; i<dias; i++){
        cout<<"Temperatura máxima: ";cin>>max;
        cout<<"Temperatura minima: ";cin>>min;
        cout<<endl;
        cout<<"La temperatura media del "<<i+1<<" dias es: "<<tempMedia(max, min);
        cout<<endl;
    }
}
*/
///////////////     3      /////////////////////////////////////////////////

/*
float are(float radio){
    const float pi = 3.14;
    float area = pi*pow(radio,2);
    return area;
}
float peri(float radio){
    const float pi = 3.14;
    float perimetro = 2*pi*radio;
    return perimetro;
}

int main(){
    float radio;
    cout<<"Radio? ";cin>>radio;
    cout<<endl;
    cout<<"Su area y perimetro es: "<<are(radio)<<"     "<<peri(radio);
}
*/
///////////////      4       ////////////////////////////////////////////////////////
/*
float elevado(float x, float y){
    if(y > 0){
        return pow(x , y);
    }else{
        if(y < 0){
            y = y*(-1);
           return 1.0/(pow(x, y));
        }else{
            return 1;
        }
    }
}
int main(){
    float x, y;
    cout<<"Primer valor: ";cin>>x;
    cout<<"Segundo valor: ";cin>>y;
    cout<<"Resultado: "<<elevado(x, y);
}
*/
///////////////      5        ////////////////////////////////////////////////////////

/*
int factorial(int n){
    if(n == 0 || n == 1){
		return 1;
	}
	else{
		return factorial(n-1) * n;
    }
}
int main(){
    int x;
    cout<<"Ingrese un número: ";cin>>x;
    cout<<"Resultado: "<<factorial(x);
}
*/
///////////////      6        ////////////////////////////////////////////////////////
/*
int factorial(int n){
    if(n == 0 || n == 1){
		return 1;
	}
	else{
		return factorial(n-1) * n;
    }
}

int combinaciones(int n, int k){
    return factorial(n) / (factorial(k)*factorial(n-k));
}
int main(){
    int n, k;
    cout<<"Ingrese n: ";cin>>n;
    cout<<"Ingrese k: ";cin>>k;
    cout<<"Hay "<<combinaciones(n,k)<<" combinaciones";
}
*/
///////////////      7-8     ////////////////////////////////////////////////////////
/*
bool validFecha(int dia, int mes){
    if(1<=dia && dia<=31 && mes>=1 && mes<=12){
        return true;
    }else{
        return false;
    }
}

bool EsBisiesto(int alo){
    if(alo % 4 == 0 && (alo % 100 != 0 || alo % 400 == 0)){
        return true;
    }else{
        return false;
    }
}

int DiasDelMes(int mes, int alo){
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        return 31;
    }else{
        if(mes==4 || mes==6 || mes==9 || mes==11){
            return 30;
        }else{
            if(mes == 2 && EsBisiesto(alo)){
                return 29;
            }else{
                return 28;
            }
        }
    }
}

int Calcular_Dia_Juliano(int dia, int mes, int alo){
    int suma=0;
    if(mes==1){
        return dia;
    }else{
        for(int i=1; i<mes; i++){
            suma+=DiasDelMes(i, alo);
        }
        return suma+dia;
    }
}

int main(){
    int dia, mes, alo;
    do{
    cout<<"Dia?: ";cin>>dia;
    cout<<"Mes?: ";cin>>mes;
    cout<<"Año?: ";cin>>alo;
    }while(!validFecha(dia, mes));

    cout<<Calcular_Dia_Juliano(dia, mes, alo);   
}
*/