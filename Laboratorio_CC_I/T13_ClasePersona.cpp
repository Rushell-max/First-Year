/*//////////////   CLASES // TAREA PERSONAL  //////////////////////////////

    -RUSHELL VANESSA ZAVALAGA OROZCO 
*/
/*////////////////          ACTIVIDADES                    ///////////////////////////////////////

	CREAR LA CLASE PERSONA Y UTILIZARLA PARA ADMINISTRAR UNA AGENDA DE PERSONAS
    (CREAR UN NUEVO CONTACTO, MODIFICAR O ACTUALIZAR CIERTA INFORMACIÓN DE UN CONTACTO,
    LISTAR TODOS LOS CONTACTOS, BUSCAR UN CONTACTO).

*/

#include <iostream>
#include <sstream>

using namespace std;

// Clase
class Persona{
    private:
        string nombre;
        string apellido;
        int numero_contacto;

    public:
        Persona(string, string, int);
        void setNombre(string);
        void setApellido(string);
        void setNumero_contacto(int);

        string getNombre();
        string getApellido();
        int getNumero_contacto();
};

// Crear contacto
Persona::Persona(string nom, string ape, int numero){
    nombre = nom;
    apellido = ape;
    numero_contacto = numero;
}

void Persona::setNombre(string x){
    nombre = x;
}

void Persona::setApellido(string x){
    apellido = x;
}

void Persona::setNumero_contacto(int x){
    numero_contacto = x;
}

string Persona::getNombre(){
    return nombre;
}

string Persona::getApellido(){
    return apellido;
}

int Persona::getNumero_contacto(){
    return numero_contacto;
}

//////////////////////////////////////////////////////////////////
int main(){
    Persona *ListaContactos[10];
    int opc, i = 0;
    
    do{
        cout<<"\n 1 >> CREAR CONTACTO NUEVO \n";
        cout<<" 2 >> MODIFICAR INFORMACIÓN DE ALGUN CONTACTO \n";
        cout<<" 3 >> VER LISTA DE CONTACTOS \n";
        cout<<" 4 >> BUSCAR CONTACTO \n";
        cout<<" 5 >> Salir\n";
        cout<<"\n\n  OPCION . . . "; cin>>opc;
        if(opc==1){
            string nom, ape;
            int numero;
            cout<<"\n CONTACTO NUEVO >> "<<endl;
            cout<<"   > Nombre:    ";cin>>nom;
            cout<<"   > Apellido:  ";cin>>ape;
            cout<<"   > Numero:    ";cin>>numero;
            while(!(numero <1000000000 && numero > 99999999)){
                cout<<"   Numero Incorrecto! Debe tener 9 cifras "<<endl;  
                cout<<"   > Numero:    ";cin>>numero;
            }
            cout<<endl;
            ListaContactos[i]=new Persona(nom, ape , numero);
            i++;
        }
        else if(opc==2){
            string cadena;
            int entero;
            cout<<" INGRESE NOMBRE O APELLIDO DEL CONTACTO A MODIFICAR . . . ";cin>>cadena;
            for(int j=0; j<i; j++){
                if (ListaContactos[j]->getNombre() == cadena || ListaContactos[j]->getApellido() == cadena){
                    cout<<"   >> Información a cambiar (1/Nombre)(2/Apellido)(3/Numero) . . . ";cin>>entero;
                    if(entero == 1){
                        cout<<"     > Ingrese nombre nuevo: ";cin>>cadena;
                        ListaContactos[j]->setNombre(cadena);
                    }else if(entero == 2){
                        cout<<"     > Ingrese apellido nuevo: ";cin>>cadena;
                        ListaContactos[j]->setApellido(cadena);
                    }else if(entero == 3){
                        cout<<"     > Ingrese número nuevo: "; cin>>entero;
                        while(!(entero <1000000000 && entero > 99999999)){
                            cout<<"     ¡Numero Incorrecto! Debe tener 9 cifras "<<endl;  
                            cout<<"     > Ingrese número nuevo: ";cin>>entero;
                        }  
                        ListaContactos[j]->setNumero_contacto(entero);
                    }
                }
            }
        }
        else if(opc==3){
            cout<<"\n LISTA DE CONTACTOS >>>>>>>>>>>>>>>>>>>>>>>>> \n";
            for(int j=0; j<i; j++){
                cout<<"\n   CONTACTO "<<j+1<<" >> "<<endl;
                cout<<"     > Nombre:    "<<ListaContactos[j]->getNombre()<<endl;
                cout<<"     > Apellido:  "<<ListaContactos[j]->getApellido()<<endl;
                cout<<"     > Numero:    "<<ListaContactos[j]->getNumero_contacto()<<endl;
                cout<<endl;
            }
        }
        else if(opc==4){
            string cadena;
            int entero = 0;
            cout<<" INGRESE NOMBRE O APELLIDO DEL CONTACTO BUSCADo (si no se conoce = 0) . . . ";cin>>cadena;
            if (cadena == "0"){
                cout<<" INGRESE NUMERO . . . ";cin>>entero;
            }
            for(int j=0; j<i; j++){
                if (ListaContactos[j]->getNombre() == cadena || ListaContactos[j]->getApellido() == cadena || ListaContactos[j]->getNumero_contacto() == entero){
                    cout<<"\n   ENCONTRADO! "<<endl;
                    cout<<"   CONTACTO "<<j+1<<" >> "<<endl;
                    cout<<"     > Nombre:    "<<ListaContactos[j]->getNombre()<<endl;
                    cout<<"     > Apellido:  "<<ListaContactos[j]->getApellido()<<endl;
                    cout<<"     > Numero:    "<<ListaContactos[j]->getNumero_contacto()<<endl;
                    cout<<endl;
                }
            }
        }
    }while(opc!=5);

    return 0;
}