/*//////////////   GUIA ALGORITMOS DE ARBOL GENERADORES MIN // LABORATORIO 8   //////////////////////////////

    -Nombre Completo: RUSHELL VANESSA ZAVALAGA OROZCO 
	-CUI: 20202227	
	-Email (Institucional):  rzavalaga@unsa.edu.pe
	-Fecha: 19 de octubre 2020	
	-Sección: A y B
	-Docente: Dra. Roxana Flores Quispe /Dr. Yuber Elmer Velazco Paredes

*/
/*////////////////          ACTIVIDADES                    ///////////////////////////////////////

	a) Generar un grafo seudo aleatorio sin lazos (.dot) dado n vértices 
		con las posibilidades de salvar los datos. 

    b) Mediante el algoritmo de Prim, encontrar el árbol recubridor 
		mínimo

    c) Mediante el algoritmo de Kruskal, encontrar el árbol recubridor mínimo.
*/

#include <iostream>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

//     A                                    ///////////////////////
/*	a) Generar un grafo seudo aleatorio sin lazos (.dot) dado n vértices 
		con las posibilidades de salvar los datos. 
*/

// - Función para completar una matriz con 0's
void CompletarCeros(int **&M, int  nV){
	for(int i=0; i< nV;i++)
		for(int j=0; j< nV;j++)
 			M[i][j]=0;
}

// - Generar el camino básico
void caminoBas(int **&M, int  nV){
	for(int i = 1 ; i <  nV-1 ; i++){
        M[i][i+1] = rand() % 10;
    }
}

// - Agregar enlaces aleatoriamente.
void aleatorio(int **&M, int  nV){
	for(int i = 1 ; i <  nV ; i++)
		for(int j = i ; j <  nV ; j++)
			if(M[i][j] == 0 && i!=j)
				M[i][j] = rand() % 10;
			
}

// -Función que mantiene la simetria en la matriz
void simetria(int **&M, int  nV){
	for(int i = 1 ; i <  nV ; i++)
		for(int j = i ; j <  nV ; j++)
			M[i][j] = M[j][i];
}

// Función ingreso de datos
void ingresar(int **&M, int n){
	for(int i=1; i<n; i++){
		for (int j=1; j<i ; j++){
			cout<<"I: "<<i<<" J: "<<j;
			cin>>M[i][j];
		}
	}
	simetria(M, n);
}

// Funcion para crear la matriz
void crearMatriz(int **&M, int  nV){
	M = new int*[ nV];
	for(int i = 0 ; i <  nV ; i++){
        M[i] = new int[ nV];
    }

    CompletarCeros(M,  nV);

    for(int x = 1 ; x <  nV ; x++){
    	M[0][x] = x;
		M[x][0] = x;
	}
}

// -Función para mostrar una matriz
void mostrarMAT(int **&M, int  nV){
    for(int i=0; i< nV;i++){
        for(int j=0; j< nV;j++)
            cout<<M[i][j]<<"\t";
        cout<<endl;
    }
}

// - Función para visualizar el grafo base 
void mostrar(int **&matriz, int  nV){
    ofstream archivo;
    archivo.open("D:\\projects\\Laboratorio ED II\\Graphviz\\bin\\T10_GrafoBASE.dot");
    archivo << "graph B {\n";
    for(int x=1;x< nV;x++){
        archivo << x << ";\n";
    }
    for(int i=1;i< nV;i++){
        for(int j=i;j< nV;j++){
            if(matriz[i][j]!=0){
                archivo << matriz[i][0] << "--" << matriz[0][j] <<"[label="<<matriz[i][j]<<"]"<<";\n";
            }
        }
    }
    archivo << "\n}";
    archivo.close();
    system("D: & cd Graphviz & cd bin & dot T10_GrafoBASE.dot -o T10_GrafoBASE.png -Tpng & T10_GrafoBASE.png");
}

// -Función principal que acoge tofo el ejercicio A
void actividadA(int **&M, int  nV){
    srand(time(NULL));
	crearMatriz(M,  nV);
	//caminoBas(M,  nV);
	//aleatorio(M , nV);
    ingresar(M, nV);
	//simetria(M,  nV);
    cout << "\n>>MATRIZ DE ADYACENCIA DEL GRAFO . . .\n";
	mostrarMAT(M , nV);
    mostrar(M,  nV);
}

/////////////////////////********************* ///////////////////////

// Función para eliminar matriz
void borrarMatriz(int **&M, int n){
    for(int i=0; i<n; i++)
        delete [] M[i];
    delete [] M;
}

