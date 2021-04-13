/* 8. Este programa muestra los pagos que recibirá un trabajador por cada hora laboral en base a la
hora del día en que trabaja. El usuario deberá escribir el número de horas trabajadas en cada
uno de los horarios y el programa determinará el total de dinero a recibir por el trabajador y
también dirá si ganó más dinero por horas extras que por horas de oficina trabajadas o
viceversa, o si el trabajador ganó exactamente lo mismo por horas extras que por horas de
oficina. Diálogo ejemplo:
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
/*
int main(){
	float base, a1, a2, a3, a4, HO, HE, total;

	cout<<"          HORARIO           PAGO         "<<endl;
	cout<<"                                         "<<endl;
	cout<<"     8:00 AM - 4:00 PM     PAGO BASE     "<<endl;
	cout<<"     4:00 PM - 8:00 PM     25% EXTRA     "<<endl;
	cout<<"     8:00 PM - 12:00 AM    50% EXTRA     "<<endl;
	cout<<"     12:00 AM - 8:00 AM    PAGO DOBLE    "<<endl;
	cout<<"     12:00 AM - 8:00 AM    PAGO DOBLE    "<<endl;
	cout<<endl;
	cout<<"SUELDO BASE POR HORA TRABAJADA: ";cin>>base;
    cout<<endl;
    cout<<"Número de horas trabajadas de 8:00 am a 4:00 pm: ";cin>>a1;
    cout<<"Número de horas trabajadas de 4:00 pm a 8:00 pm: ";cin>>a2;
    cout<<"Número de horas trabajadas de 8:00 pm a 12:00 am: ";cin>>a3;
    cout<<"Número de horas trabajadas de 12:00 am a 8:00 am: ";cin>>a4;
	cout<<endl;
	
	HO = base*a1;
	HE = base*a2*1.25 + base*a3*1.5 + base*a4*2;
	total= HO + HE;
	
	cout<<"EL PAGO TOTAL DEL TRABAJADOR ES: $"<<total<<endl;
	cout<<endl;
	cout<<"EL SALARIO POR HORAS DE OFICINA: $"<<HO<<endl;
	cout<<"EL SALARIO POR HORAS EXTRA: $"<<HE<<endl;
	
	if(HO==HE){
		cout<<"El trabajador gana los mismos por horas de oficina y extras "<<endl;
	}
	else{
		if (HO<HE){
			cout<<"El trabajador gana mas por horas extras que de oficina "<<endl;
		}
		else{
            cout<<"El trabajador gana mas por horas de oficina que de extras "<<endl;
		}
	}
	cout<<endl;
	system("PAUSE");
	return 0;
}
*/
/* 9. Este programa pide primeramente la cantidad total de compras de una persona. Si la cantidad
es inferior a $100.00, el programa dirá que el cliente no aplica a la promoción. Pero si la
persona ingresa una cantidad en compras igual o superior a $100.00, el programa genera de
forma aleatoria un número entero del cero al cinco. Cada número corresponderá a
un color diferente de cinco colores de bolas que hay para determinar el descuento que el
cliente recibirá como premio. Si la bola aleatoria es color blanco, no hay descuento, pero si es
uno de los otros cuatro colores, sí se aplicará un descuento determinado según la tabla que
aparecerá, y ese descuento se aplicará sobre el total de la compra que introdujo inicialmente el
usuario, de manera que el programa mostrará un nuevo valor a pagar luego de haber aplicado
el descuento */

int main(){
	float compra, azar, nuevo;
	cout<<"INTRODUZCA LA CANTIDAD TOTAL DE LA COMPRA: "; cin>>compra;
	
	if(compra>=100){
		cout<<"SU GASTO IGUALA O PASA LOS $100.00 Y POR TANTO PARTICIPA EN LA PROMOCIÓN.";
		cout<<endl;
		cout<<"           COLOR                               DESCUENTO        "<<endl;
		cout<<endl;
		cout<<"        BOLA BLANCA                             NO TIENE        "<<endl;
        cout<<"        BOLA ROJA                             10 POR CIENTO     "<<endl;
        cout<<"        BOLA AZUL                             20 POR CIENTO     "<<endl;
        cout<<"        BOLA VERDE                            25 POR CIENTO     "<<endl;
        cout<<"        BOLA AMARILLA                         50 POR CIENTO     "<<endl;
        cout<<endl;

        srand (time(NULL));
		azar = rand()%5;
		
		if(azar==1){
			cout<<"ALEATORIAMENTE USTED OBTUVO UNA BOLA BLANCA "<<endl;
			cout<<endl;
			cout<<"LO SENTIMOS!, NO OBTIENE NINGUN DESCUENTO "<<endl;
			nuevo = compra;
		}else
		    if(azar==2){
                cout<<"ALEATORIAMENTE USTED OBTUVO UNA BOLA ROJA "<<endl;
                cout<<endl;
				cout<<"FELICITACIONES HA GANADO UN 10 POR CIENTO DE DESCUENTO "<<endl;
				nuevo = compra*0.9;
			}else
			    if(azar==3){
                    cout<<"ALEATORIAMENTE USTED OBTUVO UNA BOLA AZUL "<<endl;
                    cout<<endl;
					cout<<"FELICITACIONES HA GANADO UN 20 POR CIENTO DE DESCUENTO "<<endl;
					nuevo = compra*0.8;
				}else
				    if(azar==4){
                        cout<<"ALEATORIAMENTE USTED OBTUVO UNA BOLA VERDE "<<endl;
                        cout<<endl;
						cout<<"FELICITACIONES HA GANADO UN 25 POR CIENTO DE DESCUENTO "<<endl;
						nuevo = compra*0.75;
					}else
					    if(azar==5){
                            cout<<"ALEATORIAMENTE USTED OBTUVO UNA BOLA AMARILLO "<<endl;
                            cout<<endl;
							cout<<"FELICITACIONES HA GANADO UN 50 POR CIENTO DE DESCUENTO "<<endl;
							nuevo = compra*0.5;
						}
	cout<<endl;
	cout<<"SU TOTAL A PAGAR ES: "<<nuevo<<endl;
	}
	else{
		cout<<"LO SENTIMOS, NO APLICAS PARA EL DESCUENTO "<<endl;
		}
    cout<<endl;
	system("PAUSE");
	return 0;
}
