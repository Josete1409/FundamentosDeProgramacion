//============================================================================
// Name        : Practica6.cpp
// Author      : Jose Antonio Alvarez Nieto
// Version     :
// Description : En esta práctica trabajaremos con notas musicales básicas.
//				 1. Implementa un módulo para almacenar dichos tonos en un vector.
//				 2. Implementa un módulo que recorra el vector ascendentemente y reproduzca las notas musicales.
//				 3. Implementa un módulo que recorra el vector descendentemente y reproduzca las notas musicales.
//				 4. Diseña un módulo que toque el cumpleaños feliz.
//============================================================================

#include <iostream>
#include <conio2.h>
#include <conio.h>
#include <windows.h>
#include <fstream.h>

//Constantes
#define max 19
#define max_archivo 100

//Declaracion de variables - vectores
typedef int vector_notas[max];
typedef int vector_archivo[max_archivo];

using namespace std;

int menu (void);
void inicializar_notas(vector_notas notas);
void DoaSi(const vector_notas notas);
void SiaDo(const vector_notas notas);
void cumple_feliz(const vector_notas notas);
void teclado(const vector_notas);

int main() {

	vector_notas notas;
	int opcion;

	opcion=menu();

	while(opcion!=6){

		switch(opcion){

		case 1:
			clrscr();
			cout<<"Has elegido llenar el vector con las notas musicales."<<endl;
			//Inicializamos las notas en cada una de las posiciones del vector
			inicializar_notas(notas);
			break;
		case 2:
			clrscr();
			cout<<"Has elegido escuchar las notas de Do a Si."<<endl;
			//Recorremos el vector de forma ascendente para que suene de Do a Si
			DoaSi(notas);
			break;
		case 3:
			clrscr();
			cout<<"Has elegido escuchar las notas de Si a Do."<<endl;
			//Recorremos el vector de forma descendente para que suene de Si a Do
			SiaDo(notas);
			break;
		case 4:
			clrscr();
			cout<<"Has elegido escuchar canción cumpleaños feliz."<<endl;
			//Leemos de un archivo las notas para que sea la cancion del cumpleaños feliz
			cumple_feliz(notas);
			break;
		case 5:
			clrscr();
			cout<<"Has elegido el teclado libre."<<endl;
			//Cada tecla del 0-7 esta asignada a una nota, por lo que puedes tocar lo que quieras hasta que pulses Esc.
			teclado(notas);
			break;
		default:
			break;
		}

		opcion=menu();
	}
}

int menu (void){

	int opcion;

	clrscr();
	cout<<"1.- Llenar vector con las notas musicales."<<endl;
	cout<<"2.- Escuchar las notas de Do a Si."<<endl;
	cout<<"3.- Escuchar las notas de Si a Do."<<endl;
	cout<<"4.- Escuchar canción cumpleaños feliz."<<endl;
	cout<<"5.- Teclado libre."<<endl;
	cout<<"6.- Fin."<<endl;
	cout<<"Introduce la opcion que desees realizar: ";
	cin>>opcion;

	while(opcion<1 || opcion>6){
		cout<<"Error, vuelva a introducir una opcion valida: ";
		cin>>opcion;
	}

	return opcion;
}


void inicializar_notas(vector_notas notas){

	notas[0]=261; //Do Si-B
	notas[1]=293; //Re
	notas[2]=329; //Mi Fa-B
	notas[3]=349; //Fa Mi#
	notas[4]=392; //Sol
	notas[5]=440; //La
	notas[6]=493; //Si Do-B
	notas[7]=523; //Do'
	notas[8]=587; //Re'
	notas[9]=659; //Mi'
	notas[10]=698; //Fa'
	notas[11]=784; //Sol'
	notas[12]=277; //Re-B Do#
	notas[13]=311; //Mi-B Re#
	notas[14]=370; //Sol-B Fa#
	notas[15]=415; //La-B Sol#
	notas[16]=466; //Si-B La#
	notas[17]=554; //Re'-B
	notas[18]=622; //Mi'-B
	notas[19]=740; //Sol'-B

}

void DoaSi(const vector_notas notas){

	for(int i=0; i<max-12; i++){

		Beep(notas[i],500);
	}
}

void SiaDo(const vector_notas notas){

	for(int i=max-13; i>=0; i--){

		Beep(notas[i],500);
	}
}

void cumple_feliz(const vector_notas notas){

	vector_archivo archivo;
	int nota, i;
	ifstream lectura;

	lectura.open("cumple.txt");

	if(lectura.fail()){

		cout<<"Error en la apertura del fichero"<<endl;

	}else{

		lectura>>nota;
		i=0;
		Beep(notas[nota],500);
		while(!lectura.eof()){

			archivo[i]=nota;
			lectura>>nota;
			i++;
			Beep(notas[nota],500);
		}
	}

	lectura.close();

}

void teclado(const vector_notas notas){

	int tecla;
	bool fin=false;

	cout<<"Do:0 - Re:1 - Mi:2 - Fa:3 - Sol:4 - La:5 - Si:6 - Do':7"<<endl;
	cout<<"Pulsa Esc para finalizar el teclado."<<endl;

	while(!fin){
		if(kbhit()){
			tecla = getch();
			if(tecla == 48){
				Beep(notas[0],500); //Do
			}
			if(tecla == 49){
				Beep(notas[1],500); //Re
			}
			if(tecla == 50){
				Beep(notas[2],500); //Mi
			}
			if(tecla == 51){
				Beep(notas[3],500); //Fa
			}
			if(tecla == 52){
				Beep(notas[4],500); //Sol
			}
			if(tecla == 53){
				Beep(notas[5],500); //La
			}
			if(tecla == 54){
				Beep(notas[6],500); //Si
			}
			if(tecla == 55){
				Beep(notas[7],500); //Do'
			}


			if(tecla == 27) fin=true; //TECLA ESC

		}

	}
}
