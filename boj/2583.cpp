#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M,N,K;
int square[101][101]={};
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
vector<int> v;
queue<pair<int, int> > q;

// void prtSq(){
// 	printf("\n");
// 	for(int i=0; i<M; i++){
// 		for(int j=0; j<N; j++){
// 			printf("%d ", square[i][j]);
// 		}
// 		printf("\n");
// 	}
// }
void BFS(int x, int y, int cnt){
	q.push(make_pair(x,y));
	square[x][y] = 1;
	while(!q.empty()){
		cnt ++;
		x = q.front().first;
		y = q.front().second;
		square[x][y] = 1;
		q.pop();
		for(int i=0; i<4; i++){
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if(xx>=M || xx<0 || yy>=N || yy<0) continue;
			if(square[xx][yy] == 0){
				q.push(make_pair(xx,yy));
				square[xx][yy] = 1;
			}
		}
	}
	v.push_back(cnt);
}

int main(){
	
	scanf("%d %d %d", &M, &N, &K);
	int x1, x2, y1, y2;
	for(int i=0; i<K; i++){
		scanf("%d %d %d %d", &y1,&x1,&y2,&x2);
		for(int j=x1; j<x2; j++){
			for(int l=y1; l<y2; l++){
				square[j][l] = 1;
			}
		}
	}

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(square[i][j] == 1) continue;
			else{
				//printf("square[%d][%d]: %d\n", i,j,square[i][j]);
				//prtSq();
				BFS(i,j,0);
			}
		}
	}
  sort(v.begin(), v.end());
  int vsize = v.size();
	printf("%d\n", vsize);
  for(int i=0; i<vsize; i++) printf("%d ", v[i]);
}