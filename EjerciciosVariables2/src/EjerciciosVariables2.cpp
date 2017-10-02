//============================================================================
// Name        : EjerciciosVariables2.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Convertidor de millas a kilometros
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int milla_km = 1609;

int main() {

	float millas;

	printf("Introduce las millas para convertirlas en kilometros: ");
	cin>>millas;

	printf("%f", millas*milla_km);

	return 0;
}
