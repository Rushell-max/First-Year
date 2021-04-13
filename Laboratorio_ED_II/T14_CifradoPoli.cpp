/*//////////////   GUIA CIFRADO POLIALFABETICO  //////////////////////////////

    -RUSHELL VANESSA ZAVALAGA OROZCO    
*/
/*////////////////          ACTIVIDADES           /////////////////////

    A) Cifrado de César 
        a) Generar las frecuencias de letras por lo menos tres archivos de texto plano. 
        b) Usando la tabla de frecuencias, romper un archivo cifrado (César) 
    
    B)  Cifrado de Vigenère 
        c) Implemente el cifrado de Vigenère considerando las siguientes características: 
            a. En la entrada el algoritmo debe considerar tanto el archivo de texto plano 
                (texto claro) así como la palabra clave. 
            b. La salida debe ser el archivo cifrado. 

        d)  Implemente el algoritmo de descifrado de Vigenère 

*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

void descifrarLetra(int factor, char letra, int n, char *abecedarioMay, char *abecedarioMin);

// FUNCIONES BASE Y COMPLEMENTARIAS

// Función que devuelve un puntero a un array de char donde contiene el abecedario en minusculas (sin ñ)
char *FormarAbecedarioMinSin(){
    char * abecedarioMin = new char[26];
    int cont=0;
    for(char i='a'; i<='z'; i++){
        abecedarioMin[cont]=i;
        cont++;
    }
    return abecedarioMin;
}

// Función que devuelve un puntero a un array de char donde contiene el abecedario en mayusculas (sin ñ)
char *FormarAbecedarioMaySin(){
    char * abecedarioMay = new char[26];
    int cont=0;
    for(char i='A'; i<='Z'; i++){
        abecedarioMay[cont]=i;
        cont++;
    }return abecedarioMay;
}

// MATRIZ VIGENERE

// Función que devuelve letra cifrada con Cesar
char cifrarLetraCesar(char letra, int factor, int n, char *abecedarioMay){
    for(int i=0; i<n; i++){
        if(abecedarioMay[i]==letra){
            int total = (i+factor)%n;
            return abecedarioMay[total];
        }
    }return letra;
}

// Función para crear la Matriz de Vigenere
char **CrearMatriz(int n, char *abecedarioMay){
    char **M =  new char *[n];
    for (int i=0; i<n; i++){
        M[i]=new char[n];
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            M[i][j] = cifrarLetraCesar(abecedarioMay[j], i, n, abecedarioMay);
        }
    }
    return M;
}

// Función para mostrar la matriz
void mostrar(char **M, int n){
    cout<<"  >> MOSTRANDO MATRIZ . . . "<<endl;
	for(int i=0; i<n;i++){
        cout<<"        ";
		for(int j=0; j<n;j++){
 			cout<<M[i][j]<<"  ";
        }
  		cout<<endl;
 	}
}

//     A                                    ///////////////////////
/* 	A) Cifrado de César 
        a) Generar las frecuencias de letras por lo menos tres archivos de texto plano. 
        b) Usando la tabla de frecuencias, romper un archivo cifrado (César) 
*/

// Función que muestra el array de las frecuencias
void mostrarFrecuencias(int *Frecuencias, int n, char *abecedarioMay){
    cout<<"\n   >> MOSTRANDO FRECUENCIAS "<<endl;
    for(int i=0; i<n; i++){
        cout<<"  "<<abecedarioMay[i]<<"  ->  "<<Frecuencias[i]<<endl;
    }
    cout<<endl;
}

// Función que devuelve un array de enteros las cuales son las frecuencias
int *Frecuencias(ifstream &archivo, char *abecedarioMay, char *abecedarioMin, int n){
    char cadena[1000];

    int * Frecuencias = new int[n];
    for(int i=0; i<n; i++){
        Frecuencias[i]=0;
    }

    while(!archivo.eof()){
        archivo.getline(cadena, 1000);
        int i=0;
        while(cadena[i]!= '\0'){
            for(int j=0; j<n; j++){
                if(abecedarioMin[j]==cadena[i] || abecedarioMay[j]==cadena[i]){
                    Frecuencias[j]++;
                }
            }
            i++;
        }    
    }
    return Frecuencias; 
}

