#include <iostream>

using namespace std;

//clase Figura.h
class Figura{
    protected:
        float x;
    public:
        Figura(float);
        virtual float Perimetro();
        virtual float Area();
};

//clase Figura.cpp
Figura :: Figura(float x){
    this->x = x;
}

//clase Circulo.h
class Circulo:Figura{
    public:
        Circulo(float);
        float Perimetro() { return (float)2*3.14*x ;}
        float Area() { return (float) 3.14*x*x ; }
};

//clase Cuadrado.h
class Cuadrado:Figura{
    public:
        Cuadrado(float, float, float);
        float Perimetro() {return (float) 4*x; }
        float Area() {return (float) x*x; }
};
