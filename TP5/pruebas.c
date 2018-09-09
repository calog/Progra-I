
#include <stdio.h>

#define TER '\n' //terminador establecido de palabra

int main(void) {
  char ch;
  char array[200];
  for (i=0; (ch=getchar())!= EOF ;i++) {
    array[i]=ch;
  }

  for (i=0; (ch=getchar())!= TER ;i++) {
    printf("%c\n",ch);
  }

}
