/*//////////////   GUIA ARBOLES HUFFMAN // LABORATORIO 7   //////////////////////////////

    -Nombre Completo: RUSHELL VANESSA ZAVALAGA OROZCO 
	-CUI: 20202227	
	-Email (Institucional):  rzavalaga@unsa.edu.pe
	-Fecha: 19 de octubre 2020	
	-Sección: A y B
	-Docente: Dra. Roxana Flores Quispe /Dr. Yuber Elmer Velazco Paredes

*/

/*////////////////          ACTIVIDADES           /////////////////////

	a) Generar un grafo seudo aleatorio sin lazos (.dot) dado n vértices 
		con las posibilidades de salvar los datos.
			- Generar el camino básico
						
						A 	B 	C 	D
					A 		1
					B 	1 		1
					C 		1 		1
					D 			1

			- Agregar enlaces aleatoriamente.

	b) Mediante la búsqueda en profundidad generar un árbol de expansión y 
		visualizarlo.

	c) Mediante la búsqueda en amplitud generar un árbol de expansión y 
		visualizarlo.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//     A                                    ///////////////////////
/*	a) Generar un grafo seudo aleatorio sin lazos (.dot) dado n vértices 
		con las posibilidades de salvar los datos. 
*/

// - Función para completar una matriz con 0's
void CompletarCeros(int **M, int n){
	for(int i=0; i<n;i++)
		for(int j=0; j<n;j++)
 			M[i][j]=0;
}

// -Función que mantiene la simetria en la matriz
void simetria(int **M, int n){
	for(int i=0; i<n;i++)
		for(int j=0; j<n;j++)
            if(M[i][j]==1)
                M[j][i]=1;
}

// - Generar el camino básico
void caminoBas(int **M, int n){
    for (int i=1; i<n; i++)
        M[i][i-1]=1;
    simetria(M, n);
}

// - Agregar enlaces aleatoriamente.
void aleatorio(int **M, int n){
	srand(time(NULL));
   	for(int i=0; i<n;i++)
		for(int j=0; j<i;j++)
 			if (i!=j && M[i][j] == 0){
                M[i][j]=rand() % 2;
            }
    simetria(M, n);
}

// -Función para mostrar una matriz
void mostrar(int **M, int n){
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++)
 			cout<<M[i][j]<<" ";
  		cout<<endl;
 	}
	cout<<endl;
}

// - Función para visualizar el grafo base 
void grafo(int **M, int n){
    ofstream grafo;
    grafo.open("D:\\projects\\Laboratorio ED\\Graphviz\\bin\\T9_Grafo.dot");
    grafo << "graph G{ " << endl;
	for(int i=0; i<n;i++)
		for(int j=0; j<i;j++)
			//cout<<" I: "<<i<<" J: "<<j<<endl;
			if(M[i][j]==1){
				//cout<<" entro I: "<<i<<" J: "<<j<<endl;
				grafo << j+1<< " -- " << i+1 <<";"<< endl;
			}
	grafo<< "}"<<endl;
	grafo.close();
	system("D: & cd Graphviz & cd bin & dot T9_Grafo.dot -o T9_Grafo.png -Tpng & T9_Grafo.png");
}

void ingresar(int **&M, int n){
	for(int i=0; i<n; i++){
		for (int j=0; j<i ; j++){
			cout<<"I: "<<i<<" J: "<<j;
			cin>>M[i][j];
		}
	}
	simetria(M, n);
}

// -Función principal que acoge tofo el ejercicio A
void actividadA(int **M, int n){
    CompletarCeros(M, n);
	//caminoBas(M,n);
    //aleatorio(M, n);
	ingresar(M, n);
	cout<<"Mostrando matriz base "<<endl;
    mostrar(M,n);
	grafo(M, n);
}

//     B                                    ///////////////////////
/*	b) Mediante la búsqueda en profundidad generar un árbol de 
		expansión y visualizarlo
*/

// - Función para visualizar el grafo de profundidad
void grafoPROF(int **MP, int n){
    ofstream grafo;
    grafo.open("D:\\projects\\Laboratorio ED\\Graphviz\\bin\\T9_GrafoProf.dot");
    grafo << "graph G{ " << endl;
	for(int i=0; i<n;i++)
		for(int j=0; j<i;j++)
			//cout<<" I: "<<i<<" J: "<<j<<endl;
			if(MP[i][j]==1){
				//cout<<" entro I: "<<i<<" J: "<<j<<endl;
				grafo << j+1<< " -- " << i+1 <<";"<< endl;
			}
	grafo<< "}"<<endl;
	grafo.close();
	system("D: & cd Graphviz & cd bin & dot T9_GrafoProf.dot -o T9_GrafoProf.png -Tpng & T9_GrafoProf.png");
}

