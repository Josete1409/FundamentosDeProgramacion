//============================================================================
// Name        : Practica7.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Creación de nuestra propia libreria, y paso por parametros al main
//============================================================================

#include <iostream>
#include <windows.h>
#include <conio2.h>
#include "milibreria.h"

using namespace std;

int main(int arg, char * argv[]) {

	//Variables
	int f_encontrado, c_encontrado, f1, f2, c1, c2;
	bool encontrado;
	char caracter_buscar;
	matriz_registros matriz;

	f1=atoi(argv[1]);
	c1=atoi(argv[2]);
	f2=atoi(argv[3]);
	c2=atoi(argv[4]);

	clrscr();

	if(arg!=5){

		cout<<"Ha olvidado pasar algun parametro"<<endl;

	}else{

		//usamos los argumentos del main

		cout<<"Posiciones no visibles f1:"<<f1<<" c1:"<<c1<<  " f2:"<<f2<<" c2:"   <<c2<<endl;
		inicializar_matriz(matriz,f1,c1,f2,c2);
		matriz[f1][c1].visible=false;
		matriz[f2][c2].visible=false;

		mostrar_matriz(matriz);

		cout<<"Buscamos si existe en la matriz un determinado caracter"<<endl;
		cout<<"Introduzca caracter:";
		cin>>caracter_buscar;

		buscar_matriz(matriz, caracter_buscar, f_encontrado, c_encontrado, encontrado);

		if(encontrado==true){

			cout<<"el caracter "<<caracter_buscar<<" existe en la fila "<<f_encontrado<<" y columna "<<c_encontrado<<endl;

		}else{

			cout<<"el caracter "<<caracter_buscar<<" no existe."<<endl;

		}

	}

	return 0;
}
