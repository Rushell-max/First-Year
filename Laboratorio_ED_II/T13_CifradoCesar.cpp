/*//////////////   GUIA CIFRADO DE CESAR   //////////////////////////////

    -RUSHELL VANESSA ZAVALAGA OROZCO    */

/*////////////////          ACTIVIDADES           /////////////////////
    
    a) Implemente el cifrado de César considerando las siguientes características:
        
        a. En la entrada el algoritmo debe considerar tanto el archivo de texto plano (texto claro)
            así como el factor de desplazamiento K. (k puede tomar valores entre 1 y 25)
        b. La salida debe ser el archivo cifrado.

    b) Implemente el algoritmo de descifrado de Cesar.

    c) Aplicar la técnica de fuerza bruta para desencriptar un mensaje.

        a. La entrada debe ser un archivo cifrado. (Un párrafo completo)
        b. Establezca un grupo de palabras claves que apoyen el proceso de descifrado. Esta
            entrada también debe ser un archivo de texto plano. (Artículos, palabras más usadas,
            diccionario, etc.)
        c. La salida debe ser el archivo descifrado, además del factor k.

*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

// FUNCIONES BASE Y COMPLEMENTARIAS

// Función para entrar en un array de char el abecedario en minusculas
void FormarAbecedarioMin(char *abecedarioMin){
    int cont=0;
    for(char i='a'; i<='z'; i++){
        abecedarioMin[cont]=i;
        cout<<"   "<<cont<<"  ->  "<<i<<endl;
        cont++;
    }
}

// Función para entrar en un array de char el abecedario en mayusculas
void FormarAbecedarioMay(char *abecedarioMay){
    int cont=0;
    for(char i='A'; i<='Z'; i++){
        abecedarioMay[cont]=i;
        cout<<"   "<<cont<<"  ->  "<<i<<endl;
        cont++;
    }
}

// Función que llama a las otras dos.
void FORMAR_ABECEDARIO_COM(char *abecedarioMin, char *abecedarioMay){
    FormarAbecedarioMin(abecedarioMin);
    FormarAbecedarioMay(abecedarioMay);
}

// Funcion que retorna la posición en el abecedario de una letra.
int encontrarPosicion(char *abecedarioMin, char *abecedarioMay, char letra){
    for(int i=0; i<26; i++){
        if(abecedarioMin[i]==letra){
            return i;
        }else if(abecedarioMay[i]==letra){
            return i;
        }
    }
    return 0;
}

// Función que retorna el tamaño de una cadena
int num(char *a, int cont, int i){
    if (a[i] == '\0'){
        return cont;
    }else{
        cont++;
        i++;
        return num(a, cont, i);
    }
}

//     A                                    ///////////////////////
/* 	a) Implemente el cifrado de César considerando las siguientes características:
        
        a. En la entrada el algoritmo debe considerar tanto el archivo de texto plano (texto claro)
            así como el factor de desplazamiento K. (k puede tomar valores entre 1 y 25)
        b. La salida debe ser el archivo cifrado.
*/

// Función que cifra letra con factor k
void cifrarLetra(char *abecedarioMin, char *abecedarioMay, int factor, char letra){
    for(int i=0; i<26; i++){
        if(abecedarioMin[i]==letra){
            int total = (i+factor)%26;
            //cout<<"   "<<letra<<"  ->  "<<abecedarioMin[total]<<endl;
            cout<<abecedarioMin[total];
            return;
        }else if(abecedarioMay[i]==letra){
            int total = (i+factor)%26;
            //cout<<"   "<<letra<<"  ->  "<<abecedarioMay[total]<<endl;
            cout<<abecedarioMay[total];
            return;
        }
    }cout<<letra;
    //cout<<"   "<<letra<<"  ->  "<<letra<<endl;
}

// Función que cifra cadena con factor k, esta llama a cifrar por letra.
void cifrarCadena(char *abecedarioMin, char *abecedarioMay, int factor, char *cadena){
    //cout<<num(cadena, 0, 0)<<" "<<endl;
    for (int i=0; i<num(cadena, 0, 0); i++){
        cifrarLetra(abecedarioMin, abecedarioMay, factor, cadena[i]);
    }
}

// Función que recibe texto o frase que va cifrar
void ingresarParaCifrar(ifstream &archivo, int factor, char *abecedarioMin, char *abecedarioMay){
	archivo.open("D:\\projects\\Laboratorio ED\\T13_CifCesarDesci.txt");
    char cadena[100];

    while(!archivo.eof()){
        archivo.getline(cadena, 1000);
        //cout<<cadena<<"  ->  ";
        cifrarCadena(abecedarioMin, abecedarioMay, factor, cadena);
        cout<<endl;
    }
}

//     B                                    ///////////////////////
/* 	b) Implemente el algoritmo de descifrado de Cesar. */