// Funcion para los pesos totales
void pesos(int **&M, int  nV){
	int peso = 0;
	for(int i=1; i< nV; i++){
		for(int j=i; j< nV; j++){
			peso += M[i][j];
		}
	}
	cout<<"\n >>PESO TOTAL DEL GRAFO : "<<peso<<endl;
}

// Función para mostrar el grafo PRIM
void mostrarP(int **&M, int  nV){
    ofstream archivo;
    archivo.open("D:\\projects\\Laboratorio ED II\\Graphviz\\bin\\T10_GrafoPRIM.dot");
    archivo << "graph B {\n";
    for(int i = 1 ; i <  nV ; i++){
        archivo << i << ";\n";
    }
    for(int i = 1 ; i <  nV ; i++){
        for(int j = i ; j <  nV ; j++){
            if(M[i][j]!=0){
                archivo << M[i][0] << "--" << M[0][j] <<"[label="<<M[i][j]<<"]"<<";\n";
            }
        }
    }
    archivo << "\n}";
    archivo.close();
    system("D: & cd Graphviz & cd bin & dot T10_GrafoPRIM.dot -o T10_GrafoPRIM.png -Tpng & T10_GrafoPRIM.png");
}

// Función para mostrar el grafo Kruskall
void mostrarK(int **&M, int  nV){
    ofstream archivo;
    archivo.open("D:\\projects\\Laboratorio ED II\\Graphviz\\bin\\T10_GrafoKRUSKAL.dot");
    archivo << "graph B {\n";
    for(int i = 1 ; i <  nV ; i++){
        archivo << i << ";\n";
    }
    for(int i = 1 ; i <  nV ; i++){
        for(int j = i ; j <  nV ; j++){
            if(M[i][j]!=0){
                archivo << M[i][0] << "--" << M[0][j] <<"[label="<<M[i][j]<<"]"<<";\n";
            }
        }
    }
    archivo << "\n}";
    archivo.close();
    system("D: & cd Graphviz & cd bin & dot T10_GrafoKRUSKAL.dot -o T10_GrafoKRUSKAL.png -Tpng & T10_GrafoKRUSKAL.png");
}

//////////////////////// ******************** ///////////////////////

//     B                                    ///////////////////////
/* b) Mediante el algoritmo de Prim, encontrar el árbol recubridor 
	mínimo.*/

// Estructura arista
struct arista{
	int inicio;
	int final;
	int valor;
};

typedef struct arista Arista;

// Funcion para crear la arista
Arista crearArista(int inicio,int final,int valor){
	Arista nuevaArista;
	nuevaArista.inicio = inicio;
	nuevaArista.final = final;
	nuevaArista.valor = valor; 
	return nuevaArista;
}

// Función que crea un vector y lo llena con 0
void crearVec(int *&vector, int num){
	vector = new int[num];
	for(int i = 0 ; i < num ; i++)
		vector[i] = 0;
}

// Función que crea un vector de estructuras y lo llena de acuerdo a la matriz
void vecArista(int **&M,int  nV, Arista *&vector){
	int x = 0;
	for(int i = 1; i< nV ; i++){
		for(int j = i ; j< nV ; j++){
			if(M[i][j] != 0){
				vector[x] = crearArista(i, j , M[i][j]);
				x++;
			}	
		}
	}
}

// Función que cuenta las aristas de la matriz generada
int contadorArs(int **M,int  nV){
	int contador = 0;
	for(int i = 1 ; i <  nV ; i++){
        for(int j = i ; j <  nV ; j++){
			if(M[i][j] != 0){
				contador++;
            }
        }
	}
	return contador;        	
}

// Función que ayuda 
bool usados(int  nV,int num, int *usado){
	for(int i=0;i< nV-1;i++){
		if(usado[i]==num)
			return true;
	}
	return false;
}

// Funcion que busca el menor
Arista menor(Arista *aristas,int nA,int *usado, int  nV){
	Arista MenorAri;
	MenorAri = crearArista(60,60,60);
	for(int i=0;i<nA;i++)
		if(aristas[i].valor < MenorAri.valor)
			if(usados( nV,aristas[i].inicio,usado) && !usados( nV,aristas[i].final,usado)){
				MenorAri.inicio = aristas[i].inicio;
				MenorAri.final = aristas[i].final;
				MenorAri.valor = aristas[i].valor;
			}
			else if(!usados( nV,aristas[i].inicio,usado) && usados( nV,aristas[i].final,usado)){
				MenorAri = aristas[i];
				MenorAri.inicio = aristas[i].final;
				MenorAri.final = aristas[i].inicio;
				MenorAri.valor = aristas[i].valor;
			}
	return MenorAri;
}

