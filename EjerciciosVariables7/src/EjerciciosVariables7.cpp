//============================================================================
// Name        : EjerciciosVariables7.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Calcular la media de los n primeros numeros positivos
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int numero, suma;
	float media;

	printf("Introduce el n�mero de valores que desea sumar para hacer su media: ");
	cin>>numero;

	suma=numero*(numero+1);
	media=numero/2;

	cout<<"La media aritm�tica de la suma de los "<<numero<<" primeros n�meros pares es de: "<<suma/media;

	return 0;
}
