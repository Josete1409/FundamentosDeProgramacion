//============================================================================
// Name        : E2JoseAntonioAN.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <conio.h>
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

bool comprobar(char respComprobar);
void mensaje(bool comprobarResp);
void verificar(char & resp1, char & resp2);
void recuento(char resp1, char resp2, int cont1_resp1, int cont2_resp1, int cont3_resp1, int cont1_resp2, int cont2_resp2, int cont3_resp2);

int main() {

	char resp, resp1, resp2;
	int cont1_resp1, cont2_resp1, cont3_resp1, cont1_resp2, cont2_resp2, cont3_resp2;

	cont1_resp1=0;
	cont2_resp1=0;
	cont3_resp1=0;
	cont1_resp2=0;
	cont2_resp2=0;
	cont3_resp2=0;

	cout<<"Segunda entrega de fundamentos de programacion."<<endl;
	cout<<"Jose Antonio Alvarez Nieto"<<endl;
	cout<<"Desea ejecutar el programa? S/N: "<<endl;
	cin>>resp;
	resp=toupper(resp);

	while(resp!='N' && resp!='S'){

		cout<<"Has introducido un caracter no valido, intentalo de nuevo."<<endl;
		cout<<"Desea ejecutar el programa? S/N: ";
		cin>>resp;
		resp=toupper(resp);

	}

	while(resp=='S'){

		cout<<"¿Cree que Puigdemont debe entrar en la cárcel? S/N/P. (S: Si N: No P:No responde)"<<endl;
		cin>>resp1;
		resp1=toupper(resp1);
		comprobar(resp1);
		mensaje(comprobar(resp1));

		cout<<"¿Cree que Puigdemont volverá a España antes de las elecciones? S/N/P. (S: Si N: No P:No responde)"<<endl;
		cin>>resp2;
		resp2=toupper(resp2);
		comprobar(resp2);
		mensaje(comprobar(resp2));

		verificar(resp1, resp2);

		if(resp1=='S'){
			cont1_resp1++;

		}else{
			cont2_resp1++;
			cont3_resp1++;

		}

		if(resp2=='S'){
			cont1_resp2++;

		}else{
			cont2_resp2++;
			cont3_resp2++;

		}

		cout<<"¿Desea ejecutar el programa? S/N: "<<endl;
		cin>>resp;
		resp=toupper(resp);
	}

	cout<<"Cerramos las encuentas con el siguiente resultado:"<<endl;
	recuento(resp1, resp2, cont1_resp1, cont2_resp1, cont3_resp1, cont1_resp2, cont2_resp2, cont3_resp2);

	Sleep(10000);

	return 0;
}

bool comprobar(char respComprobar){

	bool comprobarResp;

	comprobarResp = false;

	if(respComprobar == 'S' || respComprobar =='N' || respComprobar == 'P'){

		comprobarResp = true;

	}

	return comprobarResp;
}

void mensaje(bool comprobarResp){

	if(comprobarResp == true){

		cout<<"Su respuesta es válida entrará en el cómputo de votos"<<endl;

	}else{

		cout<<"Su respuesta NO es válida"<<endl;
	}

}

void verificar(char & resp1, char & resp2){

	while(resp1 != 'S' && resp1 != 'N' && resp1 != 'P'){

		cout<<"Vuelva a responder a la pregunta 1: ¿Cree que Puigdemont debe entrar en la cárcel? S/N/P. (S: Si N: No P:No responde)"<<endl;
		cin>>resp1;
		resp1=toupper(resp1);
	}

	while(resp2 != 'S' && resp2 != 'N' && resp2 != 'P'){

		cout<<"Vuelva a responder a la pregunta 2: ¿Cree que Puigdemont volverá a España antes de las elecciones? S/N/P. (S: Si N: No P:No responde)"<<endl;
		cin>>resp2;
		resp2=toupper(resp2);
	}

}

void recuento(char resp1, char resp2, int cont1_resp1, int cont2_resp1, int cont3_resp1, int cont1_resp2, int cont2_resp2, int cont3_resp2){

	/*cout<<cont1_resp1<<endl;
	cout<<cont2_resp1<<endl;
	cout<<cont3_resp1<<endl;
	cout<<cont1_resp2<<endl;
	cout<<cont2_resp2<<endl;
	cout<<cont3_resp2<<endl;*/

	if(cont1_resp1>cont2_resp1+cont3_resp1){
		cout<<"Puigdemont debe ir a la cárcel"<<endl;

	}else{
		if(cont1_resp1==cont2_resp1+cont3_resp1){
			cout<<"No saben que es lo que quieren"<<endl;
		}
		cout<<"Puigdemont NO debe ir a la cárcel"<<endl;
	}

	if(cont1_resp2>cont2_resp2+cont3_resp2){
		cout<<"Puigdemont debe volver a España"<<endl;

	}else{
		if(cont1_resp2==cont2_resp2+cont3_resp2){
			cout<<"No saben que es lo que quieren"<<endl;
		}
		cout<<"Puigdemont se quedara en Bruselas"<<endl;
	}

}