// Función que halla el mayor de un array (Frecuencias)
int Mayor(int *Frecuencias, int n, char *AbecedarioMay){
    int *factores;
    int mayor = Frecuencias[0];
    for(int i=0; i<n; i++){
        if(Frecuencias[i] > mayor){
            mayor = Frecuencias[i];
        }
    }
    return mayor;
}

// Función que halla la posición del mayor de un array (Frecuencias)
int Posicion(int *Frecuencias, int n, char *AbecedarioMay){
    int *factores;
    int mayor = Frecuencias[0], posicion = 0;
    for(int i=0; i<n; i++){
        if(Frecuencias[i] > mayor){
            mayor = Frecuencias[i];
            posicion = i;
        }
    }
    return posicion;
}

// Función Bool de ayuda para saber si en un array existe ya algun elemento
bool esta(int factor, int *factores, int i){
    for(int j=0; j<i; j++)
        if(factores[j] == factor)
            return true;
    return false;
}

// Función que devuelve un array de enteros (posibles factores)
int *factores(int *Frecuencias, int *Frecuencias1, int *Frecuencias2, int *Frecuencias3, int n, char *abecedarioMay){
    int *factores;
    factores = new int[5];
    int cont = 0;
    for(int cont=0; cont<5; cont++){
        if(Mayor(Frecuencias1, n, abecedarioMay) >= Mayor(Frecuencias2, n, abecedarioMay) && Mayor(Frecuencias1, n, abecedarioMay) >= Mayor(Frecuencias3, n, abecedarioMay)){
            factores[cont] = Posicion(Frecuencias, n, abecedarioMay) - Posicion(Frecuencias1, n, abecedarioMay);
            Frecuencias1[Posicion(Frecuencias1, n, abecedarioMay)] = 0;
            if (factores[cont] < 0 ){
                factores[cont] = n+factores[cont];
            }if(esta(factores[cont], factores, cont)){
                cont--;
            }
        }else if(Mayor(Frecuencias2, n, abecedarioMay) >= Mayor(Frecuencias1, n, abecedarioMay) && Mayor(Frecuencias2, n, abecedarioMay) >= Mayor(Frecuencias3, n, abecedarioMay)){
            factores[cont] = Posicion(Frecuencias, n, abecedarioMay) - Posicion(Frecuencias2, n, abecedarioMay);
            Frecuencias2[Posicion(Frecuencias2, n, abecedarioMay)] = 0;
            if (factores[cont] < 0 ){
                factores[cont] = n+factores[cont];
            }if(esta(factores[cont], factores, cont)){
                cont--;
            }
        }else if(Mayor(Frecuencias3, n, abecedarioMay) >= Mayor(Frecuencias1, n, abecedarioMay) && Mayor(Frecuencias3, n, abecedarioMay) >= Mayor(Frecuencias2, n, abecedarioMay)){
            factores[cont] = Posicion(Frecuencias, n, abecedarioMay) - Posicion(Frecuencias3, n, abecedarioMay);
            Frecuencias3[Posicion(Frecuencias3, n, abecedarioMay)] = 0;
            if (factores[cont] < 0 ){
                factores[cont] = n+factores[cont];
            }if(esta(factores[cont], factores, cont)){
                cont--;
            }
        }
    }
    return factores;
}

