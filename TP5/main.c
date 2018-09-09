
#include <stdio.h>

//definimos algunas constantes
#define MAX 10 //maximos caracteres de la palabra
#define TER '\n' //terminador establecido de palabra

int validate (char *w1, char *w2);  //la función evalúa si es posible formar la primer palabra con las letras de la segunda, recibe punteros al inicio de ambas palabras.
int wordlength (char *word);  //calcula la cantidad de caracteres en una palabra
int askuser (char *point);  //toma las palabras de la consola
void convert (char arr[]);  //cambia las mayusculas por sus equivalentes en minusculas

int main (void) {
    int result, error, i;
    char word1[MAX], word2[MAX];

    //ingreso de palabras
    do {
      printf("-----------------------\n");
      printf("Ingrese primera palabra\n");
      error=askuser(word1);
    } while (error==1);

    do {
      printf("\n-----------------------\n");
      printf("Ingrese segunda palabra\n");
      error=askuser(word2);
    } while (error==1);

    //mostramos palabras elegidas
    i=0;
    printf("\n****************************************\n");
    printf("Primera palabra: ");
    while ( word1[i] != TER ) {
      printf("%c",word1[i]);
      i++;
    }
    printf("\n");

    i=0;
    printf("Segunda palabra: ");
    while ( word2[i] != TER ) {
      printf("%c",word2[i]);
      i++;
    }
    printf("\n");
    printf("****************************************\n");

    printf("HASTA ACA LLEGA LA PARTE DE LUCAS\n");

    //pasamos todas las mayusculas a minisculas
    convert(word1);
    convert(word2);

    //validamos las palabras
    result=validate(word1,word2);
    printf("%d\n",result);
}

int validate (char *w1, char *w2) {
    //Declaro variables
    int i,j; //variables para indicar posición en arreglo
    int wordlength1,wordlength2; //variables que indican la cantidad de caracteres en la palabra 1 y 2
    int found=0; //la variable vale 1 si ya se ha encontrado la letra evaluada de la palabra 1 en la palabra 2
    int count=0,ok=1,toughluck=0; //count se utiliza para comparar si la palabra se puede devolver o no, ok y toughluck son los valores que devolverá la función

    //comienza la ejecución del programa
    wordlength1=wordlength (w1);   //devuelve la cantidad de caracteres en la palabra 1
    wordlength2=wordlength (w2);   //idéntico para la segunda palabra
    if(wordlength2<wordlength1) //si la palabra 2 tiene menos letras que la palabra 1, luego no se podrá formar con las letras de la palabra 2 la palabra 1
    {
        return toughluck;
    }
    for (i=0;w1[i];i++)   //evalúa si se llegó al terminador de la primera palabra
    {
        for (j=0;w2[j];j++)	//evalúa si se llegó al final de la segunda palabra.
        {
            if (w1[i]==w2[j])	//si ambas letras coinciden
            {
                if(found==0)	//si la letra a buscar no ha sido encontrada aún, se prosigue a marcar como encontrada, sino no se hace nada
                {
                    w2[j]=' '; //para que no se continúe considerando esta letra, se le da el valor ' ', que nunca coincidirá con una letra de la palabra 1
                    count++;  //se incrementa la cantidad de letras en común
                    found=1; //se ubica un 1 en found para evitar que se sigan considerando si coinciden
                }
            }
        }
        found=0;  //regreso el valor de found al original
    }
    if (count==wordlength1) //si la cantidad de letras coincidentes coincide con la cantidad de letras de la palabra 1
    {
        return ok;
    }
    else
    {
        return toughluck;
    }
}

int wordlength (char *word) {
    int count=0, i=0; //count indica cuántas letras hay en la palabra, i se utiliza para moverse en el arreglo
    while (word[i])     //evalúa si el carácter indicado es el terminador de la palabra
    {
        count++;
        i++;
    }
    return count;
}

int askuser (char *point) {
  int mistake=0, j=0, i, mistakes=0;
  char ch;
  char valid[52]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  while ( (ch = getchar()) != '\n') {

    if (mistakes==0) { //si estamos dentro del segmento

      for (i=0;i<52;i++) {  //evaluamos con todas las letras posibles

        if ( j>=MAX) {  //si llegamos al final de la palabra
          mistakes=1; //seteamos error de violacion de segmento
          break;
        }
        else if ( ch==valid[i] ) { //si el caracter es valido esta bien
          *(point + j)=ch;
          mistake=0;  //el caracter era valido asi que seteamos el flag en 0
          break;  //salimos del ciclo para que el flag quede en 0
        }
        else  { //si el caracter no es valido seteamos el flag en 1
          mistake=1;
        }

      } //termina for
      j++;  //nos movemos a la siguiente posicion del arreglo

    }

  } //termina ingreso de datos
  *(point+j)=TER;  //dejamos un terminador en la ultima posicion

  if (mistake==1) //se ingreso caracter no valido
    printf("\nInput Error\n");

  if (mistakes==1) { //se violo segmento
    printf("\nLa cantidad de maxima de letras es %d.\n",MAX);
    mistake=1;
  }

  return mistake; //devolvemos el flag de error
}

void convert (char *arr) {
	char mayu[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char minu[]= "abcdefghijklmnopqrstuvwxyz";
	int i, j;

	for(i=0;arr[i];++i)
	{
		for(j=0;mayu[j];++j)
		{
			if(arr[i]==mayu[j])
			{
				arr[i]=minu[j];
			}
		}
	}
	printf("%s\n",arr);
}
