//////////////////  PRACTICA 6   /////////////////////////////
/*
 // RUSHELL VANESSA ZAVALAGA OROZCO
*/
/////////////////  EJERCICIOS  //////////////////////////////
/*
    1. Ingresar y mostrar los elementos de una matriz.
    2. Hallar el promedio de los valores guardados en la matriz.
    3. Hallar el valor más alto contenido en la matriz.
    . Hallar el menor elemento de cada fila de una matriz y 
        colocarlos en un vector.
    5. Hallar el mayor elemento de cada columna de una matriz y 
        colocarlos en un vector.
    6. Sumar los elementos de la diagonal secundaria.
    7. Hallar el mayor elemento de la diagonal principal y el 
        menor de la diagonal secundaria.
    8. En un concurso de Artes Marciales se tiene la siguiente Tabla:

     Participante  // Peleas  //  Kata  // Rotura de Maderas // Total
        0               9.5         10.7            11.2          12.14
        1               13.4        14.5            15.1          16.10
        2               17.2        18.1            19.3          20.6
        3               21.5        22.2            23.1          24.8
    
     Cree un programa que permita llenar la tabla, e imprimir:

        • El ganador en Peleas.
        • El ganador en Kata.
        • El ganador en rotura de Maderas.
        • El Ganador General del Torneo.
*/

#include <iostream>

using namespace std;

//          1           //////////////////////////////
//  1. Ingresar y mostrar los elementos de una matriz.

void ingresar(int Ma[][10], int fi,int co){
    cout<<"Ingrese valores: "<<endl;
    for(int i=0; i<fi;i++){
        for(int j=0; j<co; j++){
            cin >> Ma[i][j];
        }
    }
}

void mostrar(int Ma[][10], int fi,int co){
    for(int i=0; i<fi;i++){
        for(int j=0; j<co;j++)
            cout<<Ma[i][j]<<" ";
    cout<<endl;
    }
}

//          2           ///////////////////////////////////////
// 2. Hallar el promedio de los valores guardados en la matriz.

float promedio(int Ma[][10], int fi,int co){
    float suma=0;
    float promedio;
    for(int i=0; i<fi;i++){
        for(int j=0; j<co;j++){
            suma += Ma[i][j];
        }
    }
    promedio = suma / (fi*co);
    return promedio; 
}

//       3        /////////////////////////////////////
//  3. Hallar el valor más alto contenido en la matriz.

float mayor(int Ma[][10], int fi,int co){
    float may=Ma[0][0];
    for(int i=0; i<fi;i++){
        for(int j=0; j<co;j++){
            if (Ma[i][j] >= may){
                may=Ma[i][j];
            }
        }
    }
    return may;
}

//     4          /////////////////////////////////////
//  4. Hallar el menor elemento de cada fila de una 
//      matriz y colocarlos en un vector.

void menorF(int Ma[][10], int Men[], int fi, int co){
    int contador = 0;
    for(int i=0; i<fi;i++){
        float menor = 10000;
        for(int j=0; j<co;j++){
            if (Ma[i][j] <= menor){
                menor = Ma[i][j];
            }
        }
        Men[contador] = menor;
        contador++;
    }
}

//       5        ///////////////////////////////////////////////
//    5. Hallar el mayor elemento de cada columna de una matriz y 
//        colocarlos en un vector.

void mayorC(int Ma[][10], int May[], int Pos[], int fi, int co){
    int contador = 0;
    int pos;
    for(int i=0; i<co;i++){
        float mayor = 0;
        for(int j=0; j<fi;j++){
            if (Ma[j][i] >= mayor){
                mayor = Ma[j][i];
                pos = j;
            }
        }
        May[contador] = mayor;
        Pos[contador] = pos; //Para hacer el ejercicio 8
        contador++;
    }
}

//       6        ///////////////////////////////////
//  6. Sumar los elementos de la diagonal secundaria.

float sumaDiagS(int Ma[][10], int fi, int co){
    int cont = fi-1;
    float suma = 0;
    for (int i=0; i<co; i++){
        suma += Ma[cont][i];
        cont--;
    }
    return suma;
}

