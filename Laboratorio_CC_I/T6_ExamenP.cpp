/*Resolver y entregar hasta las 15:40 horas los PROGRAMAS COMPLETOS 
que den solución a los siguientes problemas:

1. (5 ptos.) Mediante una función recursiva hallar la 
cantidad de cifras que tiene un número entero.

2. (5 ptos.) Usando funciones y solo arreglos estáticos 
unidimensionales, ingresar los códigos, nombres y 
promedios de N alumnos. Calcular el promedio más alto, 
el promedio de la clase y la cantidad de alumnos con 
promedio mayor a la media aritmética de los promedios.

3. (6 ptos.) Indicar si una cadena se encuentra o no 
dentro de otra; de encontrarse, indicar cuántas veces aparece. 
*/

#include <iostream>

using namespace std;

/////////////////////////      1       //////////////////////
/*
double digi(double n, double cont){
    if(n/10 == 0){
        return n + cont;
    }else{
        cont += 1;
        digi(n/10, cont);
    }
}

int main(){
    double n;
    double cont = 0;
    cin>>n;
    cout<<digi(n, cont)-322;
}
*/

/////////////////////////      2        //////////////////////
/*
void ingresarDa(int CO[], string Al[], int Pro[], int i){
    cout<<"Ingresar código: "; cin>>CO[i];
    cout<<"Ingresar nombre: "; cin>>Al[i];
    cout<<"Ingresar promedio: "; cin>>Pro[i];
}

int promediAlt(int Pro[], int n){
    int mayor=0;
    for (int i=0 ; i<n; i++){
        if (Pro[i]>mayor){
            mayor=Pro[i];
        }
    }
    return mayor;
}

float promediCla(int Pro[], int n){
    int suma=0;
    for (int i=0 ; i<n; i++){
        suma += Pro[i];
    }
    return suma/n;
}

int alumnoMa(int Pro[], int n){
    float mediA = promediCla(Pro, n);
    int cont=0;
    for(int i=0; i<n; i++){
        if(Pro[i]>mediA)
            cont++;
    }
    return cont;
}

int main(){
    int n;
    cout<<"Cuantos alumnos son? ";cin>>n;
    string Al[n];
    int Co[n];
    int Pro[n];

    for (int i=0 ; i<n; i++){
        ingresarDa(Co, Al, Pro, i);
    }
    cout<<"El promedio más alto es: "<<promediAlt(Pro, n)<<endl;
    cout<<"El promedio de la clase es: "<<promediCla(Pro, n)<<endl;
    cout<<"La cantidad de alumnos con promedio mayor al promedio es : "<<alumnoMa<<endl;
}
*/
/////////////////////////      3       //////////////////////

void contiene(string &a,string &b){
  int resultado =0;
  int tamA=a.length();
  int tamB=b.length();
  for(int i=0; i<tamA; i++){
    int n=0;
    for(int j=0; j<tamB; j++){
        if(b[j]==a[i+j]){
            n++;
        }else{
            break;
      }
    }
    cout<<"n: "<<n<<" tamB: "<<tamB<<endl;
    resultado += n/tamB;
    cout<<"resultado: "<<resultado<<endl;
  }
  if(resultado>0){
    cout<<"La subcadena " <<b<<" esta "<<resultado<<" en la cadena";
  }else{
    cout<<"La subcadena "<<b<<" no se encuentra en la cadena "<<a;
  }
}

int main(){
    string cad;
    string sub;
    cout<<"Ingresar primera cadena: ";cin>>cad;
    cout<<"Ingresar segunda cadena: ";cin>>sub;
    contiene(cad, sub);
}
