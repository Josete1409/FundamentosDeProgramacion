//============================================================================
// Name        : Practica2-Tarea2.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
//Description : Practica en la que probaremos los colores, el posicionamiento
//              del cursor en la pantalla y visualización de caracteres
//              La pantalla tiene 25 filas por 80 columnas.
// Tarea 2: Simula un caracter rojo moviendose 5 posiciones en horizontal
// ============================================================================

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

	cout<<"Desea ejecutar el programa s/n:";
	cin>>resp;

	clrscr();

	//color = rand()%maxcolor;
	//textcolor(color);

	//fila=rand()%maxfil;

	//columna=rand()%maxcol;

	gotoxy(1,1);
	textcolor(RED);
	printf("%c", char(219));
	Sleep(1000);

	gotoxy(1,2);
	printf("%c", char(219));
	gotoxy(1,3);
	printf("%c", char(219));
	gotoxy(1,4);
	printf("%c", char(219));
	gotoxy(1,5);
	printf("%c", char(219));

	Beep(1000,200);

	Sleep(1000);

	textcolor(WHITE);

	return 0;
}
