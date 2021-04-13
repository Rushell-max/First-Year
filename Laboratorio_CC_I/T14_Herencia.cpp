/*//////////////   HERENCIA // TAREA PERSONAL  //////////////////////////////

    -RUSHELL VANESSA ZAVALAGA OROZCO 
*/
/*////////////////          ACTIVIDADES        ///////////////////////////////////////

    COMPLETAR EL PROGRAMA, AÑADIENDO LAS CLASES PROFESOR Y ADMINISTRATIVO QUE HEREDEN TAMBIÉN DE PERSONA,
    AGREGAR EJEMPLOS DE USO (CREANDO OBJETOS ALUMNO, PROFESOR, ADMINISTRATIVO, AGREGÁNDOLOS A UNA LISTA DE ALUMNOS,
    O PROFESORES O ADMINISTRATIVOS, MOSTRAR LOS LISTADOS).
*/

#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// PERSONA
class Persona{
    protected:
        string nombre;
        int edad;
    public:
        Persona(string, int);
        void mostrar();
};

Persona::Persona(string n,int e){
    nombre=n;
    edad=e;
}

// ALUMNO
class Alumno:public Persona{
    protected:
        string especialidad;
    public:
        Alumno(string,int,string);
        string getNombre() { return nombre ;}
        int getEdad() { return edad ;}
        string getEspecialidad() { return especialidad ;}
};

Alumno::Alumno(string n,int e,string esp):Persona(n,e){
    especialidad=esp;
}

// PROFESOR
class Profesor:public Persona{
    protected:
        string especialidad;
    public:
        Profesor(string,int,string);
        string getNombre() { return nombre ;}
        int getEdad() { return edad ;}
        string getEspecialidad() { return especialidad ;}
};

Profesor::Profesor(string n,int e,string esp):Persona(n,e){
    especialidad=esp;
}

// ADMINISTRATIVO
class Administrativo:public Persona{
    protected:
        string especialidad;
    public:
        Administrativo(string,int,string);
        string getNombre() { return nombre ;}
        int getEdad() { return edad ;}
        string getEspecialidad() { return especialidad ;}
};

Administrativo::Administrativo(string n,int e,string esp):Persona(n,e){
    especialidad=esp;
}

//////////////////////////////////////////////////////////////////////////////////
int main(){
    Alumno *ListaAlumnos[10];
    Profesor *ListaProfesores[10];
    Administrativo *ListaAdministrativos[10];
    int opc, cont1 = 0, cont2 = 0, cont3 = 0;
    
    do{
        cout<<"\n 1 >> AGREGAR ALUMNO \n";
        cout<<" 2 >> AGREGAR PROFESOR \n";
        cout<<" 3 >> AGREGAR ADMINISTRATIVO \n";
        cout<<" 4 >> VER LISTA DE ALUMNOS \n";
        cout<<" 5 >> VER LISTA DE PROFESORES \n";
        cout<<" 6 >> VER LISTA DE ADMINISTRATIVOS \n";
        cout<<" 7 >> SALIR >> \n";
        cout<<"\n\n  OPCION . . . "; cin>>opc;
        if(opc==1){
            string nom, especialidad;
            int edad;
            cout<<"\n ALUMNO NUEVO >> "<<endl;
            cout<<"   > Nombre:       ";cin>>nom;
            cout<<"   > Edad:         ";cin>>edad;
            cout<<"   > Especialidad: ";cin>>especialidad;
            cout<<endl;
            ListaAlumnos[cont1]=new Alumno(nom, edad , especialidad);
            cont1++;
        }else if(opc==2){
            string nom, especialidad;
            int edad;
            cout<<"\n PROFESOR NUEVO >> "<<endl;
            cout<<"   > Nombre:       ";cin>>nom;
            cout<<"   > Edad:         ";cin>>edad;
            cout<<"   > Especialidad: ";cin>>especialidad;
            cout<<endl;
            ListaProfesores[cont2]=new Profesor(nom, edad , especialidad);
            cont2++;
        }else if(opc==3){
            string nom, especialidad;
            int edad;
            cout<<"\n ADMINISTRATIVO NUEVO >> "<<endl;
            cout<<"   > Nombre:       ";cin>>nom;
            cout<<"   > Edad:         ";cin>>edad;
            cout<<"   > Especialidad: ";cin>>especialidad;
            cout<<endl;
            ListaAdministrativos[cont3]=new Administrativo(nom, edad , especialidad);
            cont3++;
        }else if(opc==4){
            cout<<"\n LISTA DE ALUMNOS >>>>>>>>>>>>>>>>>>>>>>>>> \n";
            for(int j=0; j<cont1; j++){
                cout<<"\n   ALUMNO "<<j+1<<" >> "<<endl;
                cout<<"     > Nombre:         "<<ListaAlumnos[j]->getNombre()<<endl;
                cout<<"     > Edad:           "<<ListaAlumnos[j]->getEdad()<<endl;
                cout<<"     > Especialidad:   "<<ListaAlumnos[j]->getEspecialidad()<<endl;
                cout<<endl;
            }
        }else if(opc==5){
            cout<<"\n LISTA DE PROFESORES >>>>>>>>>>>>>>>>>>>>>>>>> \n";
            for(int j=0; j<cont2; j++){
                cout<<"\n   PROFESOR "<<j+1<<" >> "<<endl;
                cout<<"     > Nombre:         "<<ListaProfesores[j]->getNombre()<<endl;
                cout<<"     > Edad:           "<<ListaProfesores[j]->getEdad()<<endl;
                cout<<"     > Especialidad:   "<<ListaProfesores[j]->getEspecialidad()<<endl;
                cout<<endl;
            }
        }else if(opc==6){
            cout<<"\n LISTA DE ADMINISTRATIVOS >>>>>>>>>>>>>>>>>>>>>>>>> \n";
            for(int j=0; j<cont3; j++){
                cout<<"\n   ADMINISTRATIVO "<<j+1<<" >> "<<endl;
                cout<<"     > Nombre:         "<<ListaAdministrativos[j]->getNombre()<<endl;
                cout<<"     > Edad:           "<<ListaAdministrativos[j]->getEdad()<<endl;
                cout<<"     > Especialidad:   "<<ListaAdministrativos[j]->getEspecialidad()<<endl;
                cout<<endl;
            }
        }
    }while(opc!=7);

    return 0;
}