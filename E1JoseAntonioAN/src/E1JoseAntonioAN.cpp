//============================================================================
// Name        : E1JoseAntonioAN.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : El usuario introducirá un número entero comprendido en el intervalo [1,10]
//				 (comprobar), si el número introducido es par, mostrará en pantalla tantos
//				 cuadritos (char(219)) rojos en posiciones aleatorias (columna entre 1 y 79, fila entre 1 y 24)
//				 como el número introducido, si es impar mostrará 3 cuadritos verdes empezando en la columna 10,
//				 fila 10 hacia la derecha y dejando un espacio entre ellos.
//============================================================================

#include <iostream>
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

#define maxcolumna 79
#define maxfila 24

int main() {

	char resp;
	int num, columna, fila, contador;

	cout<<"Primera entrega de fundamentos de programacion."<<endl;
	cout<<"Jose Antonio Alvarez Nieto"<<endl;
	cout<<"Desea ejecutar el programa? S/N: "<<endl;
	cin>>resp;
	resp=toupper(resp);

	while(resp!='N' && resp!='S'){

		cout<<"Has introducido un caracter no valido, intentalo de nuevo."<<endl;
		cout<<"Desea ejecutar el programa? S/N: ";
		cin>>resp;
		resp=toupper(resp);

	}

	while(resp=='S'){

		srand(time(NULL));

		cout<<"Introduzca un numero entre 1-10: "<<endl;
		cin>>num;

		while(num<1 || num>10){

			cout<<"Has introducido un valor fuera de rango, vuelva a introducir otra cifra: "<<endl;
			cin>>num;

		}

		if (num%2==0) {

			clrscr();

			cout<<"NUMERO PAR"<<endl;

			contador=0;
			while(contador!=num){

				columna=rand()%maxcolumna+1;
				fila=rand()%maxfila+1;
				textcolor(RED);
				gotoxy(columna,fila);
				printf("%c", char(219));
				contador++;

			}

			Sleep(1000);
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			textcolor(WHITE);

		} else {

			clrscr();

			cout<<"NUMERO IMPAR"<<endl;

			columna=10;
			fila=10;
			contador=0;

			gotoxy(columna,fila);

			while(contador!=3){

				textcolor(GREEN);
				gotoxy(columna,fila);
				printf("%c", char(219));
				columna=columna+2;
				contador++;

			}

			Sleep(1000);
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			textcolor(WHITE);

		}

		cout<<"¿Desea ejecutar el programa? S/N: "<<endl;
		cin>>resp;
		resp=toupper(resp);
	}

	return 0;
}