// Función para descifrar letra con factor k
void descifrarLetra(char *abecedarioMin, char *abecedarioMay, int factor, char letra){
    for(int i=0; i<26; i++){
        if(abecedarioMin[i]==letra){
            int total = (i-factor);
            if (total < 0 ){
                total = 26+total;
            }//cout<<"   "<<letra<<"  ->  "<<abecedarioMin[total]<<endl;
            cout<<abecedarioMin[total];
            return;
        }else if(abecedarioMay[i]==letra){
            int total = (i-factor);
            if (total < 0 ){
                total = 26+total;
            }//cout<<"   "<<letra<<"  ->  "<<abecedarioMay[total]<<endl;
            cout<<abecedarioMay[total];
            return;
        }
    }cout<<letra;
    //cout<<"   "<<letra<<"  ->  "<<letra<<endl;
}

// Función para descifrar una cadena con factor k, esta llama a descifrar por letra.
void descifrarCadena(char *abecedarioMin, char *abecedarioMay, int factor, char *cadena){
    //cout<<num(cadena, 0, 0)<<" "<<endl;
    for (int i=0; i<num(cadena, 0, 0); i++){
        descifrarLetra(abecedarioMin, abecedarioMay, factor, cadena[i]);
    }
}

// Función que recibe texto o frase que se va descifrar
void ingresarParaDescifrar(ifstream &archivo, int factor, char *abecedarioMin, char *abecedarioMay){
	archivo.open("D:\\projects\\Laboratorio ED\\T13_CifCesarCi.txt");
    char cadena[100];

    while(!archivo.eof()){
        archivo.getline(cadena, 1000);
        //cout<<cadena<<"  ->  ";
        descifrarCadena(abecedarioMin, abecedarioMay, factor, cadena);
        cout<<endl;
    }
}

//     C                                    ///////////////////////
/* 	c) Aplicar la técnica de fuerza bruta para desencriptar un mensaje.

        a. La entrada debe ser un archivo cifrado. (Un párrafo completo)
        b. Establezca un grupo de palabras claves que apoyen el proceso de descifrado. Esta
            entrada también debe ser un archivo de texto plano. (Artículos, palabras más usadas,
            diccionario, etc.)
        c. La salida debe ser el archivo descifrado, además del factor k.
*/

// Función para desencriptar un mensaje por fuerza bruta.
void desencriptarC(ifstream &archivo, ifstream &archivo2, char *abecedarioMin, char *abecedarioMay){
    archivo.open("D:\\projects\\Laboratorio ED\\T13_CifCesarAyuda.txt");
    archivo2.open("D:\\projects\\Laboratorio ED\\T13_CifCesarC.txt");
    char cadena[100];
    char cadena1[100];
    int factor;

    int *total;
    while(!archivo2.eof()){
        archivo2>>cadena;
        for(int j =0 ; j<26; j++){
            for (int i=0; i<num(cadena, 0, 0); i++){
                int posicion = encontrarPosicion(abecedarioMin, abecedarioMay, cadena[i]);
                total[i] = (posicion + j)%26;
            }
            archivo.close();
            archivo.open("D:\\projects\\Laboratorio ED\\T13_CifCesarAyuda.txt");
            while(!archivo.eof()){
                archivo>>cadena1;
                int contador = 0;
                for (int i=0; i<num(cadena, 0, 0); i++){
                    if(total[i] == encontrarPosicion(abecedarioMin, abecedarioMay, cadena1[i])){
                        contador++;
                    }
                }
                if(contador == num(cadena, 0, 0)){
                    factor=j%26;
                    cout<<" EL FACTOR K es : "<<26-factor<<endl;
                    archivo2.close();
                    archivo2.open("D:\\projects\\Laboratorio ED\\T13_CifCesarC.txt");
                    char cadena3[100];

                    while(!archivo2.eof()){
                        archivo2.getline(cadena3, 1000);
                        //cout<<cadena3<<"  ->  ";
                        cifrarCadena(abecedarioMin, abecedarioMay, factor, cadena3);
                        cout<<endl;
                    }
                    return;
                }
            }
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    ///// BASE /////////////////////
    ifstream archivo, archivo2, archivo3, archivo4;
    int factor;
    char abecedarioMin[26], abecedarioMay[26];
    FORMAR_ABECEDARIO_COM(abecedarioMin, abecedarioMay);

    // Implemente el cifrado de César
    do{
        cout<<"\n>> FACTOR DE DESPLAZAMIENTO CIFRAR . . . ";cin>>factor;
    }while(factor>25 || factor<1);

    cout<<">> CADENA CIFRADA "<<endl<<endl;
    ingresarParaCifrar(archivo, factor, abecedarioMin, abecedarioMay);


    // Implemente el descifrado de César
    do{
        cout<<"\n>> FACTOR DE DESPLAZAMIENTO DESCIFRAR . . . ";cin>>factor;
    }while(factor>25 || factor<1);

    cout<<">> CADENA DESCIFRADA "<<endl<<endl;
    ingresarParaDescifrar(archivo2, factor, abecedarioMin, abecedarioMay);

    // Ejercicio C, desencriptar un mensaje por fuerza bruta.
    cout<<"\n>> CADENA DESCIFRADA . . . "<<endl;
    desencriptarC(archivo3, archivo4, abecedarioMin, abecedarioMay);
    cout<<endl;
    return 0;
}