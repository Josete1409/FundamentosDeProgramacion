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

	printf("Introduce el año de nacimiento: ");
	cin>>a_nacimiento;

	printf("Introduce el año actual: ");
	cin>>a_actual;

	edad = a_actual-a_nacimiento;

	printf("La edad que tendría sería: \n");
	printf("%i", edad);


	return 0;
}
