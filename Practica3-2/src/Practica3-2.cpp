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

	char caracter, movimientoVH, movimientoUD, movimientoLR;
	int color, fila, columna, posiciones, contador, mov_fila, mov_columna, opcion;

	clrscr();

	cout<<"1.- Introducir los datos."<<endl;
	cout<<"2.- Dibujar el cuadrado."<<endl;
	cout<<"3.- Mover el caracter."<<endl;
	cout<<"4.- Fin."<<endl;
	cout<<"Introduce la opcion que desees realizar: ";
	cin>>opcion;

	while(opcion<1 || opcion>4){
		cout<<"Error, vuelva a introducir una opcion valida: ";
		cin>>opcion;
	}

	while(opcion!=4){

		textcolor(WHITE);

		switch(opcion){

		case 1:   //============================== Introducción de Datos =================================//

			clrscr();
			cout<<"Has elegido la opcion de introducir datos."<<endl;
			Sleep(1000);

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

			break;

		case 2:   //========================== Dibujo del Laberinto =================================//

			clrscr();
			cout<<"Has elegido la opcion de dibujar el cuadrado."<<endl;
			Sleep(1000);
			clrscr();

			gotoxy(50,10);
			textcolor(WHITE);
			contador=0;
			while(contador<=80){

				printf("%c", char(219));
				contador=contador+1;

			}

			gotoxy(50,35);
			contador=0;
			while(contador<80){

				printf("%c", char(219));
				contador=contador+1;
			}

			gotoxy(50,10);
			contador=0;
			mov_fila=10;
			while(contador<25){

				mov_fila=mov_fila+1;
				contador=contador+1;
				gotoxy(50,mov_fila);
				printf("%c", char(219));

			}

			gotoxy(130,10);
			contador=0;
			mov_fila=10;
			while(contador<25){

				mov_fila=mov_fila+1;
				contador=contador+1;
				gotoxy(130,mov_fila);
				printf("%c", char(219));

			}

			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			textcolor(WHITE);

			break;

		case 3:  //============================== Movimiento del caracter ================================//

			columna=columna+50;
			fila=fila+10;

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

						textcolor(BLACK);
						mov_columna=columna++; //En esta variable guardamos el valor de la columna que va aumentando para que asi se pueda ir desplazando ya que se desplaza hacia la derecha.
						gotoxy(mov_columna-1, fila);
						cout<<caracter;
						textcolor(color);
						gotoxy(mov_columna, fila);
						cout<<caracter;
						Beep(1000,200);
						Sleep(1000);
						contador=contador+1; //Sumamos 1 al contador para que pare cuando la condicion de arriba sea cierta

					}

				}else{

					contador=0;

					while(contador!=posiciones){

						textcolor(BLACK);
						mov_columna=columna--;
						gotoxy(mov_columna+1, fila);
						cout<<caracter;
						textcolor(color);
						gotoxy(mov_columna, fila);
						cout<<caracter;
						Beep(1000,200);
						Sleep(1000);
						contador=contador+1;

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

						textcolor(BLACK);
						mov_fila=fila++;
						gotoxy(columna, mov_fila-1);
						cout<<caracter;
						textcolor(color);
						gotoxy(columna, mov_fila);
						cout<<caracter;
						Beep(1000,200);
						Sleep(1000);
						contador=contador+1;

					}

				}else{

					contador=0;

					while(contador!=posiciones){

						textcolor(BLACK);
						mov_fila=fila--;
						gotoxy(columna, mov_fila+1);
						cout<<caracter;
						textcolor(color);
						gotoxy(columna, mov_fila);
						cout<<caracter;
						Beep(1000,200);
						Sleep(1000);
						contador=contador+1;

					}

				}

			}

			break;

		}

		textcolor(WHITE);

		cout<<""<<endl;
		cout<<"1.- Introducir los datos."<<endl;
		cout<<"2.- Dibujar el cuadrado."<<endl;
		cout<<"3.- Mover el caracter."<<endl;
		cout<<"4.- Fin."<<endl;
		cout<<"Introduce la opcion que desees realizar: ";
		cin>>opcion;

		while(opcion<1 || opcion>4){
			cout<<"Error, vuelva a introducir una opcion valida: ";
			cin>>opcion;
		}
	}

	textcolor(WHITE);

	return 0;
}
