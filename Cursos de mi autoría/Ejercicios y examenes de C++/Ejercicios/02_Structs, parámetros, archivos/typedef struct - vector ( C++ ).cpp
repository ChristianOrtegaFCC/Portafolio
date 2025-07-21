#include <stdio.h>
#include <string.h>
#define max 3

// ajederz
// prismas

typedef struct vector{
	int x;
	int y;
	char descripcion[100];
}vec;

void suma(vec vectores[max]);
int multiplica(vec vectores[max]);
void declara(vec vectores[max]);

int main(){
	vec vectores[max];
	
	declara(vectores);
	
	printf("del primero, x = %d\n",vectores[0].x);
	printf("del primero, y = %d\n",vectores[0].y);
	printf("del segundo, x = %d\n",vectores[1].x);
	printf("del segundo, y = %d\n",vectores[1].y);
	
	suma(vectores);
	//multiplica(vectores);
	
	return 0;
}

void suma(vec vectores[max]){
	vectores[2].x = vectores[0].x + vectores[1].x;
	vectores[2].y = vectores[0].y + vectores[1].y;
	strcpy(vectores[2].descripcion,"este_es_la_suma_de_v1_y_v2");
	
	printf("\nV1+V2 = (%d,%d)\n",vectores[2].x,vectores[2].y);
	return;
}

int multiplica(vec vectores[max]){
	int a,b,c,d,res;
	a = vectores[0].x; b = vectores[1].x;
	c = vectores[0].y; d = vectores[1].y;
	res=((a*b)+(c*d));
	
	printf("\nV1*V2 = %d\n",res);
	return res;
}

void declara(vec vectores[max]){
	int i;
	for(i=0;i<max-1;i++){
		printf("[%d]:\n",i);
		printf("valor de x: ");
		scanf("%d",&vectores[i].x);
	
		printf("valor de y: ");
		scanf("%d",&vectores[i].y);
	
		printf("Descripcion del vector:\n   ");
		scanf("%s",&vectores[i].descripcion);
	}
	return;
}
