//============================================================================
// Name        : Practica5.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Implementar modulos y hacer que se mueva el caracter dentro de los limites de nuestro
// 				 laberinto.
//============================================================================

/*#include <iostream>
using namespace std;

void intercambio_erroneo(int n1, int n2);
void intercambio_correcto(int & n1, int & n2);

int main() {

	int a,b;

	cout<<"direccion de memoria de la variable a:"<<&a<<endl;
	cout<<"tamanio de una variable entera:"<<sizeof(int)<<endl;
	cout<<"direccion de memoria de la variable b:"<<&b<<endl;
	cout<<"contenido en esa direccion de memoria de la variable a:"<<*&a<<endl;
	cout<<"contenido en esa direccion de memoria de la variable b:"<<*&b<<endl;

	a=8;
	b=7;
	cout<<"contenido en a despues de asignacion:"<<*&a<<endl;
	cout<<"contenido en b despues de asignacion:"<<*&b<<endl;

	intercambio_erroneo (a,b);
	cout<<"valores de a y b despues de la llamada erronea "<<a<<"  "<<b<<endl;
	intercambio_correcto(a,b);
	cout<<"valores de a y b despues de la llamada correcta "<<a<<" "<<b<<endl;

	return 0;
}

void intercambio_erroneo(int n1, int n2){

	cout<<"INTERCAMBIO ERRONEO"<<endl;
	cout<<"direccion de n1:"<<&n1<<endl;
	cout<<"direccion de n2:"<<&n2<<endl;
	int aux;
	aux = n1;
	n1= n2;
	n2= aux;
}

void intercambio_correcto(int & n1, int & n2){
	cout<<"INTERCAMBIO CORRECTO"<<endl;
	cout<<"direccion de n1:"<<&n1<<endl;
	cout<<"direccion de n2:"<<&n2<<endl;
	int aux;
	aux = n1;
	n1= n2;
	n2= aux;
}
 */

#include <iostream>
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

using namespace std;

int menu (void);
void informacion(int & columna, int & fila, int & ancho_columna, int & ancho_fila, int & x, int & y, int & color);
void pinta_laberinto (int columna, int fila, int ancho_columna, int ancho_fila);
void punto_de_partida(int x, int y, int color, int columna, int fila, int ancho_columna, int ancho_fila);
void mover(int tecla, int & x, int & y, int columna, int fila, int ancho_columna, int ancho_fila);

int main() {

	int opcion, columna, fila, ancho_columna, ancho_fila, x, y, color, tecla;

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

			informacion(columna, fila, ancho_fila, ancho_columna, x, y, color);
			punto_de_partida(x, y, color, columna, fila, ancho_fila, ancho_columna);
			mover(tecla, x, y, columna, fila, ancho_fila, ancho_columna);
		}
		opcion=menu();
	}
	return 0;
}

void ocultarCursor(){

	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon,&cci);
}

void mover(int tecla, int & x, int & y, int columna, int fila, int ancho_columna, int ancho_fila){

	ocultarCursor();

	bool game_over=false;
	while(!game_over){
		if(kbhit()){
			tecla = getch();
			gotoxy(x,y);
			printf(" ");
			if(tecla == ARRIBA && y-1>fila){
				y--;
				PlaySound(TEXT("sonido_mover.wav"),NULL,SND_ASYNC);
			}
			if(tecla == ABAJO && y+1<fila+ancho_fila){
				y++;
				PlaySound(TEXT("sonido_mover.wav"),NULL,SND_ASYNC);
			}
			if(tecla == IZQUIERDA && x-1>columna){
				x--;
				PlaySound(TEXT("sonido_mover.wav"),NULL,SND_ASYNC);
			}
			if(tecla == DERECHA && x+1<columna+ancho_columna){
				x++;
				PlaySound(TEXT("sonido_mover.wav"),NULL,SND_ASYNC);
			}
			gotoxy(x,y);
			printf("%c", char(219));

			if(tecla == 27) game_over=true; //TECLA ESC

		}
		Sleep(20);
	}

}

void informacion(int & columna, int & fila, int & ancho_columna, int & ancho_fila, int & x, int & y, int & color){

	cout<<"**************** Datos Para Dibujar el Laberinto ****************"<<endl;
	Sleep(2000);
	clrscr();

	cout<<"Introduzca donde quiere que empiece la columna(0-80): "<<endl;
	cin>>columna;
	while(columna<0 || columna>80){
		cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
		cout<<"Introduzca donde quiere que empiece la columna(0-80): "<<endl;;
		cin>>columna;
	}

	cout<<"Introduzca donde quiere que se empiece la fila(0-25):"<<endl;
	cin>>fila;
	while(fila<0 || fila>25){
		cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
		cout<<"Introduzca donde quiere que se empiece la fila(0-25): "<<endl;;
		cin>>fila;
	}

	cout<<"Introduzca el ancho de la columna: "<<endl;
	cin>>ancho_columna;

	cout<<"Intruduzca el ancho de la fila: "<<endl;
	cin>>ancho_fila;

	cout<<"Introduzca el color del caracter que quieres mover(1-15): "<<endl;
	cin>>color;
	while(color<0 || color>16){
		cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
		cout<<"Introduzca el color del caracter que quieres mover(1-15): "<<endl;;
		cin>>color;
	}

	cout<<"Introduce la coordenada inicial del caracter a mover en el eje x(Entre "<<columna<<" y "<<columna+ancho_columna<<"): "<<endl;
	cin>>x;
	while(x<columna || x>columna+ancho_columna){
		cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
		cout<<"Introduce la coordenada inicial del caracter a mover en el eje x(Entre "<<columna<<" y "<<columna+ancho_columna<<"): "<<endl;
		cin>>x;
	}

	cout<<"Introduce la coordenada inicial del caracter a mover en el eje y(Entre "<<fila<<" y "<<fila+ancho_fila<<"): "<<endl;
	cin>>y;
	while(y<fila || y>fila+ancho_fila){
		cout<<"Has introducido un valor fuera de rango, intentalo de nuevo."<<endl;
		cout<<"Introduce la coordenada inicial del caracter a mover en el eje y(Entre "<<fila<<" y "<<fila+ancho_fila<<"): "<<endl;
		cin>>y;
	}
	pinta_laberinto(columna, fila, ancho_columna, ancho_fila);
}

void punto_de_partida(int x, int y, int color, int columna, int fila, int ancho_columna, int ancho_fila){

	textcolor(color);
	gotoxy(x,y);
	printf("%c", char(219));

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

}

int menu (void){

	int opcion;

	clrscr();
	textcolor(WHITE);
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