// Función principal para romper el cifrado
void romperCifrado(ifstream &archivo,ifstream &archivo1,ifstream &archivo2,ifstream &archivo3, char *abecedarioMay, char *abecedarioMin, int n){
    cout<<"\n  >>>>>>>>>>>>>>>>> ROMPER CIFRADO CESAR  >>>>>>>>>>>>>>>>>>>>>>"<<endl;
    int *frecuencias = Frecuencias(archivo, abecedarioMay, abecedarioMin, n);
    int *frecuencias1 = Frecuencias(archivo1, abecedarioMay, abecedarioMin, n);
    int *frecuencias2 = Frecuencias(archivo2, abecedarioMay, abecedarioMin, n);
    int *frecuencias3 = Frecuencias(archivo3, abecedarioMay, abecedarioMin, n);
    char cadena[100];
    mostrarFrecuencias(frecuencias, n, abecedarioMay);

    //mostrarFrecuencias(frecuencias1, n, abecedarioMay);
    //mostrarFrecuencias(frecuencias2, n, abecedarioMay);
    //mostrarFrecuencias(frecuencias3, n, abecedarioMay);
    int fact, opc, cont=0;
    int *Factores = new int[5];
    Factores = factores(frecuencias, frecuencias1, frecuencias2, frecuencias3, n , abecedarioMay);

    cout<<"  >> POSIBLES FACTORES . . . "<<endl;
    for(int i=0; i<5;i++){
        cout<<"     > "<<Factores[i]<<endl;
    }cout<<endl;

    do{
    fact = Factores[cont];
    cout<<"  >> PROBANDO CON FACTOR "<<fact<<endl<<endl;

    archivo.close();
    archivo.open("D:\\projects\\Laboratorio ED\\T14_TextoCif.txt");
    while(!archivo.eof()){
        archivo.getline(cadena, 1000);
        int i=0;
        cout<<"      ";
        while(cadena[i] != '\0'){
            descifrarLetra(fact, cadena[i], n, abecedarioMay, abecedarioMin);
            i++;
        }cout<<endl;
    }archivo.close();
    cout<<endl;
    cout<<"  >> El descriframiento es correcto? (1/Si)(2/No) . . . ";cin>>opc;
    cout<<endl;
    cont++;
    }while(opc == 2);
}


//     B                                    ///////////////////////
/*  B)  Cifrado de Vigenère 
        c) Implemente el cifrado de Vigenère considerando las siguientes características: 
            a. En la entrada el algoritmo debe considerar tanto el archivo de texto plano 
                (texto claro) así como la palabra clave. 
            b. La salida debe ser el archivo cifrado. 
        d)  Implemente el algoritmo de descifrado de Vigenère 
*/

// CIFRADO DE VIGENERE

// Función que cifra letra segun Vigenere
void cifrarLetra(int factor, char letra, int n, char *abecedarioMay, char *abecedarioMin){
    for(int i=0; i<n; i++){
        if(abecedarioMin[i]==letra){
            int total = (i+factor)%n;
            cout<<abecedarioMin[total];
            return;
        }else if(abecedarioMay[i]==letra){
            int total = (i+factor)%n;
            cout<<abecedarioMay[total];
            return;
        }
    }cout<<letra;
}

// Función que cifra cadena segun Vigenere, esta llama a cifrar letra
void cifrarCadena(char *mensaje, char *clave, char **Vig, int n, char *abecedarioMay, char *abecedarioMin){
    int i = 0, cont1, k = 0;
    while (mensaje[i] != '\0'){
        for(int j=0; j<n; j++){
            if( clave[k] == '\0'){
                k=0;
            }if(abecedarioMay[j] == clave[k]){
                cont1 = j;
            }
        }
        //cout<<cont1<<" "<<mensaje[i]<<" "<<n<<" "<<clave[k]<<endl;
        cifrarLetra(cont1, mensaje[i], n, abecedarioMay, abecedarioMin);
        i++;
        k++;
    }
}

