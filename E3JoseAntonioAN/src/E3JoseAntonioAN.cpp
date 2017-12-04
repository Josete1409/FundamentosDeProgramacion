//============================================================================
// Name        : E3JoseAntonioAN.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <conio2.h>
#include <conio.h>

//Costantes
#define fila 12
#define columna 10

//Tipos de datos
typedef char m_sopa[fila][columna];
typedef char cadena1[9];
typedef char cadena2[9];

using namespace std;

void inicializa_matriz(m_sopa matriz);
void mostrar_matriz (const m_sopa matriz);
int fila_letra(const m_sopa matriz, char caracter_buscar);
void coloca_palabras(m_sopa matriz, cadena1 c1, cadena2 c2);

int main(int arg, char * argv[]) {

	//Variables
	char caracter_buscar, resp;
	int f_encontrado;
	m_sopa matriz;

	srand(time(NULL));

	if(arg!=3){

		cout<<"Ha olvidado pasar algun parametro"<<endl;

	}else{

		cout<<"Tercera entrega de fundamentos de programacion."<<endl;
		cout<<"Jose Antonio Alvarez Nieto"<<endl;
		cout<<"Desea ejecutar la Sopa de Letras? S/N: "<<endl;
		cin>>resp;
		resp=toupper(resp);

		while(resp!='N' && resp!='S'){

			cout<<"Has introducido un caracter no valido, intentalo de nuevo."<<endl;
			cout<<"Desea ejecutar la Sopa de Letras? S/N: ";
			cin>>resp;
			resp=toupper(resp);

		}

		while(resp=='S'){

			clrscr();

			inicializa_matriz(matriz);
			coloca_palabras(matriz, argv[1], argv[2]);
			mostrar_matriz(matriz);

			cout<<"Introduzca la letra a buscar: "<<endl;
			cin>>caracter_buscar;

			f_encontrado=fila_letra(matriz, caracter_buscar);

			if(f_encontrado==-1){

				cout<<"La letra "<<caracter_buscar<<" no se encuentra en la sopa de letras."<<endl;

			}else{

				cout<<"La primera fila en la que aparece la letra "<<caracter_buscar<<" es la fila "<<f_encontrado<<endl;

			}

			cout<<"¿Desea ejecutar la Sopa de Letras? S/N: "<<endl;
			cin>>resp;
			resp=toupper(resp);

			while(resp!='N' && resp!='S'){

				cout<<"Has introducido un caracter no valido, intentalo de nuevo."<<endl;
				cout<<"Desea ejecutar la Sopa de Letras? S/N: ";
				cin>>resp;
				resp=toupper(resp);
			}

		}
	}
	return 0;
}


void inicializa_matriz(m_sopa matriz){

	char letras;

	for(int i=0; i<fila; i++){

		for(int j=0; j<columna; j++){

			letras=rand()%(122-97+1)+97;
			matriz[i][j]=letras;
		}
	}
}

void mostrar_matriz (const m_sopa matriz){

	for(int i=0; i<fila; i++){

		for(int j=0; j<columna; j++){

			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}

}

int fila_letra(const m_sopa matriz, char caracter_buscar){

	int f, c;

	int f_encontrado = -1;
	f = 0;

	while(f<fila && f_encontrado==-1){

		c=0;
		while(c<columna && f_encontrado==-1){

			if(matriz[f][c] == caracter_buscar){

				f_encontrado = f;

			}else{

				c++;

			}

		}
		f++;
	}

	return f_encontrado;

}

void coloca_palabras(m_sopa matriz, cadena1 c1, cadena2 c2){

	int long1, long2, f, c;

	long1 = strlen(c1);
	long2 = strlen(c2);

	f=rand()%11;
	c=rand()%9;

	if(long1<=9 && long2<=9){

		for(int i=0; i<long1; i++){

			matriz[f][c]=c1[i];
			c++;

		}

		for(int j=0; j<long2; j++){

			matriz[f][c]=c2[j];
			f++;

		}
	}


}
