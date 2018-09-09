
#include <stdio.h>

#define TER '\n' //terminador establecido de palabra

int main(void) {
  int i;
  char ch, array[200];

  for (i=0; (ch=getchar())!= EOF ;i++) {
    array[i]=ch;
  }

  for (i=0; (array[i]!=TER) ;i++) {
    printf("%c\n",ch);
  }

}
