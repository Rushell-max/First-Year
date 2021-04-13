#include <iostream>

using namespace std;

float funcionObje(float x, float y){
    return 8*x + 10*y;
}	

float primerfunX(float y){
    float x = (144 - 8*y) / 9;
    return x;
}

float primerfunY(float x){
    float y = (144 - 9*x) / 8;
    return y;
}

float segundfunX(float y){
    float x = (100 - 8*y) / 5;
    return x;
}

float segunfunY(float x){
    float y = (100 - 5*x) / 8;
    return y;
}

int main(){
    float x = 0;
    float y = 0;
    int empleaMax = 144;
    int horasMax=1000;
    float *vector;
    vector = new float[3];
    float *vectory;
    vectory = new float[3];

    vector[0] = 0;
    vectory[0] = segunfunY(vector[0]);

    vectory[1] = 0;
    vector[1] = primerfunX(vectory[1]);

    vector[2] = 11;
    vectory[2] = primerfunY(vector[2]) ;

    float mayor=0;
    for(int i=0; i<3; i++){
        if(funcionObje(vector[i], vectory[i])> mayor){
            mayor = funcionObje(vector[i], vectory[i]);
        }
    }
    cout<<"La solución optima es: "<<mayor; 
}


