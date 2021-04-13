/*//////////////   CLASES // TRABAJO FINAL   //////////////////////////////
    
    Trabajo presentado por:

        -JOSE LUIS GUTIERREZ ANCHAPURI
        -RUSHELL VANESSA ZAVALAGA OROZCO 
        -GLEDDYNURI MARBEL PICHA CHANI
  
*/

#include <iostream>

#include <vector>

using namespace std;

// DISEÑO DE LIBRERÍAS ///////////////////////////////////////////////77

//clase Empleado.h
class Empleado{
    private:
        int nro;
        string nombre;
    public:
        Empleado(int,string);
        int getNro();
        string getNombre();
        void setNro(int);
        void setNombre(string);
};

//clase Empleado.cpp
Empleado :: Empleado(int nro,string nombre){
    this->nro = nro;
    this->nombre = nombre;
}

int Empleado :: getNro(){
    return nro;
}

string Empleado :: getNombre(){
    return nombre;
}

void Empleado :: setNro(int nro){
    this->nro = nro;
}

void Empleado :: setNombre(string nombre){
    this->nombre = nombre;
}

// CLASES CONTENEDOR ////////////////////////////////////////////////////

/* //////// SINTAXIS DE LA CLASE VECTOR (EJEMPLO DE CLASE DE CONTENEDOR)
template <class Type, class Allocator = allocator<Type>>
class vector */

void ClaseContenedor(){
   vector <int> v1;

   v1.push_back( 10 ); // Agrega un elemento al final del vector
   v1.push_back( 20 );

   const int &i = v1.at( 0 );
   int &j = v1.at( 1 );
   cout << "EL PRIMER ELEMENTO ES " << i << endl;
   cout << "EL SEGUNDO ELEMENTO ES " << j << endl;
}

// CLASE DE INTERFAZ ////////////////////////////////////////////////////

class Interfaz{
    public:
    virtual void evaluar() = 0;
};

class ImplementationClass : public Interfaz{

    public:
    void evaluar(){
        cout<<"  >> EVALUANDO "<<endl;
    }
};

void interfaz(){
    ImplementationClass inter;
    inter.evaluar();
}

//////////////////////////////////////////////////////////////////////////
class ElementoGrafico{
    public:
    virtual void setColor(double r, double g, double b) = 0;
    virtual void setPos(double xpos, double ypos) = 0;
    virtual void setLabel(string lb) = 0;
};

class LineaTexto : public ElementoGrafico{
    // IMPLEMENTACIÓN **
};

class BotonOKCancel : public ElementoGrafico{
    // IMPLEMENTACIÓN **
};

int main(){
    ClaseContenedor();
    interfaz();
}
