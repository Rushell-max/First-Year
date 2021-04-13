#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <time.h>
# include <windows.h>

using namespace std;

////////////1. Mostrar los N primeros m�ltiplos de 3./////////////
/*
int main(){
	int n;
	cout<<"Ingrese un n�mero: "<<endl;
	cin>>n;

	for(int i=1; i<n+1; i++){
		cout<<i*3<<" ";
	}

	cout<<endl;

	system("PAUSE");
	return 0;
}
*/
//////////////////2. Mostrar los impares entre 1 y 100.////////////
/*
int main(){
	cout<<"Los impares entre 1 y 100 son: "<<endl;

	for(int i=1; i<101; i++){
		if(i%2!=0){
			cout<<i<<" ";
		}
	}

	cout<<endl;
	
	system("PAUSE");
	return 0;
}
*/
///////////////////3. Mostrar los pares entre a y b.//////////////////
/*
int main(){
	int a, b;
	cout<<"Ingresar a: ";cin>>a;
	cout<<"Ingresar b: ";cin>>b;
	cout<<"Los impares entre "<<a<<" y "<<b<<" son: ";

	for(int i=a; i<b+1; i++){
		if(i%2!=0){
			cout<<i<<" ";
		}
	}

	cout<<endl;

	system("PAUSE");
	return 0;
}
*/

/////////////////4. Se introducen 5 n�meros por teclado, y se desea calcular cu�ntos son mayores que 0,
//cuantos son menores a 0 y cuantos son iguales a 0.//////////////////////////////////
/*
int main(){
	int a;
	int contI=0 , contM =0;

	for(int num=0; num<5; num++){
		cout<<"Ingresar un n�mero: ";cin>>a;
		if(a<0){
			contM++;
		}
		if(a==0){
			contI++;
		}
	}
	cout<<endl;
	cout<<"Cantidad de valores menores a 0: "<<contM<<endl;
	cout<<endl;
    cout<<"Cantidad de valores iguales a 0: "<<contI<<endl;

	system("PAUSE");
	return 0;
}
*/
/////////////5. Ingresar valores por teclado hasta que se ingrese un cero.//////////7
/*
int main(){
	int a;
	do{
		cout<<"Ingresa un valor: "<<endl;
		cin>>a;
	}
	while(a!=0);
	
	system("PAUSE");
	return 0;
}
*/
//6. Hallar la suma de todos los n�meros ingresados por el usuario. El programa ya no pedir� m�s
//n�meros cuando el usuario ingrese 0.
/*
int main(){
	int a,s=0;
	do{
		cout<<"Ingresa un valor: ";cin>>a;
		s+=a;
	}
	while(a!=0);
	
	cout<<endl;
	
	cout<<"La suma de los n�meros ingresados es: "<<s<<endl;
	
	cout<<endl;
	
	system("PAUSE");
	return 0;
}
*/
//7. Realice un programa que permita a los alumnos realizar el juego del Porfiado en donde la
//computadora siempre gana. Adem�s, deber� implementar un sistema de dialogo que le
//pregunte al usuario si desea seguir jugando.

/*
int main(){
	int num, dec=1;
	do{
		cout<<"Ingrese un n�mero: ";cin>>num;
	    cout<<endl;
		cout<<"J�, te gan� con el "<<num+1<<endl;
		cout<<endl;
		cout<<"Deseas seguir jugando?: "<<endl;
		cout<<endl;
		cout<<" 1 = si // 0 = no : ";cin>>dec;
		cout<<endl;
	}
	while(dec == 1);
	
	system("PAUSE");
	return 0;
}
*/
//8. Programa en el que el ordenador lanza 50 veces un dado y cuenta cuantas veces sale el n�
//1.
/*
int main(){
	int azar, cont = 0 ;
	srand(time(NULL));
	for(int i = 0; i < 50 ; i++ ){
		azar = rand()% 6;
		cout << "El valor "<< i <<" es:  "<< azar<< endl;
		if(azar == 1){
			cont++;
		}
	}

	cout<<"El programa conto "<<cont<<" veces que sale el n� 1. :D"<<endl;
	system("PAUSE");
	return 0;
}
*/
//9. Pedir sucesivamente por teclado un n�mero hasta que el n�mero sea un valor comprendido
//entre 1 y 5.
/*
int main(){
	int a;
	do{
		cout<<"Ingresa un valor: ";cin>>a;
	}
	while(a!=1 && a!=2 && a!= 3 && a!= 4 && a!= 5);


	system("PAUSE");
	return 0;
}

*/
//10. Mostrar un listado con los valores de 1, 2, ....., 1000 fotocopias, junto con su costo
//respectivo, si el precio unitario de la fotocopia es le�do por la computadora.
/*
int main(){
	int precio;
	cout<<"Ingrese el precio unitario de la fotocopia: ";cin>>precio;
	for(int i=1; i<=1000; i++){

	}

	system("PAUSE");
	return 0;
}
*/
//11. Producir el mismo listado anterior si existe una promoci�n que consiste en un descuento del
//10% para cantidades entre 100 y 200 unidades y del 15% para cantidades entre 201 y 500
//unidades y del 20% para compras mayores.




