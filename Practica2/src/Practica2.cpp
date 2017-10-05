//============================================================================
// Name        : Practica2.cpp
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
// ============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio2.h>

using namespace std;

//¿que hacen las 3 lineas siguientes? --> Define tres variables constantes, sin reservar espacio en memoria.
#define maxfil 25
#define maxcol 80
#define maxcolor 16

int main() {

	//¿que signfica esta sentencia? --> Inicializa la semilla para que cada vez que ejecutemos el programa
	// cambie su valor.
	srand(time(NULL));

	//¿De que tipo son las variables y porque se han puesto esos tipos? ¿Es correcto?
	// --> Tipo Caracter(Solo 1) y tipo entero. Es correcto pero la variable color tambien se podria poner
	// 	   junto a las variables fila y columna.
	char resp;
	int fila,columna;
	int color;

	cout<<"Desea ejecutar el programa s/n:";
	cin>>resp;

	//¿que signfica esta sentencia? --> Limpiar la pantalla
	clrscr();

	//¿Cual sera el valor de la variable color? --> Un numero aleatorio de 0 a 15.
	// En la libreria conio los numeros del 0 al 15 estan definidos como unos determinados colores.
	color = rand()%maxcolor;
	textcolor(color);

	//¿Cual sera el valor de la variable fila, es correcto? --> Un número aleatorio entre 0 y 24.
	fila=rand()%maxfil;

	//¿Cual sera el valor de la variable columna, es correcto? --> Un número aleatorio entre 0 y 15
	columna=rand()%maxcol;

	//¿que signfica esta sentencia? --> Posiciona el cursor en la fila y columna que haya en las variables columna y fila.
	gotoxy(columna,fila);

	//¿que signfica esta sentencia? --> Imprime por pantalla una variable tipo char.
	printf("%c", char(219));

	//¿que signfica esta sentencia? --> Realiza es un sonido.
	Beep(1000,200);

	//¿que signfica esta sentencia? --> Para la ejecucion del programa el tiempo que le establezcamos dentro del parentesis.
	Sleep(1000);

	textcolor(WHITE);//restauramos el color del texto a blanco

	return 0;
}
