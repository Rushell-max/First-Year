/*
1. Dado un vector que registra la talla 5 perros, se pide hallar la media, la varianza, la
	desviación estándar y determinar cuántos animales están con una talla dentro de lo normal.
	https://www.disfrutalasmatematicas.com/datos/desviacion-estandar.html
2. Hallar los n primeros números de la Serie Fibonacci, almacenemos en un vector, luego en
	otro vector guarde solo los que son múltiplos de 3 y muéstrelos ordenados en forma
	ascendente y descendente.
3. Crear una matriz cuadrada y mediante un Menú realizar las siguientes opciones:
	a) Leer Datos.
	b) Modificar Datos.
	c) Mostrar Datos.
	d) Mostrar la suma de la diagonal principal.
	e) Mostrar la suma de la diagonal secundaria.
	f) Salir
*/
#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<math.h>
#include<cmath>
#include<conio.h>

using namespace std;

/*
1. Dado un vector que registra la talla 5 perros, se pide hallar la media, la varianza, la
	desviación estándar y determinar cuántos animales están con una talla dentro de lo normal.
	https://www.disfrutalasmatematicas.com/datos/desviacion-estandar.html

int main(){
	int P[5]={600,470,170,430,300};

	int suma = 0;
	for(int i = 0; i<5; i++){
		suma += P[i];
	}
	int media = suma/5;
	cout<<"La media es: "<<media<<endl;

	float x = 0;
	for(int i = 0; i<5; i++){
		float sumatoria = pow((P[i] - media),2);
		x += sumatoria;
	}
	int varianza = x / 5;
	cout<<"La varianza es: "<<varianza<<endl;

	int desvEst = sqrt(varianza);
	cout<<"La desviación estandar es: "<<desvEst<<endl;

	int norm=0;
	for(int i=0; i<5; i++){
    	if(P[i]<(media+desvEst) && P[i]>(media-desvEst)){
      		norm = norm+1;
		}
	}
	cout<<"Perritos en talla normal: "<<norm<<endl;
    system("PAUSE");
	return 0;
}

/*
2. Hallar los n primeros números de la Serie Fibonacci, almacenemos en un vector, luego en
	otro vector guarde solo los que son múltiplos de 3 y muéstrelos ordenados en forma
	ascendente y descendente.
*/
/*
int main(){
	int n;
	cout <<"Digite un número: ";
	cin >> n;

	int fib[n];
	fib[0]=1;
	fib[1]=1;

    cout<<"\nSerie de Fibonacci \n";
	for(int i=2; i<n; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
    for(int i=0; i<n; i++){
		cout<<fib[i]<<" ";
	}    
	int mult3[1000];
	int p=0;
 	for(int i=0; i<n; i++){
    	if (fib[i] % 3 == 0){
      		mult3[p] = fib[i];
      		p += 1;
   	  }
	}
	cout<<"\nLos múltiplos de 3: \n";
	for(int i=0; i<p; i++){
		cout<<mult3[i]<< " ";
	}
    cout<<"\nDe forma ascendente: \n";
	for(int i=0; i<p; i++){
		cout<<mult3[i]<< " ";
	}
    cout<<"\nDe forma descendente: \n";
	for(int i=p-1; i>=0; i--){
		cout<<mult3[i]<<" ";
	}
	cout<<endl;
	system("PAUSE");
	return 0;
}

/*
3. Crear una matriz cuadrada y mediante un Menú realizar las siguientes opciones:
	a) Leer Datos.
	b) Modificar Datos.
	c) Mostrar Datos.
	d) Mostrar la suma de la diagonal principal.
	e) Mostrar la suma de la diagonal secundaria.
	f) Salir
*/

//A
void leerDatos(int **M, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
    	cout<<"\nValor: \n";
    	cin>>M[i][j];
    	}
	}
}

//B
void modifDatos(int **M, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
    	cout<<"\nValor: \n";
    	cin>>M[i][j];
    	}
	}
}

//C
void mostrarDatos(int **M, int n){
	for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cout<<M[i][j]<<" ";
    	}
    cout<<endl;
	}
}

//D
int sumaDiagPrinc(int **M, int n){
	int s=0;
	for(int i=0; i<n; i++){
		s += M[i][i];
	}
	return s;
}

//E
int sumaDiagSecun(int **M, int n){
	int s=0;
	for(int i=0; i<n; i++){
		s += M[i][n-1];
		n -= 1;
	}
	return s;
}


int main(){
	int n;
	cout<<"\nDe que orden será la matriz: \n";
	cin>>n;

    int** M = new int*[n];
    for (int i = 0; i < n; ++i){
    	M[i] = new int[n];
	}
    int inp;

	while(inp != 6){
		cout<<"\n1) Leer Datos \n";
		cout<<"\n2) Modificar Datos.\n";
		cout<<"\n3) Mostrar Datos.\n";
		cout<<"\n4) Mostrar la suma de la diagonal principal.\n";
		cout<<"\n5) Mostrar la suma de la diagonal segundaria.\n";
		cout<<"\n6) Salir\n";
		cout<<"\nQue desea hacer? \n";
		cin>> inp;

		switch(inp){
			case 1:
				system("cls");
				leerDatos(M,n);
				system("Pause");
				system("cls");
			break;
			case 2:
				system("cls");
				modifDatos(M,n);
				system("Pause");
				system("cls");
			break;
			case 3:
				system("cls");
				mostrarDatos(M,n);
				system("Pause");
				system("cls");
			break;
			case 4:
				system("cls");
				cout<<sumaDiagPrinc(M,n)<<endl;
				system("Pause");
				system("cls");
			break;
			case 5:
				system("cls");
				cout<<sumaDiagSecun(M,n)<<endl;
				system("Pause");
				system("cls");
			break;
		}
	}

	system("PAUSE");
	return 0;
}


