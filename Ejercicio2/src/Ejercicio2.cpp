//============================================================================
// Name        : Ejercicio2.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Ejercicios de FP
//============================================================================

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {

	float capital;

	printf("Intruduce el capital que deseas invertir: ");
	cin>>capital;

	printf("Las ganancias obtenidas serían: ");
	printf("%f", capital*0.2);

	return 0;
}