// Función que recibe el archivo a cifrar y la clave.
void ingresarParaCifrar(ifstream &archivo, char *clave, char **Vig, int n, char *abecedarioMay, char *abecedarioMin){
    char cadena[100];
    cout<<"\n    >> TEXTO CIFRADO CON LA CLAVE "<<clave<<endl<<endl;

    while(!archivo.eof()){
        archivo.getline(cadena, 1000);
        cout<<"        ";
        cifrarCadena(cadena, clave, Vig, n, abecedarioMay, abecedarioMin);
        cout<<endl;
    }
    cout<<endl;
}

// DESCIFRADO DE VIGENERE

// Función que descifra letra segun Vigenere
void descifrarLetra(int factor, char letra, int n, char *abecedarioMay, char *abecedarioMin){
    for(int i=0; i<n; i++){
        if(abecedarioMin[i]==letra){
            int total = (i-factor);
            if (total < 0 ){
                total = n+total;
            }cout<<abecedarioMin[total];
            return;
        }else if(abecedarioMay[i]==letra){
            int total = (i-factor);
            if (total < 0 ){
                total = n+total;
            }cout<<abecedarioMay[total];
            return;
        }
    }cout<<letra;
}

// Función que descifra cadena segun Vigenere, esta llama a descifrar letra
void descifrarCadena(char *mensaje, char *clave, char **Vig, int n, char *abecedarioMay, char *abecedarioMin){
    int i = 0, cont1, k = 0;
    while(mensaje[i] != '\0'){
        for(int j=0; j<n; j++){
            if( clave[k] == '\0'){
                k=0;
            }if(abecedarioMay[j] == clave[k]){
                cont1 = j;
            }
        }
        descifrarLetra(cont1, mensaje[i], n, abecedarioMay, abecedarioMin);
        i++;
        k++;
    }
}

// Función que recibe el archivo a descifrar y la clave.
void ingresarParaDescifrar(ifstream &archivo, char *clave, char**Vig, int n, char *abecedarioMay, char *abecedarioMin){
    char cadena[100];

    cout<<"\n    >> TEXTO DESCIFRADO CON LA CLAVE "<<clave<<endl<<endl;
    while(!archivo.eof()){
        archivo.getline(cadena, 1000);
        cout<<"        ";
        descifrarCadena(cadena, clave, Vig, n, abecedarioMay, abecedarioMin);
        cout<<endl;
    }
    cout<<endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){

    // BASE
    int n = 26;
    ifstream archivo, archivo1, archivo2, archivo3;
    char *abecedarioMay = FormarAbecedarioMaySin();
    char *abecedarioMin = FormarAbecedarioMinSin();
    
    // MATRIZ VIGENERE
    //cout<<" >> INGRESE N: ";cin>>n;
    char **Vig = CrearMatriz(n, abecedarioMay);
    mostrar(Vig, n);

    char *clave = "CIELO"; 
    //cout<<"  >> INGRESE CLAVE (Mayusculas): ";cin.getline(clave, 1000);

    // CIFRAR VIGENERE    
    archivo.open("D:\\projects\\Laboratorio ED\\T14_Vigclaro.txt");
    ingresarParaCifrar(archivo, clave, Vig, n, abecedarioMay, abecedarioMin);
    archivo.close();

    // DESCIFRAR VIGENERE    
    archivo.open("D:\\projects\\Laboratorio ED\\T14_VigCif.txt");
    ingresarParaDescifrar(archivo, clave, Vig, n, abecedarioMay, abecedarioMin);
    archivo.close();
    
    // ROMPER CIFRADO CESAR
    archivo1.open("D:\\projects\\Laboratorio ED\\T14_Texto1.txt");
    archivo2.open("D:\\projects\\Laboratorio ED\\T14_Texto2.txt");
    archivo3.open("D:\\projects\\Laboratorio ED\\T14_Texto3.txt");
    archivo.open("D:\\projects\\Laboratorio ED\\T14_TextoCif.txt");
    romperCifrado(archivo, archivo1, archivo2, archivo3, abecedarioMay, abecedarioMin, n);
    archivo.close();
    archivo1.close();
    archivo2.close();
    archivo3.close();
}