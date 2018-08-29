//declaraciones
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void loop(void);
int evaluate(char[100][10], int, int);
int request(void);
void generate(char[100][10], int);
void print(char mat [100][10],int, int);
void miscellaneous(void);


//funcion main
int main(void) {

  char matriz[100][10];
  int cant ,fila ,columna ,maxfil ,maxcol, density;

  //preguntar por fila
  do {  //mientras haya un error, seguir preguntando
    printf("\n------------------------------------------\n");
    printf("Ingrese cantidad de filas (entre 1 y 100).\n");
    printf("------------------------------------------\n");
    maxfil=request();
    if (maxfil>=100)
      printf("La cantidad de filas debe ser menor a 100.\n");
  } while ((maxfil==0)||(maxfil>100));

  //preguntar por columna
  do {  //mientras haya un error, seguir preguntando
    printf("\n--------------------------------------------\n");
    printf("Ingrese cantidad de columnas (entre 1 y 10).\n");
    printf("--------------------------------------------\n");
    maxcol=request();;
    if (maxcol>10)
      printf("La cantidad de columna debe ser menor o igual a 10.\n");
  } while ((maxcol==0)||(maxcol>10));

  do {  //mientras haya un error, seguir preguntando
    printf("\n---------------------------------------------\n");
    printf("Ingrese densidad de particulas (entre 1 y 5).\n");
    printf("---------------------------------------------\n");
    density=request();
    if (density>5)
      printf("La densidad debe ser menor o igual a 5.\n");
  } while ((density==0)||(density>5));

  //generamos matriz random
  density= 6 - density; //la densidad es inversa a la probabilidad
  generate(matriz, density);

  //miscellaneous
  miscellaneous();

  //imprimimos la matriz
  printf("\n");
  print(matriz,maxfil,maxcol);

  //el crash seguramente es por esta parte, faltaria la funcion de fran y esta terminado
  while (1)
  {
    fila=1, columna=1;
    cant=evaluate(matriz, fila, columna);
    printf("%d\n",cant);
    break;
  }

  printf("not crashed\n");
  return 0;
}

//funcion loop
void loop(void) {



}

//funcion evalua la cantidad de celulas vivas al rededor de la celda ij
int evaluate (char matrx[100][10], int i, int j) {

  int n, h ,total=0; //n y h son contadores, total es el numero total

  for (n=-1;n<=1;n++) { //evaluamos las posiciones de las filas anterior, misma y sig
    for (h=-1;h<=1;h++) { //evaluamos las posiciones de las columnas anterior, misma y sig
      if (matrx[i+n][j+h]=='X')
        total++;  //sumamos uno al total
    }
  }

  total=total-1;  //corregimos el total porque se conto la posicion ij en si misma
  return total;
}

//pide la fila
int request (void) {
  int ch ,cant=0, mistake=0;
  while ( (ch = getchar()) != '\n') {

    if ( ((ch - '0')>9) || ((ch - '0')<0) ) { //si el caracter no es un numero esta mal
      mistake=1;  //flag error
    }
    else
      cant = cant*10 + (ch - '0');

  }

  if ( (cant==0)&&(mistake==0) ) //ninguna de las cantidades pedidas puede ser 0
    printf("No puede ser cero.\n");

  if (mistake==1) {
    printf("----------Input Error----------\n");
    return 0; //si hubo error devolvemos un 0 como flag
  }
  else {
    return cant; //sino devolvemos el valor
  }
}

//funcion que genera una matriz random
void generate (char matrx[100][10], int j) {

  int i, h, random;
  srand(time(NULL));  //seteo una semilla para que la generacion sea completamente random

  for (i=0;i<100;i++) {
    for (h=0;h<100;h++) {
      random = 1 + (rand()%j);  //la probabilidad de generar unos aumenta con la densidad elegida
      if (random == 1)  //si se genera un uno, hay una celula viva
        matrx[i][h]='X';
      else
        matrx[i][h]=' ';
    }
  }

}

//esta funcion imprime en pantalla la martiz.
void print (char mat [100][10],int i,int j) {
	int contcol;
	int contfil=0;

	while(contfil<i)
	//Imprime las filas de la matriz hasta llegar a la ultima.==
	{
		printf("|");
		for(contcol=0;contcol<j;++contcol)
		//Imprime todos los caracteres de la misma fila hasta llegar al ultimo.
		{
			printf("%c|",mat[contfil][contcol]);
		}
		++contfil;
		printf("\n");
	}
}

//doesnt really do anything
void miscellaneous (void){

  sleep(1);
  printf("\nWaking the Dwarfs...\n");
  sleep(1);
  printf("Generating Matrix...\n");
  sleep(1);
  printf("Building Matrix with characters...\n");
  sleep(1);

}
