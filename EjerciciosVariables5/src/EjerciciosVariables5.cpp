//============================================================================
// Name        : EjerciciosVariables5.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Calcular la suma de los n primeros numeros pares.
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int numeros;

	printf("Introduce hasta que número quieres que se realice la suma de los pares: ");
	cin>>numeros;

	cout<<"La suma de los "<<numeros<<" primeros números pares es de: "<<(numeros*numeros)+numeros;

	return 0;
}
