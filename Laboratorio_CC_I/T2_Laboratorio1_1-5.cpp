#include <iostream>
#include<stdlib.h>
#include <math.h>

using namespace std;

/*1. Una temperatura en ºC se puede convertir a su equivalente Fahrenheit (ºF)
con la fórmula: F = 9/5 C + 32. Hacer un programa que lea una temperatura en
grados Centígrados y obtenga e imprima la temperatura Fahrenheit equivalente.
*/
//   SOLUCIÓN 1:

int main(){
	int tem;
	int far;
	cout<<"Indique la temperatura en grados Centígrados: "<<endl;
	cin>>tem;
	far=((9*tem)/5)+32;
	cout<<"La temperatura en Fahrenheit equivalente es: "<<far<<endl;
	system("Pause");
	return 0;
}
/*
//   SOLUCIÓN 2:

int main () {
	float c=0,f=0;
	cout << "Digite la temperatura en °C: ";
	cin >> c;
	f = (9*c)/5 + 32;
	cout << "\nLa temperatura en fahrenheit es: "<<f;

    system("Pause");
	return 0;
}

//    SOLUCIÓN 3:


int main(){
    float cent,far;
    cout << "cuantos grados desea cambiar?!" << endl;
    cin >> cen;
    cout<<endl;
    far = cent*(9/5) + 32
    cout<<"Los "<<cent<<" ªC a Fahrenheit es "<<far;

    system("Pause");
	return 0;
}

/*2. Ingresar un número entero y si el número es divisible entre 5 cambiar
su valor por el mismo elevado al cubo y si el número termina en 7 cambiar su
valor por su raíz cuadrada.


 //   SOLUCIÓN 1:

int main(){
	int numero1;
	float nuevo;
	cout<<"Ingrese un numero entero: "<<endl; cin>>numero1;
	if(numero1%5==0){
    	nuevo=pow(numero1, 3);
    	cout<<"El numero es divisible entre 5"<<endl;
    	cout<<"El nuevo numero elebado al cubo es: "<<nuevo<<endl;
	}
	else if(numero1==7 or numero1%10==7 or (numero1/10)%10==7){
    	nuevo = sqrt(numero1);
    	cout<<"El numero termina en 7 "<<endl;
    	cout<<"La raiz cuadrada del numero es: "<<nuevo<<endl;
	}
	else{
    	cout<<"El numero no termina en 7 ni es divisible entre 5"<<endl;
	}
    system("Pause");
	return 0;
}

//   SOLUCIÓN 2:

int main () {
	int ultimodig,entero;
	float raizflot;
	cout << "Digite un numero entero: ";
	cin >> entero;
	ultimodig = entero%10;
	if (ultimodig%5==0){
		entero=pow(entero,3);
		cout << "El nuevo valor es: " <<entero; }
	else if (ultimodig==7) {
		raizflot=sqrt(entero);
		cout << "El nuevo valor es: " <<raizflot;
	} else {
		cout << "Su valor es el mismo "<<entero;
	}
	return 0;
}

// SOLUCIÓN 3:
int main(){
	int num;
	cout<<"Ingrese un numero: "<<endl;
	cin>>num;

	if(num%5==0){
	    cout<<"Resultado: "<<pow(num, 3)<<endl;
	}
	else
	    if(num==7 or num%10==7 or (num/10)%10==7 or ((num/10)/10)%10==7){
			cout<<"Resultado: "<<sqrt(num)<<endl;
		}
		else{
			cout<<"El numero no es divisible en 5 o termina en 7"<<endl;
		}
	return 0;
}

/*3. Encontrar cuál de tres valores leídos (A, B, C) por la computadora, es el menor.
SOLUCIÓN 1:


int main(){
	int a, b, c ;
	cout<< "Ingrese tres valores: " << endl ;
	cin>> a >> b >> c ;

	if(a<=b && a<=c)
        		cout<<"El menor es "<<a;
	else
    		if(b<=a && b<=c)
        			cout<<"El menor es "<<b;
		else
       			cout<<"El menor es "<<c;
	return 0;
}

// SOLUCIÓN 2:

int main () {
	float N1,N2,N3;
	cout << "NUMERO 1? "; cin>>N1;
	cout << "NUMERO 2? "; cin>>N2;
	cout << "NUMERO 3? "; cin>>N3;
	if ( N1 < N2 && N1 < N3){
		cout << "el menor es: "<<N1;
	} else if ( N2 < N1 && N2 < N3) {
		cout << "el menor es: "<<N2;
	} else {
		cout << "el menor es: "<<N3;
	}
	return 0;
}
/*
4. Considere que está desarrollando una web donde trabaja con tipos de motor (suponemos que se trata del tipo de motor de una bomba para mover fluidos). Los valores posibles son 1, 2, 3, 4.
a) Si el tipo de motor es 0, mostrar un mensaje indicando “No hay establecido un valor definido para el tipo de bomba”.
b) Si el tipo de motor es 1, mostrar un mensaje indicando “La bomba es una bomba de agua”.
c) Si el tipo de motor es 2, mostrar un mensaje indicando “La bomba es una bomba de gasolina”.
d) Si el tipo de motor es 3, mostrar un mensaje indicando “La bomba es una bomba de hormigón”.
e) Si el tipo de motor es 4, mostrar un mensaje indicando “La bomba es una bomba de pasta alimenticia”.
f) Si no se cumple ninguno de los valores anteriores mostrar el mensaje “No existe un valor válido para tipo de bomba”.
SOLUCIÓN 1:



int main(){
    int mot;
    cout << "¿Que tipos de fluido de motor esta usando? " << endl;
    cin >> mot;
    if (mot == 1){cout<<"La bomba es una bomba de agua"<<endl;
    }else{if(mot == 2){ cout<<"La bomba es una bomba de gasolina"<<endl;
    }else{if(mot==3){ cout<<"La bomba es una bomba de hormigon"<<endl;
    }else if (mot == 4){ cout<<"La bomba es una bomba de pasta alimenticia"<<endl;
    }else { cout << "No existe un valor válido para tipo de bomba"; }}}
    return 0;
}



// SOLUCIÓN 2:

int main () {
	int N;
	cout << "DIGITE UN NUMERO: ";
	cin >> N;
	switch (N) {
		case 0:
			cout << "No hay establecido un valor definido para el tipo de bomba";break;
		case 1:
			cout <<  "La bomba es una bomba de agua";break;
		case 2:
			cout << "La bomba es una bomba de gasolina";break;
		case 3:
			cout <<  "La bomba es una bomba de hormigón";break;
		case 4:
			cout << "La bomba es una bomba de pasta alimenticia";break;
		default:
			cout << "No existe un valor valido para tipo de bomba";break;
	}
	return 0;
}

/*
5. Considera que estás desarrollando un programa donde necesitas trabajar con
objetos de tipo Rueda (que representa a una rueda de un vehículo).
Realizar las siguientes comprobaciones:
a) Si el diámetro es superior a 1.4 debe mostrar por consola el mensaje
“La rueda es para un vehículo grande”. Si es menor o igual a 1.4 pero mayor
que 0.8 debe mostrarse por consola el mensaje “La rueda es para un vehículo
mediano”.
Si no se cumplen ninguna de las condiciones anteriores debe mostrarse por
pantalla el mensaje “La rueda es para un vehículo pequeño”.

b) Si el diámetro es superior a 1.4 con un grosor inferior a 0.4, ó si el
diámetro es menor o igual a 1.4 pero mayor que 0.8, con un grosor inferior
a 0.25, deberá mostrarse por consola el mensaje “El grosor para esta rueda es
inferior al recomendado”.



// SOLUCION 1:

int main () {
	float DIAMETRO,GROSOR;
	cout << "Digite el Diametro: ";
	cin >> DIAMETRO;
	cout << "\nDigite el Grosor: ";
	cin >> GROSOR;

	if (DIAMETRO>1.4) {
		cout << "La rueda es para un vehiculo grande";
		if (GROSOR<0.4) {
			cout << "\nEl grosor para esta rueda es inferior al recomendado";
		}
	} else if (DIAMETRO>0.8 && DIAMETRO<=1.4) {
		cout << "La rueda es para un vehiculo mediano";
if (GROSOR<0.25) {cout<< "\nEl grosor para esta rueda es inferior al recomendado";
		}
	} else {
		cout << "La rueda es para un vehiculo pequeño";
	}
	return 0;
}
*/
