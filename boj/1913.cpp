#include <stdio.h>

int dalpaeng2[999][999]={};
int main(){
	int N,K,i,j,t;
	scanf("%d %d", &N, &K);
	int ipos = N/2, jpos = N/2;
	int cc=1, cc2=2;
	int i_result=ipos, j_result=jpos;
	dalpaeng2[ipos][jpos]=1;
	for(i=2; i<=N*N;){
		for(j=0; j<5; j++){
			if(j==0){
				ipos--;
				dalpaeng2[ipos][jpos] = i;
				if(i==K){
					i_result = ipos;
					j_result = jpos;
					}
				i++;
			}
			else if(j==1){
				for(t=0; t<cc; t++){
					jpos++;
					dalpaeng2[ipos][jpos] = i;
					if(i==K){
						i_result = ipos;
						j_result = jpos;
					}
					i++;
				}
				cc+=2;
			}
			else if(j==2){
				for(t=0; t<cc2; t++){
					ipos++;
					dalpaeng2[ipos][jpos] = i;
					if(i==K){
						i_result = ipos;
						j_result = jpos;
					}
					i++;
				}
			}
			else if(j==3){
				for(t=0; t<cc2; t++){
					jpos--;
					dalpaeng2[ipos][jpos] = i;
					if(i==K){
						i_result = ipos;
						j_result = jpos;
					}
					i++;
				}
			}
			else if(j==4){
				for(t=0; t<cc2; t++){
					ipos--;
					dalpaeng2[ipos][jpos] = i;
					if(i==K){
						i_result = ipos;
						j_result = jpos;
					}
					i++;
				}
				cc2+=2;
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ", dalpaeng2[i][j]);
		}
		printf("\n");
	}
	printf("%d %d\n", i_result+1, j_result+1);
}
