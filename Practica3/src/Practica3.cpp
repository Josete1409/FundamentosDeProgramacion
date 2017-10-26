/*============================================================================
// Name        : Practica3.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version	   :
// Description : Escribir un programa que simule el movimiento de un carácter que el usuario
introducirá por teclado. El usuario podrá seleccionar el movimiento Horizontal o Vertical,
además podrá elegir el punto desde donde comenzará a moverse el carácter y si se mueve
hacia arriba, hacia abajo, hacia la derecha o hacia la izquierda, dependiendo del movimiento
seleccionado. Además podrá elegir el color del carácter y el número de posiciones que
deberá moverse (entre 1 y 10).
Realizar las comprobaciones:
- El color estará comprendido entre 1 y 15, el negro es el cero
- Movimiento H o V
- Si es H, podrá elegir entre L o R (Left/Right)
- Si es V, podrá elegir entre U o D (Up/Down)
- La fila estará comprendida entre 1 y 24
- La columna estará comprendida entre 1 y 79
- El número de posiciones entre 1 y 10
Tarea1:
El programador deberá asegurarse de que los datos introducidos por el usuario son correctos.
============================================================================*/

#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

using namespace std;

int main() {

	char caracter, movimientoVH, movimientoUD, movimientoLR, resp;
	int color, fila, columna, posiciones, contador, mov_fila, mov_columna;


	cout<<"Desea ejecutar el programa s/n: ";
	cin>>resp;

	while(resp!='n' && resp!='N' && resp!='s' && resp!='S'){   //Comprobamos que la respuesta sea valida y si no que lo vuelva a preguntar

		cout<<"Has introducido un caracter no valido, intentalo de nuevo."<<endl;
		cout<<"Desea ejecutar el programa s/n: ";
		cin>>resp;

	}

	if(resp=='s' || resp=='S') {

		clrscr();
		cout<<"Introduce el caracter que deseas que se mueva: ";
		cin>>caracter;

		cout<<"Elija cuantas posiciones quieres que se desplace(1-10 posiciones): ";
		cin>>posiciones;

		while(posiciones<1 || posiciones>10){ //Comprobamos que la posicion este entre 1-10 y si no es asi que lo vuelva a preguntar

			cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
			cout<<"Elija cuantas posiciones quieres que se desplace(1-10 posiciones): ";
			cin>>posiciones;

		}

		cout<<"Introduce el valor del color que desee que tenga el caracter(Entre 1 y 15): ";
		cin>>color;

		while(color<1 || color>15){ //Comprobamos que el color este entre 1-15 y si no es asi lo vuelve a preguntar

			cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
			cout<<"Introduce el valor del color que desee que tenga el caracter(Entre 1 y 15): ";
			cin>>color;

		}

		cout<<"Introduce la fila donde quieres que empiece tu caracter(fila 1-25): ";
		cin>>fila;

		while(fila<1 || fila>24){ //Comprobamos que la fila este entre 1-24 y si no es asi lo vuelve a preguntar

			cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
			cout<<"Introduce la fila donde quieres que empiece tu caracter(fila 1-25): ";
			cin>>fila;

		}

		cout<<"Introduce la columna donde quieres que empiece tu caracter(columna 1-80): ";
		cin>>columna;

		while(columna<1 || columna>79){ //Comprobamos que la columna este entre 20-100 y si no es asi lo vuelve a preguntar

			cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
			cout<<"Introduce la columna donde quieres que empiece tu caracter(columna 1-80): ";
			cin>>columna;

		}

		cout<<"Introduce que tipo de movimiento quiere realizar, horizontal-H o vertical-V(Introduce V o H): ";
		cin>>movimientoVH;

		while(movimientoVH!='v' && movimientoVH!='V' && movimientoVH!='h' && movimientoVH!='H'){ //Comprobamos que la respuesta sea valida y si no lo vuelve a preguntar

			cout<<"Has introducido un caracter no valido, intentalo de nuevo."<<endl;
			cout<<"Introduce que tipo de movimiento quiere realizar, horizontal-H o vertical-V(Introduce V o H): ";
			cin>>movimientoVH;

		}

		if(movimientoVH=='h' || movimientoVH=='H'){ //Si el mov es hor. solo se va a mover hacia la derecha o izquierda por lo que comprobamos que tipo de movimiento va a realizar.

			cout<<"Introduce hacia donde quieres que se desplace, derecha-L o izquierda-R(Introduce L o R): ";
			cin>>movimientoLR;

			while(movimientoLR!='l' && movimientoLR!='L' && movimientoLR!='r' && movimientoLR!='R'){ //Comprobamos que la respuesta sea valida y si no es asi lo vuelve a preguntar

				cout<<"Has introducido un caracter no valido, intentalo de nuevo."<<endl;
				cout<<"Introduce hacia donde quieres que se desplace, derecha-L o izquierda-R(Introduce L o R): ";
				cin>>movimientoLR;

			}

			gotoxy(columna, fila); //colocamos el cursor el las posiciones que haya querido el usuario
			textcolor(color); //cambiamos el color del texto al que haya elegido el usuario
			cout<<caracter; //mostramos por pantalla en la posicion de arriba el caracter que haya querido representar el usuario.

			if(movimientoLR=='r' || movimientoLR=='R'){

				contador=0; //inicializamos el contador a 0.

				while(contador!=posiciones){ //Mientras que el contador sea distinto de las posiciones que quiera desplazarse, el caracter se ira moviendo.

					clrscr();
					mov_columna=columna++; //En esta variable guardamos el valor de la columna que va aumentando para que asi se pueda ir desplazando ya que se desplaza hacia la derecha.
					contador=contador+1; //Sumamos 1 al contador para que pare cuando la condicion de arriba sea cierta
					gotoxy(mov_columna, fila);
					cout<<caracter;
					Beep(1000,200);
					Sleep(1000);

				}

			}else{

				contador=0;

				while(contador!=posiciones){

					clrscr();
					mov_columna=columna--;
					contador=contador+1;
					gotoxy(mov_columna, fila);
					cout<<caracter;
					Beep(1000,200);
					Sleep(1000);

				}

			}

		}else{

			cout<<"Introduce hacia donde quieres que se desplace, arriba-U o abajo-D(Introduce U o D): ";
			cin>>movimientoUD;

			while(movimientoUD!='u' && movimientoUD!='U' && movimientoUD!='d' && movimientoUD!='D'){

				cout<<"Has introducido un caracter no valido, intentalo de nuevo."<<endl;
				cout<<"Introduce hacia donde quieres que se desplace, arriba-U o abajo-D(Introduce U o D): ";
				cin>>movimientoUD;

			}

			gotoxy(columna, fila);
			textcolor(color);
			cout<<caracter;

			if(movimientoUD=='d' || movimientoUD=='D'){

				contador=0;

				while(contador!=posiciones){

					clrscr();
					mov_fila=fila++;
					contador=contador+1;
					gotoxy(columna, mov_fila);
					cout<<caracter;
					Beep(1000,200);
					Sleep(1000);

				}

			}else{

				contador=0;

				while(contador!=posiciones){

					clrscr();
					mov_fila=fila--;
					contador=contador+1;
					gotoxy(columna, mov_fila);
					cout<<caracter;
					Beep(1000,200);
					Sleep(1000);

				}

			}

		}

	}

	textcolor(WHITE);

	return 0;
}

