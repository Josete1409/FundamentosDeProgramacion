/*
 * milibreria.h
 *
 *  Created on: 27 de nov. de 2017
 *      Author: joset
 */

#ifndef MILIBRERIA_H_
#define MILIBRERIA_H_


//Librerias
#include <iostream>

using namespace std;

//Constantes
#define fila 3
#define columna 2


//Tipos de Datos
typedef struct{
	char dato;
	bool visible;
}registro;
typedef registro matriz_registros[fila][columna];


//Cabeceras de módulos
void inicializar_matriz(matriz_registros matriz, int f1, int c1, int f2, int c2);
void mostrar_matriz(const matriz_registros matriz);
bool buscar_matriz(const matriz_registros matriz, char caracter_buscar, int & f_encontrado, int & c_encontrado, bool & encontrado);


//Implementación de módulos
void inicializar_matriz(matriz_registros matriz, int f1, int f2, int c1, int c2){

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
				cout<<"Caracter en la fila "<<i<<" columna "<<j<<": "<<matriz[i][j].dato<<endl;
			}

		}
	}

	cout<<"Solo mostramos la informacion de la matriz"<<endl;
	for(int i=0; i<fila; i++){

		for(int j=0; j<columna; j++){

			if(matriz[i][j].visible == true){
				cout<<matriz[i][j].dato<<" ";
			}else{
				cout<<" ";
			}

		}
		cout<<endl;
	}

}

bool buscar_matriz(const matriz_registros matriz, char caracter_buscar, int & f_encontrado, int & c_encontrado, bool & encontrado){

	int f, c;

	f_encontrado = -1;
	c_encontrado = -1;
	encontrado = false;
	f = 0;

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


#endif /* MILIBRERIA_H_ */
