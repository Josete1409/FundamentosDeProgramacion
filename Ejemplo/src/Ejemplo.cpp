//============================================================================
// Name        : Ejemplo.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Copyright   : Your copyright notice
// Description : Ejemplo 2
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

using namespace std;

int main(void) {
	int radio;
	float perimetro;

	cout<< "Introduzca el radio de una circunferencia: " ;
	//scanf("%i", &radio);
	// endf --> Salto de línea -- <<radio<<endf
	cin>>radio;
	perimetro = 2*PI*radio;
	cout<<"El perimetro es: "<<perimetro;
	//system("PAUSE");

	return 0;
}