//  7                     ///////////////////////////////////
//   7. Hallar el mayor elemento de la diagonal principal y el 
//        menor de la diagonal secundaria.

float mayorDiagP(int Ma[][10], int fi, int co){
    float mayor = Ma[0][0];
    for (int i=0 ; i<fi ; i++){
        if (Ma[i][i] >= mayor){
            mayor = Ma[i][i];
        }
    }
    return mayor;
}

float menorDiagS(int Ma[][10], int fi, int co){
    int cont = fi-1;
    float menor = Ma[fi-1][0];
    for (int i=0; i<co; i++){
        if (Ma[cont][i]<= menor)
            menor = Ma[cont][i];
        cont--;
    }
    return menor;
}

//  8                     ///////////////////////////////////////////
//  8. En un concurso de Artes Marciales se tiene la siguiente Tabla:

/* Participante  // Peleas  //  Kata  // Rotura de Maderas // Total
    0                 5          7               2             14
    1                 4          5               1             10
    2                 2          1               3             6
    3                 5          2               1             8
*/

/* Cree un programa que permita llenar la tabla, e imprimir:

    • El ganador en Peleas.
    • El ganador en Kata.
    • El ganador en rotura de Maderas.
    • El Ganador General del Torneo.
*/
void ingresar8(int Ma[][10], int fi,int co){
    int suma;
    string categorias[] ={"Peleas",  "Kata", "Rotura de Maderas","Total"};
    for(int i=0; i<fi;i++){
        cout<<"Participante numero "<<i+1<<endl;
        for(int j=0; j<co-1; j++){
            cout<<"Puntaje "<<categorias[j]<<"           ";
            cin >> Ma[i][j];
            suma += Ma[i][j];
            Ma[i][co-1] = suma; 
        }
        cout<<endl;
        suma = 0;
    }
}

void mostrarRes(int May[], int Pos[], int co){
    string categorias[] ={"peleas",  "kata", "rotura de maderas","general"};
    for(int i=0 ; i<co; i++){
        cout<<"El ganador "<<categorias[i]<<" es el participante numero "<<Pos[i]<<" con "<<May[i]<<" puntos"<<endl;
    }
}

int main(){
    int Ma[10][10];
    int May[10];
    int Men[10];
    int Pos[10];
    int fi = 4, co = 4; 
    

    ingresar8(Ma, fi, co);
    cout<<"Mostrando tabla: "<<endl;
    mostrar(Ma, fi, co);
    cout<<endl;

    cout<<"////////////    2    ///////////"<<endl;
    cout<<"Promedio "<<promedio(Ma, fi, co)<<endl;
    cout<<endl;

    cout<<"////////////    3    ///////////"<<endl;
    cout<<"Mayor "<<mayor(Ma, fi, co)<<endl;
    cout<<endl;

    cout<<"////////////    4    ///////////"<<endl;
    menorF(Ma, Men, fi, co);
    for (int i=0; i<fi; i++){
        cout<<"Fila "<<i<<", menor: "<<Men[i]<<endl;
    }
    cout<<endl;

    cout<<"////////////    5    ///////////"<<endl;
    mayorC(Ma, May, Pos, fi, co);  
    for (int i=0; i<co; i++){
        cout<<"Columna "<<i<<", mayor: "<<May[i]<<endl;
    }
    cout<<endl;

    cout<<"////////////    6    ///////////"<<endl;
    cout<<"Suma diagonal secundaria "<<sumaDiagS(Ma, fi, co)<<endl;
    cout<<endl;

    cout<<"////////////    7    ///////////"<<endl;
    cout<<"Mayor diagonal principal "<<mayorDiagP(Ma, fi, co)<<endl;
    cout<<"Menor diagonal secundaria "<<menorDiagS(Ma, fi, co)<<endl;
    cout<<endl;

    cout<<"////////////    8    ///////////"<<endl;
    cout<<"           RESULTADOS              "<<endl;
    mostrarRes(May, Pos, co);
}