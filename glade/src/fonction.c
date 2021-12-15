#include "fonction.h"
#include <stdio.h>

int verif(char log[],char pw[])
{
int trouve=0;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("n_utilisateur.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{
if ((strcmp(ch1,log)==0)&&(strcmp(ch2,pw)==0))
trouve=1;
}

fclose(f);
}

return (trouve);
}

