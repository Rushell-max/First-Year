///////////////////////////////////INTEGRANTES//////////////////////////////////////////////
// - MERISABEL RUELAS QUENAYA
// - FIORELA VILLARROEL RAMOS
// - RUSHELL VANESSA ZAVALAGA OROZCO
// - ALBERT VARGAS MAMANI
// - Diego Alonso Zanabria Sacsi
//////////////////////////////////EJERCICIO 10/////////////////////////////////////////////
//	METODO 1
# include <iostream>
using namespace std;
int main (){
	int num1,num2,num3;
	cout << "Introduce numero 1: "; cin>>num1;
	cout << "Introduce numero 2: "; cin>>num2;
	cout << "Introduce numero 3: "; cin>>num3;
	if ((num1>num2 && num1<num3)||(num1<num2 && num1>num3))
		cout<<"El numero del medio es "<<num1;
	else
		if ((num2>num1 && num2<num3)||(num2<num1 && num2>num3))
			cout<<"El numero del medio es "<<num2;
		else
			if ((num3>num1 && num3<num2)||(num3<num1 && num3>num2))
				cout<<"El numero del medio es "<<num3;
	return 0;
}
//////////////////////////////////EJERCICIO 11/////////////////////////////////////////////
// METODO 1
# include <iostream>
using namespace std;
int main(){
	int a, b, c;
	int n1,n2,n3;
	cout << "Introduce numero 1: "; cin>>a;
	cout << "Introduce numero 2: "; cin>>b;
	cout << "Introduce numero 3: "; cin>>c;
	if (a<b)
		if (a<c){
			n1=a;
			if (b<c){
				 // abc
				 n2=b;
				 n3=c;
			}
			else{
				// acb
				 n2=c;
				 n3=b;
			}
		}
		else{
			// cab
			n1=c;
			n2=a;
			n3=b;
		}
	else
		if (b<c){
			n1=b;
			if (c<a){
				// bca
				n2=c;
				n3=a;
			}
			else{
				// bac
				n2=a;
				n3=c;
			}
		}
		else{
			// cba
			n1=c;
			n2=b;
			n3=a;
		}
	cout<<endl<<"ORDENAMIENTO"<<endl;
	cout<<"\t"<<n1<<"\t"<<n3<<endl;
	cout<<"\t"<<n2<<"\t"<<n2<<endl;
	cout<<"\t"<<n3<<"\t"<<n1<<endl;
	return 0;
}
// METODO 2
#include <iostream>
using namespace std;
int main()
{
    int n1, n2, n3;
    cout<<"Ingrese el primer numero : "<<endl;
    cin>>n1;
    cout<<"Ingrese el segundo numero : "<<endl;
    cin>>n2;
    cout<<"Ingrese el tercer numero : "<<endl;
    cin>>n3;
    if(n1>n2 & n1>n3 & n2>n3){
        cout<<"La primera columna de numeros de menor a mayor es: "<<endl<<n3<<endl<<n2<<endl<<n1<<endl;
        cout<<"La siguiente columna de numero de mayor a menor es :"<<endl<<n1<<endl<<n2<<endl<<n3<<endl;

    }
    else if(n1>n2 & n1>n3 & n3>n2){
        cout<<"La primera columna de numeros de menor a mayor es: "<<endl<<n2<<endl<<n3<<endl<<n1<<endl;
        cout<<"La siguiente columna de numero de mayor a menor es :"<<endl<<n1<<endl<<n3<<endl<<n2<<endl;

    }
    else if(n2>n1 & n2>n3 & n1>n3){
        cout<<"La primera columna de numeros de menor a mayor es: "<<endl<<n3<<endl<<n1<<endl<<n2<<endl;
        cout<<"La siguiente columna de numero de mayor a menor es :"<<endl<<n2<<endl<<n1<<endl<<n3<<endl;

    }

    else if(n2>n1 & n2>n3 & n3>n1){
        cout<<"La primera columna de numeros de menor a mayor es: "<<endl<<n1<<endl<<n3<<endl<<n2<<endl;
        cout<<"La siguiente columna de numero de mayor a menor es :"<<endl<<n2<<endl<<n3<<endl<<n1<<endl;
    }

    else if(n3>n1 & n3>n2 & n2>n1){
        cout<<"La primera columna de numeros de menor a mayor es: "<<endl<<n1<<endl<<n2<<endl<<n3<<endl;
        cout<<"La siguiente columna de numero de mayor a menor es :"<<endl<<n3<<endl<<n2<<endl<<n1<<endl;
    }

    else if (n3>n1 & n3>n2 & n1>n2){
        cout<<"La primera columna de numeros de menor a mayor es: "<<endl<<n2<<endl<<n1<<endl<<n3<<endl;
        cout<<"La siguiente columna de numero de mayor a menor es :"<<endl<<n3<<endl<<n1<<endl<<n2<<endl;
    }
    return 0;
}


