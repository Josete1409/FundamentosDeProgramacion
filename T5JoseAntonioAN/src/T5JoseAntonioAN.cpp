//============================================================================
// Name        : T5JoseAntonioAN.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Implementa tus propias funciones para convertir una letra a mayúsculas o a minúsculas.
//============================================================================

#include <iostream>
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void amayusculas (char letra);
void aminusculas (char letra);

int main() {

	char letra, resp;

	cout<<"Desea ejecutar el programa? S/N: "<<endl;
	cin>>resp;
	resp=toupper(resp);

	while(resp!='N' && resp!='S'){

		cout<<"Has introducido un caracter no valido, intentalo de nuevo."<<endl;
		cout<<"Desea ejecutar el programa? S/N: ";
		cin>>resp;
		resp=toupper(resp);

	}

	while(resp=='S'){


		cout<<"Conversor de caracteres"<<endl;
		cout<<"Introduzca una letra del abecedario (A-Z): "<<endl;
		cin>>letra;

		while((letra<'a' || letra>'z') && (letra<'A' || letra>'Z')){

			cout<<"Caracter no valido, vuelva a intentarlo de nuevo."<<endl;
			cout<<"Introduzca una letra del abecedario (A-Z): "<<endl;
			cin>>letra;

		}
		if(letra>='A' && letra<='Z') {

			aminusculas(letra);

		}else{

			amayusculas(letra);

		}

		cout<<"¿Desea ejecutar el programa? S/N: "<<endl;
		cin>>resp;
		resp=toupper(resp);

	}

	return 0;
}

void aminusculas (char letra){

	//Caracteres ASCII -- Mayusculas (65-90)


	letra= letra+32;	//La diferencia que hay del 65 al 97 es = 32 y como siguen en el mismo orden lo unico que hay que hacer es sumarle esa diferencia
	cout<<"En minuscula es: "<<letra<<endl;

}

void amayusculas (char letra){

	//Caracteres ASCII -- Minusculas (97-122)


	letra= letra-32;
	cout<<"En mayuscula es: "<<letra<<endl;

}