//13. Suponga que se tiene un conjunto de calificaciones de un grupo de 10 alumnos. Realizar un
//algoritmo para calcular la calificaci�n media y la calificaci�n mas baja de todo el grupo.
/*
int main(){
	float suma = 0;
	int nota;
	int menor = 20;
	for(int i=0;i<10;i++){
		cout<<"Nota: ";cin>>nota;
		suma += nota;
		if(nota<menor){
			menor = nota;
		}
	}
	cout<<endl;
	cout<<"La calificaci�n media es: "<<suma/10<<endl;
	cout<<"La nota m�s baja es: "<<menor<<endl;
	
	system("PAUSE");
	return 0;
}
*/

//14. Simular el comportamiento de un reloj digital, imprimiendo la hora, minutos y segundos de
//un d�a desde las 0:00:00 horas hasta las 23:59:59 horas
/*
int main(){
	for(int h = 00; h<=23; h++){
		for(int m = 00; m<=59; m++){
			for(int s = 00; s<=59; s++){
				cout.fill('0');cout.width (2); cout<<h;
				cout<<" : ";
				cout.fill('0');cout.width (2); cout<<m;
				cout<<" : ";
				cout.fill('0');cout.width (2); cout<<s<<endl;
				Sleep(1000);
			}

		}
	}
	system("PAUSE");
	return 0;
}

*/

/*18. En un supermercado un ama de casa pone en su carrito los art�culos que va tomando de los
estantes. La se�ora quiere asegurarse de que el cajero le cobre bien lo que ella ha
comprado, por lo que cada vez que toma un articulo anota su precio junto con la cantidad
de art�culos iguales que ha tomado y determina cuanto dinero gastar� en ese articulo; a
esto le suma lo que ira gastando en los dem�s art�culos, hasta que decide que ya tomo todo
lo que necesitaba. Ay�dale a esta se�ora a no pasarse de su presupuesto*/
/*
int main(){
	float presupuesto, precio;
	string articulo;
	int cantidad;
	
	int suma = 0 ;
	int respuesta = 1;
	
	cout<<"Cu�l es su presupuesto: ";cin>>presupuesto;
	while(respuesta == 1){
		cout<<"Nombre del articulo: ";cin>>articulo;
		cout<<endl;
		cout<<"Precio del articulo: ";cin>>precio;
		cout<<"Cantidad de "<<articulo<<" que llevara: ";cin>>cantidad;
		suma += precio*cantidad;
		cout<<endl;
		cout<<"Monto hasta el momento: "<<suma<<endl;
		cout<<endl;
		if(suma==presupuesto){
			cout<<"Ha llegado al m�ximo"<<endl;
			break;
		}else
		    if(suma>presupuesto){
				cout<<"Se ha excedido el monto "<<endl;
				cout<<endl;
				suma -= precio*cantidad;
				cout<<"Monto sin la ultima compra: "<<suma<<endl;
			}
		cout<<endl;
		cout<<"Desea seguir comprando? 1/Si   0/No ";cin>>respuesta;
		cout<<endl;
	}
	system("PAUSE");
	return 0;
}
*/
/*19. Una central distribuye cal hacia diferentes almacenes sucursales. Disponen de un muelle de
carga a donde van llegando sacas de cal de entre 3000 y 9000 Kgs, con pesos variables en
funci�n de las circunstancias de la producci�n. La empresa dispone de una flota de
camiones con capacidades de carga de entre 18000 y 28000 Kgs.
Se pretende establecer un protocolo consistente en cargar 20 camiones diarios. Cada
cami�n se quiere cargar como m�ximo a su l�mite de capacidad debiendo partir si con la
siguiente saca en la l�nea de producci�n se fuera a exceder su capacidad.
La empresa quiere desarrollar un programa que le pida al operario encargado de carga la
capacidad del cami�n y el peso de las sacas, indic�ndole si debe cargar la saca o despachar
el cami�n para comenzar a cargar otro.*/
/*
int main(){
	int cal1= 3000, cal2=9000;
	int cam1=8000, cam2=28000;
	int cant=20, cont=0, num, kg;
	
	for(int i=1; i<cant;i++){
		cont=0;
		cout<<"Cami�n: "<<i<<": "<<endl;
		cout<<"Capacidad: 1/8000   2/2800";cin>>capa;
		cout<<"Kg de la saca: ";cin>>kg
		while(cont+kg<=capa){
		    cont += kg;
		    cout<<"Total "<<cont<<endl;
		    cout<<"Kg de la saca: ";cin>>kg;
		}
		cout<<"Capacidad excesiva sale con: "
	}
}
*/
/*
int main(){
	for(int i=1; i<=10; i++){
	    for(int j=0; j<10; j++){
			cout<<i<<" ";
		}
	cout<<endl;
	}
}
*/
int main(){
	for(int i=1; i<=15; i++){
		int num=1;
	    for(int j=1; j<=4; j++){
			cout<<num<<" ";
			num=num*10+j+1;
		}
		cout<<endl;
	}
	system("PAUSE");
	return 0;
}
