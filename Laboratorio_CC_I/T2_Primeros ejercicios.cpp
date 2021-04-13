#include <iostream>
#include <math.h>

using namespace std;
//1. Calcular la ma, mg para 2 numeros
/*
int main()
{   float a,b;
    float ma, mg;
    cout<<"Primer valor: ";
    cin>>a;
    cout<<"Segundo valor: ";
    cin>>b;

    ma=(a+b)/2;
    mg=sqrt(a*b);
    cout<<"La media aritmetica es: "<<ma<<endl;
    cout<<"La media geometrica es: "<<mg<<endl;
    return 0;
}
//2. Calcular la ma, mg para n numeros

int main(){
    float n, a;
    float ma, mg;
    float suma=0;
    float multip=1;

    cout<<"Cuantos valores dara?: ";
    cin>>n;

    cout<<"Ingresar valores: ";
    for(int i=0; i<n; i++){
        cin>>a;
        suma=a+suma;
        multip=a*multip;
    }

    ma=(suma)/n;
    mg=pow(multip, 1./n);
    cout<<"La media aritmetica es: "<<ma<<endl;
    cout<<"La media geometrica es: "<<mg<<endl;
    return 0;
}
//3. Calcular la ma, mg para 3 numeros

int main()
{   float a,b,c;
    float ma, mg;
    cout<<"Ingrese tres valores: ";
    cin>>a>>b>>c;

    ma=(a+b+c)/3;
    mg=pow((a*b*c), 1./3);
    cout<<"La media aritmetica es: "<<ma<<endl;
    cout<<"La media geometrica es: "<<mg<<endl;
    return 0;
}
*/
//Mayor de tres numeros
//Solucion 1
/*
int main(){
    int a, b, c;
    cout<<"Ingrese tres numeros: ";
    cin>>a>>b>>c;

    if(a>=b && a>=c)
        cout<<"El mayor es "<<a;
    if(b>=a && b>=c)
        cout<<"El mayor es "<<b;
    if(c>=a && c>=b)
        cout<<"El mayor es "<<c;
    return 0;
}
*/
//Solucion 2
int main(){
    int a, b, c;
    cout<<"Ingrese tres numeros: ";
    cin>>a>>b>>c;

    if(a>=b && a>=c)
        cout<<"El mayor es "<<a;
    else
        if(b>=a && b>=c)
            cout<<"El mayor es "<<b;
        else
            cout<<"El mayor es "<<c;
    return 0;
}