//////////////////////////////////EJERCICIO 13/////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int n1, n2, n3;
    cout<<"Ingrese el primer numero : "<<endl;
    cin>>n1;
    cout<<"Ingrese el segundo numero : "<<endl;
    cin>>n2;
    cout<<"Ingrese el tercer numero : "<<endl;
    cin>>n3;
    if(n1>n2 & n1>n3 & n2>n3){
        cout<<"La relación de mayor a menor es :"<<endl<<n1<<" "<<n2<<" "<<n3<<endl;
        cout<<"Los puntos que le faltan al segundo lugar para el primero es: "<<endl<<n1-n2<<endl;
        cout<<"Los puntos que le faltan al tercer lugar para el segundo es: "<<endl<<n2-n3<<endl;
    }
    else if(n1>n2 & n1>n3 & n3>n2){
        cout<<"La relación de mayor a menor es :"<<endl<<n1<<" "<<n3<<" "<<n2<<endl;
        cout<<"Los puntos que le faltan al segundo lugar para el primero es: "<<endl<<n1-n3<<endl;
        cout<<"Los puntos que le faltan al tercer lugar para el segundo es: "<<endl<<n3-n2<<endl;
    }
    else if(n2>n1 & n2>n3 & n1>n3){
        cout<<"La relación de mayor a menor es :"<<endl<<n2<<" "<<n1<<" "<<n3<<endl;
        cout<<"Los puntos que le faltan al segundo lugar para el primero es: "<<endl<<n2-n1<<endl;
        cout<<"Los puntos que le faltan al tercer lugar para el segundo es: "<<endl<<n1-n3<<endl;

    }

    else if(n2>n1 & n2>n3 & n3>n1){
        cout<<"La relación de mayor a menor es :"<<endl<<n2<<" "<<n3<<" "<<n1<<endl;
        cout<<"Los puntos que le faltan al segundo lugar para el primero es: "<<endl<<n2-n3<<endl;
        cout<<"Los puntos que le faltan al tercer lugar para el segundo es: "<<endl<<n3-n1<<endl;

    }

    else if(n3>n1 & n3>n2 & n2>n1){
        cout<<"La relación de mayor a menor es :"<<endl<<n3<<" "<<n2<<" "<<n1<<endl;
        cout<<"Los puntos que le faltan al segundo lugar para el primero es: "<<endl<<n3-n2<<endl;
        cout<<"Los puntos que le faltan al tercer lugar para el segundo es: "<<endl<<n2-n1<<endl;
    }

    else if (n3>n1 & n3>n2 & n1>n2){
        cout<<"La relación de mayor a menor es :"<<endl<<n3<<" "<<n1<<" "<<n2<<endl;
        cout<<"Los puntos que le faltan al segundo lugar para el primero es: "<<endl<<n3-n1<<endl;
        cout<<"Los puntos que le faltan al tercer lugar para el segundo es: "<<endl<<n1-n2<<endl;
    }
    else if(n3==n1==n2){
				cout<<"Los tres empatan ";
		}
		else if(n3==n2 && n3!=n1 && n3<n1){
        cout<<"La relación de mayor a menor es : "<<endl<<n1<<" "<<n2<<" "<<n3<<endl;
				cout<<"Estan empatados num. 3 y num. 2 "<<endl;
				cout<<"Los puntos que le falto a num. 3 son: "<<n1-n2;
		}
		else if(n3==n2 && n3!=n1 && n3>n1){
        cout<<"La relación de mayor a menor es : "<<endl<<n3<<" "<<n2<<" "<<n1<<endl;
				cout<<"Estan empatados num. 3 y num. 2 "<<endl;
				cout<<"Los puntos que le falto a num. 1 son: "<<n3-n1<<endl;
		}
		else if(n3==n1 && n3!=n2 && n3>n2){
        cout<<"La relación de mayor a menor es : "<<endl<<n3<<" "<<n1<<" "<<n2<<endl;
				cout<<"Estan empatados num. 3 y num. 1 "<<endl;
				cout<<"Los puntos que le falto a num. 2 son: "<<n3-n2<<endl;
		}
		else if(n3==n1 && n3!=n2 && n3<n2){
        cout<<"La relación de mayor a menor es : "<<endl<<n2<<" "<<n1<<" "<<n3<<endl;
				cout<<"Estan empatados num. 3 y num. 1 "<<endl;
				cout<<"Los puntos que le falto a num. 3 son: "<<n2-n3<<endl;
		}
		else if(n1==n2 && n1!=n3 && n1>n3){
        cout<<"La relación de mayor a menor es : "<<endl<<n1<<" "<<n2<<" "<<n3<<endl;
				cout<<"Estan empatados num. 1 y num. 2"<<endl;
				cout<<"Los puntos que le falto a num. 3 son: "<<n1-n3<<endl;
		}
		else if(n1==n2 && n1!=n3 && n1<n3){
        cout<<"La relación de mayor a menor es : "<<endl<<n3<<" "<<n2<<" "<<n1<<endl;
				cout<<"Estan empatados num. 1 y num. 2"<<endl;
				cout<<"Los puntos que le falto a num. 1 son: "<<n3-n1<<endl;
		}
		system("PAUSE");
    return 0;
}

