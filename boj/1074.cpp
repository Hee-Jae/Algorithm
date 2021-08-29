#include <stdio.h>
//32769
int ans = 0;
int r,c;
void label(int x, int y, int size, int cnt){
	if(size == 2){
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				if((x+i)==r && (y+j)==c){
					ans = cnt;
				}
        cnt++;
			}
		}
	}
	else{
    int unit = size*size/4;
		size /= 2;
    if(r >= x+size && c >= y+size) label(x+size,y+size,size, cnt+unit*3);
		else if(r >= x+size && c >= y) label(x+size,y,size, cnt+unit*2);
    else if(r >= x && c >= y+size) label(x,y+size,size, cnt+unit);
    else label(x,y,size, cnt);
	}
}
int main(){
	int N, size=1;
	scanf("%d %d %d", &N, &r, &c);
	while(N--) size*=2;
	label(0,0,size,0);
  printf("%d\n", ans);
	return 0;
}