// -Función que ayuda a que no haya ciclos en la matriz de profundidad 
bool aristaNOCreaCicloPROF(int **MP, int n, int i){
	int suma = 0;
	//cout<<"entre arista con i "<<i<<endl;
	for (int j=i+1; j<n ;j++){
		//cout<<" J: "<<j<<" I: "<<i<<" = "<<MP[j][i]<<endl;
		suma += MP[j][i];
	}
	//cout<<"SUMA = "<<suma<<endl;
	if (suma <= 1){
		return false;
	}
	else
		return true;
}

// -Función principal del ejercicio B
void busquedaProfun(int **M, int n){
	int **MP=new int *[n];
	for(int i=0; i<n;i++){
		MP[i]=new int[n];
    }
	CompletarCeros(MP, n);

	for (int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			//cout<<" I: "<<i<<" J: "<<j<<endl;
			if (M[i][j] == 1){
				MP[i][j] = 1;
				simetria(MP, n);
				if (aristaNOCreaCicloPROF(MP, n, i)){
					//cout<<" PINTA 0 ";
					MP[i][j] = 0;
					MP[j][i] = 0;
				}
			}
		}
	}
	cout<<"Mostrando matriz de profundidad "<<endl;
	mostrar(MP, n);
	grafoPROF(MP, n);
    for(int i=0;i<n;i++){
		delete [] MP[i];
	}
	delete [] MP;
}

//     C                                    ///////////////////////
/*	c) Mediante la búsqueda en amplitud generar un árbol de 
		expansión y visualizarlo.
*/

// - Función para visualizar el grafo de amplitud
void grafoAMP(int **MP, int n){
    ofstream grafo;
    grafo.open("D:\\projects\\Laboratorio ED\\Graphviz\\bin\\T9_GrafoAMP.dot");
    grafo << "graph G{ " << endl;
	for(int i=0; i<n;i++)
		for(int j=0; j<i;j++)
			//cout<<" I: "<<i<<" J: "<<j<<endl;
			if(MP[i][j]==1){
				//cout<<" entro I: "<<i<<" J: "<<j<<endl;
				grafo << j+1<< " -- " << i+1 <<";"<< endl;
			}
	grafo<< "}"<<endl;
	grafo.close();
	system("D: & cd Graphviz & cd bin & dot T9_GrafoAMP.dot -o T9_GrafoAMP.png -Tpng & T9_GrafoAMP.png");
}

// -Función que ayuda a que no haya ciclos en la matriz de amplitud
bool aristaNOCreaCicloAMP(int **MP, int n, int i){
	int suma = 0;
	//cout<<"entre arista con i "<<i<<endl;
	for (int j=0; j<i ;j++){
		//cout<<" I: "<<i<<" J: "<<j<<" = "<<MP[i][j]<<endl;
		suma += MP[i][j];
	}
	//cout<<"SUMA = "<<suma<<endl;
	if (suma <= 1){
		return false;
	}
	else
		return true;
}

// -Función principal del ejercicio C
void busquedaAmplitud(int **M, int n){
	int **MA=new int *[n];
	for(int i=0; i<n;i++){
		MA[i]=new int[n];
    }
	CompletarCeros(MA, n);
	for (int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			//cout<<" I: "<<i<<" J: "<<j<<endl;
			if (M[i][j] == 1){
				MA[i][j] = 1;
				simetria(MA, n);
				if (aristaNOCreaCicloAMP(MA, n, j)){
					//cout<<" PINTA 0 ";
					MA[i][j] = 0;
					MA[j][i] = 0;
					//cout<<MA[i][j];
					//mostrar(MA, n);
				}
			}
		}
	}
	cout<<"Mostrando matriz de amplitud "<<endl;
	mostrar(MA, n);
	grafoAMP(MA, n);
	for(int i=0;i<n;i++){
		delete [] MA[i];
	}
	delete [] MA;
}

////////////////////////////////////////////////////////////////////////
int main(){
    int n;
    cout<<"Ingrese n: ";cin>>n;
	int **M=new int *[n];
	for(int i=0; i<n;i++){
		M[i]=new int[n];
    }

	actividadA(M, n);
	busquedaProfun(M, n);
	busquedaAmplitud(M, n);

    for(int i=0;i<n;i++){
		delete [] M[i];
	}
	delete [] M;
	return 0;
}