// Función para construir el grafo con PRIM
void arb_prim(int contador,int **&prim,int *&usado,Arista *aristas,int  nV,int nA,int v1,int x){	
	Arista elegido;
	if(contador !=  nV-2){	
		if(!usados( nV, v1, usado)){	
			usado[x]=v1;
			x++;
			elegido = menor(aristas,nA,usado, nV);
			prim[elegido.inicio][elegido.final] = elegido.valor;
			prim[elegido.final][elegido.inicio] = elegido.valor;
			contador++;
			arb_prim(contador,prim,usado,aristas, nV,nA,elegido.final,x);	
		}                                                       
	}
	else if(contador== nV-2){
		return;
	}
}

// FUNCION PRINCIPAL B
void PRIM(int **&M, int  nV){
	int **prim, *usedP;

	int nA = contadorArs(M ,  nV);
	Arista *aristas = new Arista[nA];

    vecArista(M , nV,aristas);
	
    crearVec(usedP,  nV-1);
    crearMatriz (prim ,  nV);
	arb_prim(0,prim,usedP,aristas, nV,nA,1,0);
	
    cout <<"\n>>MATRIZ DE ARBOL CON ALGORITMO PRIM . . .\n";
	mostrarMAT(prim, nV);
	pesos(prim,  nV);
	mostrarP(prim, nV);

	borrarMatriz(prim,  nV);
	delete[] usedP;
	delete[] aristas;
}

//     C                                    ///////////////////////
/*c) Mediante el algoritmo de Kruskal, encontrar el árbol recubridor mínimo.
*/

// Funcion de busqueda (complemento funcion tiene ciclo)
int buscar(int subconjunto[], int v){
	if(subconjunto[v] == 0)
		return v;
	return buscar(subconjunto, subconjunto[v]);
}

// Funcion complementaria de tiene ciclo
void unir(int subconjunto[], int v1, int v2){
	int v1CONJ = buscar(subconjunto, v1);
	int v2CONJ = buscar(subconjunto, v2);

	subconjunto[v1CONJ] = v2CONJ;
}

// Función de consulta pregunta si tiene ciclo o no
bool tieneCICLO(int **M, int  nV){
	int * subconjunto = (int*)malloc( nV * sizeof(int));

	memset(subconjunto, 0, sizeof(int) *  nV);

	for(int i = 1; i <  nV; i++){
		for(int j = i; j <  nV; j++){
			if(M[i][j] != 0){
				int v1 = buscar(subconjunto, i);
				int v2 = buscar(subconjunto, j);

				if(v1 == v2){
					return true;
				}
				else
					unir(subconjunto, v1, v2);
			}
		}
	}
	return false;
}

// Función para construir el grafo con KRUSKALL
void arb_kruskall(int **M, int **&kruskall, int  nV){
	int cont=1;
	int contador = 0;

	do {
		for(int i=1; i< nV; i++){
			for(int j=i; j< nV; j++){
				if (M[i][j] == cont){
					kruskall[i][j] = M[i][j];
					kruskall[j][i] = kruskall[i][j];
					contador++;
					if (tieneCICLO(kruskall,  nV)){
						kruskall[i][j] = 0;
						kruskall[j][i] = 0;
						contador--;
					}
				}
			}
		}
		cont++;
	}while(contador !=  nV-2);
}

// FUNCION PRINCIPAL C
void KRUSKALL(int **&M, int  nV){
	int **kruskall;
	crearMatriz(kruskall,  nV);

	arb_kruskall(M, kruskall,  nV);
	cout <<"\n>>MATRIZ DE ARBOL CON ALGORITMO KRUSKALL . . .\n";
	mostrarMAT(kruskall,  nV);
	pesos(kruskall,  nV);
	mostrarK(kruskall,  nV);

	borrarMatriz(kruskall,  nV);
}

///////////////////////////////////////////////////////////////////
int main(){
	int **M,  nV;
	cout << ">> Numero inicial de VERTICES: "; cin >>  nV;
	 nV++;

    actividadA(M,  nV);
	//PRIM(M,  nV);
	//KRUSKALL(M,  nV);

	borrarMatriz(M,  nV);
	return 0;
}