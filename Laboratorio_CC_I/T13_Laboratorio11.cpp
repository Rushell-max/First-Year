#include <iostream>

using namespace std;

class cuenta{
    private:
        double numero_Cuenta, monto;

    public:
        void setNumero_Cuenta(double);
        double getNumero_Cuenta();
        void setMonto(double);
        double getMonto();

        void depositar(double x);
        bool girar(double x);
        double consultar();
};

void cuenta::setNumero_Cuenta(double x){
      numero_Cuenta=x;
}

double cuenta::getNumero_Cuenta(){
    return numero_Cuenta;
}

void cuenta::setMonto(double x){
        monto=x;
}

double cuenta::getMonto(){
    return monto;
}

void cuenta::depositar(double x){
    cout<<" >> DEPOSITANDO . . . ";
    monto = x + monto;
}

bool cuenta::girar(double x){
    if(monto - x > 0){
        return true;
    }
    return false;
}

double cuenta::consultar(){
    cout<<" >> MONTO EN LA CUENTA ";
    return monto;
}

void ejercicio5(){
    cuenta cuenta1;
    //double numero_Cuenta, monto;
    cuenta1.setNumero_Cuenta(1);
    cuenta1.setMonto(1000);
    cout<<cuenta1.consultar();
    cuenta1.depositar(500);
    cout<<cuenta1.consultar();
    if(cuenta1.girar(2000)){
        cout<<" >> Saldo suficiente para retirar ";
    }else{
        cout<<" >> Sin saldo suficiente ";
    }
    
    if(cuenta1.girar(100)){
        cout<<" >> Saldo suficiente para retirar ";
    }else{
        cout<<" >> Sin saldo suficiente ";
    }
}

class Fraccion{
    private:
        float numerador, denominador;
    public:
        void setDenominador(float);
        void setNumerador(float);
        float getNumerador();
        float getDenominador();

        Fraccion sumar(Fraccion, Fraccion);
        void mostrar();
        Fraccion simplificar();
};

void Fraccion::setDenominador(float x){
      denominador=x;
}

float Fraccion::getDenominador(){
    return denominador;
}

void Fraccion::setNumerador(float x){
        numerador=x;
}

float Fraccion::getNumerador(){
    return numerador;
}

void Fraccion::mostrar(){
    cout<<" >> FRACCION "<<endl;
    cout<<"  "<<numerador<<endl;
    cout<<" --"<<endl;
    cout<<"  "<<denominador<<endl;
}

Fraccion Fraccion::sumar(Fraccion Fraccion1, Fraccion Fraccion2){
    Fraccion Fraccion3;
    float num, den;
    den= Fraccion1.getDenominador()*Fraccion2.getDenominador();
    //cout<<"den "<<den<<endl;
    num = den*((Fraccion1.getNumerador()/Fraccion1.getDenominador())+(Fraccion2.getNumerador()/Fraccion2.getDenominador()));
    //cout<<"den "<<num<<endl;
    int num1=num, den1=den;
    Fraccion3.setNumerador(num);
    Fraccion3.setDenominador(den);
    Fraccion3.mostrar();
    cout<<num1<<" "<<den1<<endl;
    cout<<num1 / den1<<" "<<den1 / num1<<endl;
    while(num1 / den1 != 0 || den1 / num1!= 0){
        Fraccion3.simplificar();
    }
    Fraccion3.mostrar();
    return Fraccion3;
}

Fraccion Fraccion::simplificar(){
    Fraccion Fraccion1;
    int num, den, num1, den1;
    num =numerador;
    den = denominador;
    if(num / den == 0){
        num1 = num % den;
    }else if(den / num == 0){
        den1 = den % num;
    }
    Fraccion1.setNumerador(num1);
    Fraccion1.setDenominador(den1);
    return Fraccion1;
}

void ejercicio7(){
    Fraccion Fraccion1, Fraccion2, Fraccion3;

    Fraccion1.setNumerador(5);
    Fraccion1.setDenominador(8);
    Fraccion1.mostrar();

    Fraccion2.setNumerador(4);
    Fraccion2.setDenominador(3);
    Fraccion2.mostrar();

    Fraccion3.sumar(Fraccion1, Fraccion2);
    //Fraccion3.mostrar();
    //Fraccion3.simplificar(Fraccion3);
}






int main(){
    ejercicio5();
    //ejercicio7();
}
