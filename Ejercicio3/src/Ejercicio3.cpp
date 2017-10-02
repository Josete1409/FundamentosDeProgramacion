//============================================================================
// Name        : Ejercicio3.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Ejercicio 3 de FP
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	float sueldo_b, v1, v2, v3;
	sueldo_b = 850;

	printf("Introduce el valor de sus ventas: ");
	cin>>v1;
	cin>>v2;
	cin>>v3;

	printf("El valor que recibirá en comisiones por sus ventas será: ");
	printf("%f\n", (v1+v2+v3)*0.10);

	printf("El total de su sueldo con respecto a las comisiones y el sueldo base sera: ");
	printf("%f", sueldo_b+((v1+v2+v3)*0.10));

	return 0;
}
