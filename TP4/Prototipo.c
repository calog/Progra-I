//declaraciones
#include <stdio.h>
#include <stdlib.h>

void loop(void);
int evaluate(char[100][10], int, int);
int request(void);
void generate(char[100][10]);

//funcion main
int main(void) {

  char matriz[100][10]={{ }};
  int cant ,fila ,columna ,maxfil ,maxcol;

  //preguntar por fila
  do {  //mientras haya un error, seguir preguntando
    printf("Ingrese cantidad de filas.\n");
    maxfil=request();
    if (maxfil>=100)
      printf("La cantidad de filas debe ser menor a 100.\n");
  } while ((maxfil==0)||(maxfil>100));

  //preguntar por columna
  do {  //mientras haya un error, seguir preguntando
    printf("Ingrese cantidad de columnas.\n");
    maxcol=request();;
    if (maxcol>10)
      printf("La cantidad de columna debe ser menor o igual a 10.\n");
  } while ((maxcol==0)||(maxcol>10));

  //generamos matriz random
  generate(matriz);

  matriz[0][3]='X';
  matriz[1][1]='X';
  matriz[1][2]='X';
  matriz[2][3]='X';

  fila=1;
  columna=2;

  while (1)
  {
    cant=evaluate(matriz, fila, columna);
    printf("%d\n",cant);
    break;
  }

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
      printf("----------Input Error----------\n");
      mistake=1;  //flag error
    }
    else
      cant = cant*10 + (ch - '0');

  }

  if (mistake==1) {
    return 0; //si hubo error devolvemos un 0 como flag
  }
  else {
    return cant; //sino devolvemos el valor
  }
}

//funcion que genera una matriz random
void generate (char matrx[100][10]) {

  int i, h;

  for (i=0;i<100;i++) {
    for (h=0;h<100;h++) {
      if ( (rand()%1+3)==1 )
        matrx[i][h]='X';
    }
  }

}
