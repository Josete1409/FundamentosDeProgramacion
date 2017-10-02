//============================================================================
// Name        : Ejercicio4.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : Ejercicio 4
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	float total_compra, descuento, total_pagar;

	printf("Introduce el valor total de la compra: \n");
	cin>>total_compra;

	descuento = total_compra*0.15;
	total_pagar = total_compra-descuento;

	printf("El total de la compra con el 15 por ciento de descuento sería: ");
	printf("%f", total_pagar);

	return 0;
}
