//============================================================================
// Name        : Ejercicio6.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Ejercicio 6 de FP
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int a_nacimiento, a_actual, edad;

	printf("Introduce el a�o de nacimiento: ");
	cin>>a_nacimiento;

	printf("Introduce el a�o actual: ");
	cin>>a_actual;

	edad = a_actual-a_nacimiento;

	printf("La edad que tendr�a ser�a: \n");
	printf("%i", edad);


	return 0;
}
