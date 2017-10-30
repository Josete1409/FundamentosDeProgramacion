//============================================================================
// Name        : Practica4.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Implementa un programa que compruebe el funcionamiento de los módulos solicitados.
// 				 El usuario terminará la ejecución del programa cuando elija la opción 7 Salir.
// 				 Visualiza un mensaje por cada opción que elija el usuario, por ejemplo si selecciona 1,
// 				 mensaje a visualizar en pantalla: “Jugador Nuevo”, así con todas las opciones.
//============================================================================

#include <iostream>
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void pinta_laberinto (int columna, int fila, int ancho_columna, int ancho_fila);
int menu (void);


int main() {

	int opcion, columna, fila, ancho_columna, ancho_fila;

	clrscr();
	opcion=menu();

	while(opcion!=7){

		switch (opcion) {
		case 1:
			clrscr();
			cout<<"**************** Registrar jugador. ****************"<<endl;
			Sleep(2000);
			clrscr();
			break;
		case 2:
			clrscr();
			cout<<"**************** Jugador existente. ****************"<<endl;
			Sleep(2000);
			clrscr();
			break;
		case 3:
			clrscr();
			cout<<"**************** Caza de numeros pares.****************"<<endl;
			Sleep(2000);
			clrscr();
			break;
		case 4:
			clrscr();
			cout<<"**************** Caza de numeros impares. ****************"<<endl;
			Sleep(2000);
			clrscr();
			break;
		case 5:
			clrscr();
			cout<<"**************** Caza de vocales. ****************"<<endl;
			Sleep(2000);
			clrscr();
			break;
		case 6:
			clrscr();
			cout<<"**************** Mostrar fichero de jugadores. ****************"<<endl;
			Sleep(2000);
			clrscr();
			break;
		default:
			break;

		}

		if(opcion==3 || opcion==4 || opcion==5){

			cout<<"**************** Pintar Laberinto ****************"<<endl;
			Sleep(2000);
			clrscr();
			cout<<"Introduzca donde quiere que empiece la columna(0-80): "<<endl;
			cin>>columna;
			while(columna<0 || columna>80){
				cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
				cout<<"Introduzca donde quiere que empiece la columna(0-80): ";
				cin>>columna;
			}
			cout<<"Introduzca donde quiere que se empiece la fila(0-25):"<<endl;
			cin>>fila;
			while(fila<0 || fila>25){
				cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
				cout<<"Introduzca donde quiere que se empiece la fila(0-25): ";
				cin>>fila;
			}
			cout<<"Introduzca el ancho de la columna: "<<endl;
			cin>>ancho_columna;
			cout<<"Intruduzca el ancho de la fila: "<<endl;
			cin>>ancho_fila;
			pinta_laberinto(columna, fila, ancho_columna, ancho_fila);

		}
		opcion=menu();
	}

	return 0;
}

void pinta_laberinto (int columna, int fila, int ancho_columna, int ancho_fila){

	clrscr();
	if(columna+ancho_columna>80 || fila+ancho_fila>25){

		textcolor(RED);
		for (int i=columna; i<=columna+ancho_columna; i++) {

			gotoxy(i,fila);
			printf("%c", char(219));

			gotoxy(i, fila+ancho_fila);
			printf("%c", char(219));
		}

		for (int i=fila; i<=fila+ancho_fila; i++) {

			gotoxy(columna,i);
			printf("%c", char(219));

			gotoxy(columna+ancho_columna, i);
			printf("%c", char(219));
		}
		textcolor(WHITE);

	}else{

		for (int i=columna; i<=columna+ancho_columna; i++) {

			gotoxy(i,fila);
			printf("%c", char(219));

			gotoxy(i, fila+ancho_fila);
			printf("%c", char(219));
		}
		for (int i=fila; i<=ancho_fila+fila; i++) {

			gotoxy(columna,i);
			printf("%c", char(219));

			gotoxy(columna+ancho_columna,i);
			printf("%c", char(219));
		}


	}

	Sleep(5000);

}

int menu (void){

	int opcion;

	clrscr();
	cout<<"1.- Registrar jugador nuevo."<<endl;
	cout<<"2.- Jugador existente."<<endl;
	cout<<"3.- Caza de numeros pares."<<endl;
	cout<<"4.- Caza de numeros impares."<<endl;
	cout<<"5.- Caza de vocales."<<endl;
	cout<<"6.- Mostrar fichero de jugadores."<<endl;
	cout<<"7.- Fin."<<endl;
	cout<<"Introduce la opcion que desees realizar: ";
	cin>>opcion;

	while(opcion<1 || opcion>7){
		cout<<"Error, vuelva a introducir una opcion valida: ";
		cin>>opcion;
	}

	return opcion;
}
