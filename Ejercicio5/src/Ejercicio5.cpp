//============================================================================
// Name        : Ejercicio5.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Ejercicio 5 de FP
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int ah, am, ta;
	float ph, pm;

	printf("Introduce el número de alumnos hombres: \n");
	cin>>ah;

	printf("Introduce el número de alumnos mujeres: \n");
	cin>>am;

	ta = ah+am;
	ph = (ah*100)/ta;
	pm = (am*100)/ta;

	printf("El porcentaje de alumnos hombres es de: \n");
	printf("%f", ph);
	printf("\nEl porcentaje de alumnos mujeres es de: \n");
	printf("%f", pm);

	return 0;
}
