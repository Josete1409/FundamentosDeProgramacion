//============================================================================
// Name        : Practica7-PruebaMatrices.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Comprobar el funcionamiento de las matrices, registros y el paso por parámetros.
//============================================================================

#include <iostream>
#include <windows.h>

//Constantes
#define fila 3
#define columna 2

//Declaracion de Matrices y Registros
typedef struct{
	char dato;
	bool visible;
}registro;

typedef registro matriz_registros[fila][columna];

using namespace std;

void inicializar_matriz(matriz_registros matriz);
void mostrar_matriz(const matriz_registros matriz);
bool buscar_matriz(const matriz_registros matriz, char caracter_buscar, int & f_encontrado, int & c_encontrado);

int main() {

	matriz_registros matriz;
	char caracter_buscar;
	bool encontrado;
	int f_encontrado, c_encontrado;

	inicializar_matriz(matriz);
	mostrar_matriz(matriz);

	cout<<"Buscamos si existe en la matriz un detarminado caracter"<<endl;
	cout<<"Introduza caracter: "<<endl;
	cin>>caracter_buscar;

	encontrado=buscar_matriz(matriz, caracter_buscar, f_encontrado, c_encontrado);

	if(encontrado){

		cout<<"El caracter "<<caracter_buscar<<" existe en la fila "<<f_encontrado<<" y columna "<<c_encontrado<<endl;

	}else{

		cout<<"El caracter "<<caracter_buscar<<" no existe"<<endl;

	}

	Sleep(5000);

	return 0;

}

void inicializar_matriz(matriz_registros matriz){

	cout<<"Introduce informacion en la matriz por filas"<<endl;
	for(int i=0; i<fila; i++){

		for(int j=0; j<columna; j++){

			cout<<"Introduzca caracter en la fila "<<i<<" columna "<<j<<":"<<endl;
			cin>>matriz[i][j].dato;
			//Todos los datos seran visibles
			matriz[i][j].visible = true;

		}
	}

}

void mostrar_matriz(const matriz_registros matriz){

	cout<<"Motrar la informacion de la matriz"<<endl;
	for(int i=0; i<fila; i++){

		for(int j=0; j<columna; j++){

			if(matriz[i][j].visible == true){
				cout<<"Caracter en la fila "<<i<<" columna "<<j<<":"<<matriz[i][j].dato<<endl;
			}

		}
	}

	cout<<"Solo mostramos la informacion de la matriz"<<endl;
	for(int i=0; i<fila; i++){

		for(int j=0; j<columna; j++){

			if(matriz[i][j].visible == true){
				cout<<matriz[i][j].dato<<" "<<endl;
			}else{
				cout<<" ";
			}

		}
		cout<<endl;
	}

}

bool buscar_matriz(const matriz_registros matriz, char caracter_buscar, int & f_encontrado, int & c_encontrado){

	bool encontrado;
	int f, c;

	encontrado = false;
	f = 0;
	f_encontrado = -1;
	c_encontrado = -1;


	while(f<fila && !encontrado){

		c=0;
		while(c<columna && !encontrado){

			if(matriz[f][c].dato == caracter_buscar){

				encontrado = true;
				f_encontrado = f;
				c_encontrado = c;

			}else{

				c++;

			}

		}
		f++;
	}

	return encontrado;
}
