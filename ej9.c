#include<stdio.h>

int main(void) {

    double x, tercerdec;
while (1) {
    printf("Ingrese el numero\n");
    scanf("%lf\n",&x);
    printf("El numero es %f\n",x);
    if ((x-(int)x)>=0.5)
        printf("El numero redondeado es %d\n",(int)x+1);
    else
        printf("El numero redondeado es %d\n",(int)x);
    printf("El numero entero superior es %d\n",(int)x+1);
    printf("El numero entero inferior es %d\n",(int)x);
    printf("La parte decimal de %f es %f\n",x,(x-(int)x));
    tercerdec=((x-(int)x)*100)-(int)((x-(int)x)*100);
    printf("%f\n",tercerdec);



    if (tercerdec>=0.5)
        printf("El numero redondeado es %f\n",x-(tercerdec/100)+0.01);
    else
        printf("El numero redondeado es %f\n",x-tercerdec/100);

}
return 0;
}
