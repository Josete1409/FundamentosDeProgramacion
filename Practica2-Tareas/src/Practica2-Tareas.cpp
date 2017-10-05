//============================================================================
// Name        : Practica2-Tareas.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
//Description : Practica en la que probaremos los colores, el posicionamiento
//              del cursor en la pantalla y visualización de caracteres
//              La pantalla tiene 25 filas por 80 columnas.
// Tarea 1: Cambia colores y posicion del cursor y comprueba su funcionamiento.
//          Comprueba como funciona el calculo de numeros aleatorios.
//          Una vez que lo tengas dominado, coloca un caracter en cada
//          esquina de la pantalla y uno central con un color
//          calculado aleatoriamente, cada vez que se ejecute el programa el color cambiará.
// Tarea 2: Simula un caracter rojo moviendose 5 posiciones en horizontal
// Tarea 3: Simula un caracter rojo moviendose 5 posiciones en vertica
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio2.h>

using namespace std;

#define maxfil 25
#define maxcol 80
#define maxcolor 16

int main() {

	srand(time(NULL));

	char resp;
	int fila,columna;
	int color;

	clrscr();

	cout<<"Desea ejecutar el programa s/n:";
	cin>>resp;

	color = rand()%maxcolor;
	textcolor(color);

	fila=rand()%maxfil;

	columna=rand()%maxcol;

	if(resp=='s' || resp=='S'){

		clrscr();

		gotoxy(1,1);                      //Tarea 1
		printf("%c", char(219));
		gotoxy(79,1);
		printf("%c", char(219));
		gotoxy(40,12);
		printf("%c", char(219));
		gotoxy(1,24);
		printf("%c", char(219));
		gotoxy(79,24);
		printf("%c", char(219));
		Beep(1000,200);

		Sleep(2000);

		clrscr();

		gotoxy(1,1);                        //Tarea 2
		textcolor(RED);
		printf("%c", char(219));
		Beep(1000,200);
		Sleep(1000);

		gotoxy(1,1);
		textcolor(BLACK);
		printf("%c", char(219));
		gotoxy(1,2);
		textcolor(RED);
		printf("%c", char(219));
		Beep(1000,200);
		Sleep(1000);

		gotoxy(1,2);
		textcolor(BLACK);
		printf("%c", char(219));
		gotoxy(1,3);
		textcolor(RED);
		printf("%c", char(219));
		Beep(1000,200);
		Sleep(1000);

		gotoxy(1,3);
		textcolor(BLACK);
		printf("%c", char(219));
		gotoxy(1,4);
		textcolor(RED);
		printf("%c", char(219));
		Beep(1000,200);
		Sleep(1000);

		gotoxy(1,4);
		textcolor(BLACK);
		printf("%c", char(219));
		gotoxy(1,5);
		textcolor(RED);
		printf("%c", char(219));
		Beep(1000,200);
		Sleep(1000);

		gotoxy(1,5);                    //Tarea 3
		textcolor(BLACK);
		printf("%c", char(219));
		gotoxy(2,5);
		textcolor(RED);
		printf("%c", char(219));
		Beep(1000,200);
		Sleep(1000);

		gotoxy(2,5);
		textcolor(BLACK);
		printf("%c", char(219));
		gotoxy(3,5);
		textcolor(RED);
		printf("%c", char(219));
		Beep(1000,200);
		Sleep(1000);

		gotoxy(3,5);
		textcolor(BLACK);
		printf("%c", char(219));
		gotoxy(4,5);
		textcolor(RED);
		printf("%c", char(219));
		Beep(1000,200);
		Sleep(1000);

		gotoxy(4,5);
		textcolor(BLACK);
		printf("%c", char(219));
		gotoxy(5,5);
		textcolor(RED);
		printf("%c", char(219));
		Beep(1000,200);
		Sleep(1000);

	} else {

		textcolor(WHITE);
		printf("Ha decidido no ejecutar el programa.");

	}

	textcolor(WHITE);

	Sleep(1000);

	return 0;
}
