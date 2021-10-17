
#include <stdio.h>
#include "fonctionrih.h"
int main (){
int a;
int b;
 printf ("\n saisirle premier nombre");
scanf ("%d",a);
do {
 printf ("\n saisir le second nombre");
scanf ("%d",b);
}while (b==0);
printf ("\n%d+%d=%d",a,b,sommer(a,b));
printf ("\n%d-%d=%d",a,b,soustraire(a,b));
printf ("\n%d/%d=%f\n",a,b,diviser(a,b));
return (0);
}

