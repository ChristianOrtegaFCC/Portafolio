#include <iostream>

int main(){
bool a[10];
bool *a_pointers[10];
int i;

for(i=0;i<10;i++){ // llenas A[i] y a_pointers[i]
	//a[i] = 'a'+i;//(i+1)*10;
	if ((i/2)== 0) a[i] = true; else a[i] = false;
	a_pointers[i] = &a[i];
}

// imprimes a[i]
for(i=0;i<10;i++){if (a[i] == true) printf("True\n"); else printf("false\n"); }// printf("a[%d] = %c\n",i,a[i]); printf("\n");

// imprimes &a[i]
for(i=0;i<10;i++) printf("&a[%d] = %d\n",i,&a[i]); printf("\n");

// imprimes a_pointers[i]
for(i=0;i<10;i++) printf("a_pointers[%d] = %d\n",i,a_pointers[i]); printf("\n");

// imprimes a_pointers[0] + i
for(i=0;i<10;i++) printf("a_pointers[0] + %d = %d\n",i,a_pointers[0]+i); printf("\n");

// imprimes &a_pointers[i]
for(i=0;i<10;i++) printf("&a_pointers[%d] = %d\n",i,&a_pointers[i]); printf("\n");

// imprimes *a_pointers[i]
for(i=0;i<10;i++){if (a[i] == true) printf("True\n"); else printf("false\n"); } //printf("*a_pointers[%d] = %c\n",i,*a_pointers[i]); printf("\n");

return 0;
}
