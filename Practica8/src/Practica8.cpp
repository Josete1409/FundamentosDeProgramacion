//============================================================================
// Name        : Practica8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

#define maxpreg 34
#define numresp 4
#define maxresp numresp*maxpreg
#define maxcad 256

typedef char cadena[maxcad];
typedef struct{
	int num;
	cadena preg;
}pregunta;
typedef pregunta v_preguntas[maxpreg];
typedef struct{
	int num;
	int correcta;//0   falsa 1 verdadera
	cadena resp;
}respuesta;
typedef respuesta v_respuestas[maxresp];

using namespace std;

void leer_preguntas(v_preguntas vp, const cadena p);
void leer_respuestas(v_respuestas vr, const cadena r);
void test(const v_preguntas vp, const v_respuestas vr, int & acertadas, int & contestadas);
void barra_espacio(const cadena c1, cadena c2);

int main(int argc, char * argv[]) {

	if(argc!=3){

		cout<<"Error al pasar los argumentos, debe de ejecutar el "<<endl;
		cout<<"programa con el nombre del fichero de preguntas, un espacio y "<<endl;
		cout<<"el nombre del fichero de respuestas"<<endl;
		cout<<"Ejemplo: "<<endl;
		cout<<"ficheros D:/programasFP/ficheros/preguntas.txt D:/programasFP/ficheros/respuestas.txt"<<endl;

	}else{

		v_preguntas vp;
		v_respuestas vr;
		int acertadas;
		int contestadas;
		char resp;

		leer_preguntas(vp,argv[1]);
		leer_respuestas(vr,argv[2]);

		system("cls");

		cout<<"Simulacion de test de Fundamentos de Programacion"<<endl;
		cout<<"Desea comenzar el test s/n?: ";
		cin>>resp;

		resp = tolower(resp);

		while(resp!='s' && resp!='n'){

			cout<<"error, introduzca s o n:";
			cin>>resp;
			resp = tolower(resp);

		}

		while(resp=='s'){

			cout<<endl;
			test(vp,vr,acertadas,contestadas);

			cout<<"Has acertado "<<acertadas<<" preguntas de "<<contestadas<<" contestadas"<<endl;
			cout<<"Realizar el test de nuevo s/n? ";
			cin>>resp;
			resp = tolower(resp);

			while(resp!='s' && resp!='n'){

				cout<<"error, introduzca s o n:";
				cin>>resp;
				resp = tolower(resp);

			}

		}
	}

	return 0;

}


//modulo que leera el fichero preguntas.txt y lo pasara a un vector
void leer_preguntas(v_preguntas vp, const cadena p){

	ifstream fpreg;
	int aux;

	int i=0;

	//fpreg.open("D:/programasFP/ficheros/preguntas.txt");

	fpreg.open(p);

	if(fpreg.fail()){

		cout<<"Error en apertura de fichero preguntas"<<endl;

	}else{

		fpreg>>aux;
		while(!fpreg.eof()){

			vp[i].num = aux;
			fpreg>>vp[i].preg;
			i++;
			fpreg>>aux;

		}
	}

	fpreg.close();
}


//modulo que leera un fichero de respuestas y lo pasa a un vector
void leer_respuestas(v_respuestas vr,const cadena r){

	ifstream fresp;
	int aux;

	int i=0;

	//fresp.open("D:/programasFP/ficheros/respuestas.txt");
	fresp.open(r);

	if(fresp.fail()){

		cout<<"Error en apertura de fichero respuestas"<<endl;

	}else{

		fresp>>aux;
		while(!fresp.eof()){

			vr[i].num = aux;
			fresp>>vr[i].correcta;
			fresp>>vr[i].resp;
			i++;
			fresp>>aux;

		}
	}

	fresp.close();

}

//modulo que ejecuta el test
//recorrera el vector de preguntas y el vector de respuestas
//devolvera al programa principal el numero de preguntas acertadas y el total de contestadas
void test(const v_preguntas vp, const v_respuestas vr, int & acertadas, int & contestadas){

	int i;
	int j;
	int cont;
	int correcta;
	int respuesta;
	cadena cadaux;

	acertadas =0;
	contestadas =0;
	i=0;

	while(i<maxpreg){

		cout<<vp[i].num<<". ";
		barra_espacio(vp[i].preg,cadaux);
		cout<<cadaux<<endl<<endl;

		cont=1;
		j=0;

		while(cont<=numresp && j<maxresp){

			if(vr[j].num  == vp[i].num){

				cout<<cont<<" ";
				barra_espacio(vr[j].resp,cadaux);
				cout<<cadaux<<endl;

				if(vr[j].correcta==1){

					correcta = cont;

				}

				cont++;

			}

			j++;

		}

		cout<<"Introduzca la respuesta correcta (1..4):";
		cin>>respuesta;

		while(respuesta <=0 || respuesta >4){

			cout<<"Error, introduzca un valor entre 1 y 4:";
			cin>>respuesta;
		}

		contestadas++;

		if(respuesta == correcta){

			cout<<endl<<"Muy Bien, has acertado"<<endl<<endl;
			acertadas++;

		}else{

			cout<<endl<<"Has fallado, la correcta es la "<<correcta<<endl<<endl;

		}

		i++;

	}

}


//modulo que copia una cadena c1 a otra cadena c2
//cambiando el caracter _ por blanco
void barra_espacio(const cadena c1, cadena c2){

	int longitud = strlen(c1);

	c2[0]='\0';

	for(int i=0;i<longitud;i++){

		if(c1[i]=='_'){

			c2[i] = ' ';

		}else{

			c2[i]= c1[i];

		}
	}

	c2[longitud]='\0';
}
