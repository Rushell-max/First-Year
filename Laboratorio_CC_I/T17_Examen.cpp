/* ///////////////////////  TERCER EXAMEN ////////////////////////////////////////////7

    Nombre:  Rushell Vanessa Zavalaga Orozco
    CUI: 20202227

*/
/*            EJERCICIOS

    1. Teniendo en cuenta la POO, implementar un programa que resuelva el siguiente problema:
 
        Cada vez que se empieza un partido, el programa debe "elegir" un número de cuatro cifras (sin cifras repetidas), 
        que será el código que el jugador debe adivinar en la menor cantidad de intentos posibles. Cada intento 
        consiste en una propuesta de un código posible que tipea el jugador, y una respuesta del programa. 
        Las respuestas le darán pistas al jugador para que pueda deducir el código. Estas pistas indican cuán cerca 
        estuvo el número propuesto de la solución a través de dos valores: 
            - La cantidad de aciertos es la cantidad de dígitos que propuso el jugador que también están en el código 
            en la misma posición. 
            - La cantidad de coincidencias es la cantidad de dígitos que propuso el jugador que también están en el código 
            pero en una posición distinta.
        
        Por ejemplo, si el código que eligió el programa es el 2607, y el jugador propone el 1406, el programa le debe 
        responder un acierto (el 0, que está en el código original en el mismo lugar, el tercero), y una coincidencia 
        (el 6, que también está en el código original, pero en la segunda posición, no en el cuarto como fue propuesto). 
        Si el jugador hubiera propuesto el 3591, habría obtenido como respuesta ningún acierto y ninguna coincidencia, 
        ya que no hay números en común con el código original, y si se obtienen cuatro aciertos es porque el jugador 
        adivinó el código y ganó el juego.
    

        2. Se desea realizar una aplicación informática que sirva para capturar e imprimir los datos de facturas por la 
        venta de aparatos electrónicos. Como programador orientado a objetos Ud. ya habrá deducido que debe crear una 
        clase factura. Dicha clase debe contener los siguientes datos:
            - Número de factura.
            - Aparatos que se vendieron, ese aparato podría ser un TV o un equipo de sonido.
            - Costo de cada aparato electrónico.
            - Porcentaje de descuento.
            - Fecha de la factura.
            - Importe o monto total de la venta.
        La clase factura debe contener los siguientes métodos:
            - Constructor.
            - ingresar_datos.
            - mostrar_datos.
            - Un método para buscar la información de un determinado aparato electrónico realizando la búsqueda por medio 
            del código.

IMPLEMENTAR HERENCIA Y POLIMORFISMO EN LA SOLUCIÓN Y COMENTAR ABAJO DEL PROGRAMA UNA BREVE DESCRIPCIÓN DE EN QUÉ 
CASOS UTILIZÓ AMBOS MECANISMOS.
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;


bool adivino(int * numero, int *numero2){
    int aciertos=0, coinci = 0;
    for(int i=0; i<4; i++){   
        if(numero[i] == numero2[i]){
            aciertos++;
        }
    }
    for(int i=0; i<4; i++){  
        for(int j = 0; j<4; j++){
            if(i != j && numero[i] == numero2[j]){
                coinci++;
            }
        }
    }
    if (aciertos == 4){
        return true;
    }else{
        cout<<" >> HAY "<<aciertos<<" ACIERTO(S) "<<endl;
        cout<<" >> HAY "<<coinci<<" COINCIDENCIA(S) "<<endl;
        return false;
    }
}

void ejercicio1(){
    int *numero, *entrada;
    numero = new int[4];
    entrada = new int[4];
    srand(time(NULL));
    for(int i=0; i<4; i++){
        numero[i]= rand() %10;
    }
    
    do{
        cout<<" >> INGRESE NUMERO . . ."<<endl;
        for(int i =0; i<4; i++){
            cout<<" >> Ingrese digito nro "<<i+1<<" : ";cin>>entrada[i];
        }
    }while(!adivino(numero, entrada));

}



class Aparatos{
    public:
        string *nombres[5];
        float *costos[5];
        //int cant;
        Aparatos(string *, float *);
        virtual void mostrar(int );
};

Aparatos :: Aparatos(string *nombres1, float* costos1){
    *nombres = nombres1;
    *costos = costos1;
}

void Aparatos::mostrar(int cant){
    for(int i=0; i<cant; i++){
        cout<<" Aparato nro "<<i+1<<": "<<endl;
        cout<<"   > Nombre: "<<nombres[i]<<endl;
        cout<<"   > Costo : "<<costos[i]<<endl;
    }
}

class Factura : public Aparatos{
    private:
        int numero;
        float descuento;
        int fecha;
        float importe;
        int cant;
    public:
        Factura(string *, float *, int, int, float, int, float);
        void buscarAparato(string*);
        void mostrar();
};

Factura::Factura (string *nombres1, float* costos1, int cant, int numero1, float descuento1, int fecha1, float importe1) : Aparatos(nombres1, costos1){
    numero = numero1;
    descuento =descuento1;
    fecha =fecha1;
    importe=importe1;
}

void Factura::mostrar(){
    cout<<"   > Numero:     "<<numero<<endl;
    cout<<"   > Descuento:  "<<descuento<<"% "<<endl;
    cout<<"   > Fecha:      "<<fecha<<endl;
    cout<<"   > Importe:    "<<importe<<endl;
    Aparatos::mostrar(cant);
}

void Factura::buscarAparato(string *cadena1){
    for(int i=0; i<cant; i++){
        if( cadena1 == nombres[i]){
            cout<<"   >> ENCONTRADO "<<endl;
            cout<<"     > Nombre: "<<nombres[i];
            cout<<"     > Costo: "<<costos[i];
            cout<<endl;
            return;
        }
    }
    cout<<"  >> No se encontró el aparato electronico "<<endl;
}

void ejercicio2(){
    Factura *Facturas[3];
    int opc, i = 0;
    
    do{
        cout<<"\n 1 >> CREAR FACTURA NUEVA \n";
        cout<<" 2 >> MOSTRAR FACTURAS \n";
        cout<<" 3 >> BUSCAR APARATO ELECTRONICO \n";
        cout<<" 4 >> Salir\n";
        cout<<"\n\n  OPCION . . . "; cin>>opc;
        if(opc==1){
            string *nom;
            float *costo;
            int descuento, importe, fecha, cant;
            cout<<"\n FACTURA NUEVA >> "<<endl;
            cout<<"   > Cant. aparatos electronicos: ";cin>>cant;
            for(int j=0; j<cant; j++){
                cout<<"     "<<j<<"> Nombre: "; cin>>nom[j];
                cout<<"      > Costo: "; cin>>costo[j];
            }
            cout<<"   > Fecha:     ";cin>>fecha;
            cout<<"   > Importe:   ";cin>>importe;
            cout<<"   > Descuento: ";cin>>descuento;
            cout<<endl;
            Facturas[i]=new Factura(nom, costo, cant, i, descuento, fecha, importe);
            i++;
        }
        else if(opc==2){
            cout<<"\n LISTA DE FACTURAS >>>>>>>>>>>>>>>>>>>>>>>>> \n";
            for(int j=0; j<i; j++){
                cout<<"\n   FACTURA "<<j+1<<" >> "<<endl;
                Facturas[i]->mostrar();
                cout<<endl;
            }
        }
        else if(opc==3){
            string *cadena;
            int entero;
            cout<<" INGRESE NOMBRE DEL APARATO . . . ";cin>>cadena[1];    
            for(int j=0; j<i; j++){
                Facturas[i]->buscarAparato(cadena);
            }        
        }
    }while(opc!=4);


}



int main(){
    ejercicio1();
    ejercicio2();
}

/* Utilice herencia y polimorfismo en el segundo problema, polimorfismo en mostrar la factura 
    y mostrar la lista de los aparatos electronicos y herencia en que factura heredaba la lista 
    de los aparatos. */