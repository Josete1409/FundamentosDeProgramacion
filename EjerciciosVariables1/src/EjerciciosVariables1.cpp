//============================================================================
// Name        : EjerciciosVariables1.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Longitud de una circunferencia de radio n
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const float pi=3.14; //Declaramos la variable constante.

int main(void) {

	float radio;

	printf("Introduzca el radio de la circunferencia: ");
	cin>>radio;

	printf("La longitud de la circunferencia es: ");
	printf("%f", 2*pi*radio );

	return 0;
}
