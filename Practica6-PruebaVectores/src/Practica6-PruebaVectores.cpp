//============================================================================
// Name        : Practica6.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Funcionamiento de vectores
//============================================================================

#include <iostream>
#include <conio.h>
#include <conio2.h>
#include <windows.h>

//Constantes

#define max 10

//Declaracion de variables - vectores

typedef int vector_enteros[max];

using namespace std;

void inicializar_vector(vector_enteros v);
void mostrar_vector(const vector_enteros v);
bool buscar_vector(const vector_enteros v, int valor);

int main() {

	clrscr();

	//Variables
	vector_enteros v;
	int valor;
	bool encontrado;

	cout<<"Visualizamos la direccion del vector."<<endl;

	inicializar_vector(v);
	mostrar_vector(v);

	cout<<"Introduzca valor buscado:";
	cin>>valor;
	encontrado=buscar_vector(v, valor);

	if(encontrado==true){
	//if(buscar_vector(v, valor)==true){

		cout<<"El valor "<<valor<<" existe en el vector"<<endl;
	}else{

		cout<<"El valor "<<valor<<" NO existe en el vector"<<endl;
	}

	return 0;
}

void inicializar_vector(vector_enteros v){

	cout<<"Introducimos los elementos del vector."<<endl;

	//Introducimos los elementos del vector
	for(int i=0; i<max; i++){

		cout<<"Introduzca elemento: "<<endl;
		cin>>v[i];
	}
}

void mostrar_vector(const vector_enteros v){

	//Visualizamos los elementos del vector
	for(int i=0; i<max; i++){

		cout<<"Elemnto "<<i+1<<": "<<v[i]<<endl;
	}
}

bool buscar_vector(const vector_enteros v, int valor){

	int x;
	bool encontrado;

	x=0;
	encontrado = false;

	while (x<max && !encontrado){
		if(v[x]== valor){

			encontrado = true;
		}else{

			x++;
		}
	}

	return encontrado;
}
