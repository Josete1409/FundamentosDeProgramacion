//============================================================================
// Name        : Ejercicio1.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Ejercicios de FP
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void) {

	float asis_part, practicas, tra_grupo, examen;

	printf("Introduzca las notas de asistencia y participacion: ");
	cin>>asis_part;

	printf("Introduzca las notas de practicas: ");
	cin>>practicas;

	printf("Introduzca las notas de trabajo de grupo: ");
	cin>>tra_grupo;

	printf("Introduzca la nota del examen: ");
	cin>>examen;

	printf("La nota final del alumno seria: ");
	printf("%f", (asis_part*0.2)+(practicas*0.25)+(tra_grupo*0.15)+(examen*0.4));

	return 0;
}
