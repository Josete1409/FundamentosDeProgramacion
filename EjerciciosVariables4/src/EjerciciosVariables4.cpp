//============================================================================
// Name        : EjerciciosVariables4.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Calcular los partidos en la primera vuelta dependiendo del n� de equipos.
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int equipos;

	printf("Introduce el n�mero de equipos participantes en el torneo: ");
	cin>>equipos;

	cout<<"El n�mero de partidos que habr� la primera vuelta del campeonato sera de: "<<equipos/2;

	return 0;
}