//METODO 2
#include<bits/stdc++.h>

using namespace std;

int main() {
	int a,b,c;
	cout << "DIGITE LOS PUNTOS DEL PRIMER EQUIPO? ";
	cin >>a;
	cout << "DIGITE LOS PUNTOS DEL SEGUNDO EQUIPO? ";
	cin >>b;
	cout << "DIGITE LOS PUNTOS DEL TERCER EQUIPO? ";
	cin >>c;

	if (a==b && b==c){
		cout<<"El PRIMER , SEGUNDO Y TERCER EQUIPO ESTAN EMPATADOS CON "<<a<<" PUNTOS";
	}else if(a==b){
		if (a>c){
			cout<<"EL PRIMER Y SEGUNDO EQUIPO ESTAN EMPATADOS EN EL PRIMER LUGAR CON "<<a<<" PUNTOS Y PARA SER ALCANZADOS POR EL TERCER EQUIPO SE NECESITAN "<<a-c<<" PUNTOS";
		}else{
			cout<<"EL PRIMER Y SEGUNDO EQUIPO ESTAN EMPATADOS EN EL SEGUNDO LUGAR CON "<<a<<" PUNTOS Y PARA ALCANZAR AL TERCER EQUIPO NECESITAN "<<c-a<<" PUNTOS";
		}
	}else if(a==c){
		if (a>b){
			cout<<"EL PRIMER Y TERCER EQUIPO ESTAN EMPATADOS EN EL PRIMER LUGAR CON "<<a<<" PUNTOS Y PARA SER ALCANZADOS POR EL SEGUNDO EQUIPO SE NECESITAN "<<a-b<<" PUNTOS";
		}else{
			cout<<"EL PRIMER Y TERCER EQUIPO ESTAN EMPATADOS EN EL SEGUNDO LUGAR CON "<<a<<" PUNTOS Y PARA ALCANZAR AL SEGUNDO EQUIPO NECESITAN "<<b-a<<" PUNTOS";
		}
	}else if(b==c){
		if (b>a){
			cout<<"EL SEGUNDO Y TERCER EQUIPO ESTAN EMPATADOS EN EL PRIMER LUGAR CON "<<b<<" PUNTOS Y PARA SER ALCANZADOS POR EL PRIMER EQUIPO SE NECESITAN "<<b-a<<" PUNTOS";
		}else{
			cout<<"EL SEGUNDO Y TERCER EQUIPO ESTAN EMPATADOS EN EL SEGUNDO LUGAR CON "<<b<<" PUNTOS Y PARA ALCANZAR AL PRIMER EQUIPO NECESITAN "<<a-b<<" PUNTOS";
		}
	}else if(a>b && b>c) {
		cout<<"\nEL PRIMER LUGAR: PRIMER EQUIPO CON "<<a;
		cout<<"\nEL SEGUNDO LUGAR: SEGUNDO EQUIPO CON "<<b<<" PUNTOS Y PARA ALCANZAR AL PRIMER LUGAR LE FALTAN "<<a-b<<" PUNTOS";
		cout<<"\nEL TERCER LUGAR: TERCER EQUIPO CON "<<c<<" PUNTOS Y PARA ALCANZAR AL SEGUNDO LUGAR LE FALTAN "<<b-c<<" PUNTOS";
	}else if(c>b && b>a) {
		cout<<"\nEL PRIMER LUGAR: TERCER EQUIPO CON "<<c;
		cout<<"\nEL SEGUNDO LUGAR: SEGUNDO EQUIPO CON "<<b<<" PUNTOS Y PARA ALCANZAR AL PRIMER LUGAR LE FALTAN "<<c-b<<" PUNTOS";
		cout<<"\nEL TERCER LUGAR: PRIMER EQUIPO CON "<<a<<" PUNTOS Y PARA ALCANZAR AL SEGUNDO LUGAR LE FALTAN "<<b-a<<" PUNTOS";
	}else if(b>a && a>c) {
		cout<<"\nEL PRIMER LUGAR: SEGUNDO EQUIPO CON "<<b;
		cout<<"\nEL SEGUNDO LUGAR: PRIMER EQUIPO CON "<<a<<" PUNTOS Y PARA ALCANZAR AL PRIMER LUGAR LE FALTAN "<<b-a<<" PUNTOS";
		cout<<"\nEL TERCER LUGAR: TERCER EQUIPO CON "<<c<<" PUNTOS Y PARA ALCANZAR AL SEGUNDO LUGAR LE FALTAN "<<a-c<<" PUNTOS";
	}else if(c>a && a>b) {
		cout<<"\nEL PRIMER LUGAR: TERCER EQUIPO CON "<<c;
		cout<<"\nEL SEGUNDO LUGAR: PRIMER EQUIPO CON "<<a<<" PUNTOS Y PARA ALCANZAR AL PRIMER LUGAR LE FALTAN "<<c-a<<" PUNTOS";
		cout<<"\nEL TERCER LUGAR: SEGUNDO EQUIPO CON "<<b<<" PUNTOS Y PARA ALCANZAR AL SEGUNDO LUGAR LE FALTAN "<<a-b<<" PUNTOS";
	}else if(a>c && c>b) {
		cout<<"\nEL PRIMER LUGAR: PRIMER EQUIPO CON "<<a;
		cout<<"\nEL SEGUNDO LUGAR: TERCER EQUIPO CON "<<c<<" PUNTOS Y PARA ALCANZAR AL PRIMER LUGAR LE FALTAN "<<a-c<<" PUNTOS";
		cout<<"\nEL TERCER LUGAR: SEGUNDO EQUIPO CON "<<b<<" PUNTOS Y PARA ALCANZAR AL SEGUNDO LUGAR LE FALTAN "<<c-b<<" PUNTOS";
	}else {
		cout<<"\nEL PRIMER LUGAR: SEGUNDO EQUIPO CON "<<b;
		cout<<"\nEL SEGUNDO LUGAR: TERCER EQUIPO CON "<<c<<" PUNTOS Y PARA ALCANZAR AL PRIMER LUGAR LE FALTAN "<<b-c<<" PUNTOS";
		cout<<"\nEL TERCER LUGAR: PRIMER EQUIPO CON "<<a<<" PUNTOS Y PARA ALCANZAR AL SEGUNDO LUGAR LE FALTAN "<<c-a<<" PUNTOS";
	}

	return 0;
}



