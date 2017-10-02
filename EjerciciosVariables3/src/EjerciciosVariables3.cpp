//============================================================================
// Name        : EjerciciosVariables3.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Calcular el perimetro de un rectangulo.
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	float base, altura;

	printf("Introduce el valor de la base del rectangulo: ");
	cin>>base;

	printf("Introduce la altura del rectangulo: ");
	cin>>altura;

	cout<<"El perimetro del rectangulo con base "<<base<<" y altura "<<altura<<" es de: ";
	printf("%f", (base+altura)*2);

	return 0;
}
