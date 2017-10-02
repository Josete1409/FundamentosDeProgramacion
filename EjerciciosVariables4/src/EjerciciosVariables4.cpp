//============================================================================
// Name        : EjerciciosVariables4.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Calcular los partidos en la primera vuelta dependiendo del nº de equipos.
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int equipos;

	printf("Introduce el número de equipos participantes en el torneo: ");
	cin>>equipos;

	cout<<"El número de partidos que habrá la primera vuelta del campeonato sera de: "<<equipos/2;

	return 0;
}