//////////////////////////////////EJERCICIO 16/////////////////////////////////////////////
/////////////////////////Metodo 1 /////////////////
#include<bits/stdc++.h>
using namespace std;
int main() {
int a , num , cont=0;
cout << "Digite un numero positivo que tenga menos de 4 cifras: ";
cin >> num;
a=num;
while (a!=0) {
	a = a / 10;
	cont++;
}
if (num>0 && cont<=4) {
	switch (cont){
		case 1: cout << "\n000"<<num;break;
		case 2: cout << "\n00"<<num;break;
	  case 3: cout << "\n0"<<num;break;
		case 4: cout <<"\n"<<num;break;
	}
}
return 0;
}
/////////////////////////////////// METODO 2 ///////////////////////////////////////////
#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Ingrese un numero maximo de 4 cifras: ";
	cin>>n;
	if (n<=9999){
		if(n<=9)
			cout<<"000"<<n;
		else if (n<=99)
			cout<<"00"<<n;
		else if (n<=999)
			cout<<"0"<<n;
		else if (n<=9999)
			cout<<n;
	}
	else
		cout<<"El numero ingresado es  incorrecto ";
}
//////////////////////////////////EJERCICIO 17/////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
int main() {
int V[5],menor;
 cout << "INGRESE NUMEROS\n\n";
 for (int i = 0;i<5;i++){
 	cout <<"numero? ";
 	cin >> V[i];
 }

 menor=V[0];
 for (int i = 0;i<5;i++){
 	if (menor>V[i]) {
 		menor=V[i];
	 }
 }

 cout << "\nEl menor valor ingresado fue "<<menor<<" y corresponde al ,";
 for (int i = 0;i<5;i++){
 	if (menor==V[i]) {
 		switch(i){
 			case 0: cout << " primer numero"; break;
 			case 1: cout << " segundo numero"; break;
 			case 2: cout << " tercer numero"; break;
 			case 3: cout << " cuarto numero"; break;
 			case 4: cout << " quinto numero"; break;
		 }
	 }
 }
return 0; }
