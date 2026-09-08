/* malloc example: random string generator*/
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */

int main (){
int i,n;
char *buffer;

printf ("tamanio de la cadena:  ");
scanf ("%d", &i);
buffer = (char*) malloc (i+1);

if (buffer==NULL) exit (1);

for (n=0; n<i; n++)
	buffer[n]=rand()%26+'a';

buffer[i]='\0';
printf ("String random: %s\n",buffer);
free (buffer);

return 0;
}
