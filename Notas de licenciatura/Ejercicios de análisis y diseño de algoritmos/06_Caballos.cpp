// trabajo final
// Amador Ortega Christian Amauri

#include <stdio.h>
#include <iostream>

void recorre_caballo(int x,int y);
bool marca_visitado[8][8];


int main(){
	int i,j,x =0,y=0;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			marca_visitado[i][j] = 0;//false
		}
	}
	
	recorre_caballo(x,y);
	
	return 0;
}

void recorre_caballo(int x,int y){
	if( (!marca_visitado[x][y]) && (x>=0) && (x<=8) && (y>=0) && (y<=8) ){
		marca_visitado[x][y] = true;
		printf("[%d][%d]\n",x,y);
		for(int i=1;i<=8;i++){
			switch(i){
				case 1:
					recorre_caballo(x+2,y-1);
					break;
				case 2:
					recorre_caballo(x+2,y+1);
					break;
				case 3:
					recorre_caballo(x+1,y+2);
					break;
				case 4:
					recorre_caballo(x-1,y+2);
					break;
				case 5:
					recorre_caballo(x-2,y-1);
					break;
				case 6:
					recorre_caballo(x-2,y+1);
					break;
				case 7:
					recorre_caballo(x+1,y-2);
					break;
				case 8:
					recorre_caballo(x-1,y-2);
					break;
				default:
					printf("you werent supposed to be here :/ \n");
					break;		
			}
		}
	}
}

