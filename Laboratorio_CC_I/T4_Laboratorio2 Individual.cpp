#include<iostream>
#include<stdlib.h>

using namespace std;

//26. Escriba un programa que despliegue todas las permutaciones de los números del 1 a n. Por
//ejemplo, si n = 3, debe obtenerse:

string crearfor(int i){
	char letra = 65+i;
	return ("for(int ")(letra)("=0; ");letra;"<n; ";letra;"++){";
}
/*
string crearvariable(int n){
	for(letra='a';letra<='z';letra++){

}

string compa(int n){
	return
}
*/
int main(){
	int n;
	cout<<"Ingrese un número: ";cin>>n;

	for (int i=0; i<n; i++){
		cout<<crearfor(i)<<endl;
	}

	system("PAUSE");
	return 0;
}
/*
int main(){
	int n;
	cout<<"Ingrese un número: ";cin>>n;

	for(int j=0; j<n; j++){
		for(int k=0; k<n; k++){
			for(int l=0; l<n; l++){
				if(j!=k && k!=l && j!=l){
					cout<<j+1<<" "<<k+1<<" "<<l+1<<endl;
				}
			}
		}
	}

	system("PAUSE");
	return 0;
}*/

//31. Mostrar los números de Fibonacci menores de 100. Estos se calculan sumando los dos
//anteriores. Así: 0, 1, 1, 2, 3, 5, 8, 13, ...
/*
int fibo(int n){
	if(n == 0 || n == 1){
		return n;
	}
	else
		return fibo(n - 2) + fibo(n - 1);
}

int main(){

	int i=0;
	do{
        cout<<fibo(i)<<" ";
		i++;
	}while(fibo(i)<100);
	cout<<endl;
	system("PAUSE");
	return 0;
}
*/
/*
32. Escribir un programa que indique cuántos dígitos tiene un valor ingresado.
Diálogo ejemplo:
Número? 2006
El valor ingresado tiene = 4 dígitos
*/
/*
int main(){
	int numero;
	int cont=0;
	cout<<"Ingrese un número: ";cin>>numero;
	cout<<endl;
	int i=10;
	while(numero/i != 0){
			cont++;
			i = i*10;
	}

	cout<<"El valor ingresado tiene "<<cont+1<<" digitos. ";
	system("PAUSE");
	return 0;

}
*/
/*34. El curso de Programación I tiene n alumnos, cada alumno tiene x notas, se requiere crear un
algoritmo que permita imprimir el promedio de cada alumno, el promedio de la clase y el
número de alumnos cuyo promedio:
 Es mayor a 15.
 Está entre 12 y 15.
 Está entre 5 y 11.
 Entre 0 y 5.*/
/*
int main(){
	int n, x;
	cout<<"Cuantos alumnos hay en clase? ";cin>>n;
	cout<<endl;
	cout<<"Cuantas notas tiene cada uno? ";cin>>x;

	float a = 0, cont = 0, total=0;
	int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<x; j++){
			cout<<endl;
			cout<<"Alumno "<<i+1<<": "<<endl;
			cout<<"Nota "<<j+1<<" ";cin>>a;
			cont += a;
		}
		cout<<endl;
		cout<<"El promedio del "<<i+1<<" alumno es: "<<cont/x;
		cout<<endl;
		if ((cont/x)>15){
			cont1++;
		}else
		    if((15>=(cont/x)) && ((cont/x)>11)){
				cont2++;
			}else
			    if((11>=(cont/x)) && ((cont/x)>5)){
			        cont3++;
				}else
				    if((5>=(cont/x)) && ((cont/x)>=0)){
						cont4++;
					}
		total += cont;
		cont=0;
	}
	cout<<endl;
	cout<<"El promedio de la clase es: "<<total/(n*x)<<endl;
	cout<<"El número de alumnos cuyo promedio: "<<endl;
 	cout<<"Es mayor a 15       "<<cont1<<endl;
 	cout<<"Está entre 12 y 15  "<<cont2<<endl;
 	cout<<"Está entre 5 y 11.  "<<cont3<<endl;
 	cout<<"Entre 0 y 5.        "<<cont4<<endl;
 	
 	system("PAUSE");
 	return 0;

}
*/
//35. Escriba un algoritmo para determinar las posibles adquisiciones que se pueden hacer con 87
//soles sin que sobre dinero de 3 productos de 5, 7 y 19 soles.
/*
int main(){
	int tot = 87;
	int cont=0;
	
	cout<<"Las posibles adquisiciones que se pueden hacer: "<<endl;
	cout<<"En orden de los tres productos 5,  7 y 19 "<<endl;
	cout<<endl;
	for(int i=0; i<17; i++){
        for(int j=0; j<12; j++){
            for(int k=0; k<4; k++){
				cont = 5*i+7*j+19*k;
				if (cont == 87){
					cout<<i<<" productos de 5"<<endl;
					cout<<j<<" productos de 7"<<endl;
					cout<<k<<" productos de 19"<<endl;
					cout<<endl;
				}
			}
		}
 	}
	system("PAUSE");
	return 0;
}
*/
