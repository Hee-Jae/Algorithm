#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

#define MAX_VALUE 987654321
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int N,M;

void dijkstra(int x, int y, int arr[][126], vector<vector<int> >& dist){
	priority_queue<pair<int,pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > pq;
	pq.push(make_pair(arr[0][0],make_pair(0,0)));
	dist[0][0] = arr[0][0];
	while(!pq.empty()){
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for(int i=0; i<4; i++){
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if(xx < M && xx >= 0 && yy < N && yy >= 0){
				int v = arr[xx][yy];
				if(dist[xx][yy] > dist[x][y] + v){
					dist[xx][yy] = dist[x][y] + v;
					pq.push(make_pair(dist[xx][yy],make_pair(xx,yy)));	
				}
			}
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	vector<vector<int> > dist;
	dist.assign(M+1, vector<int>(N+1,MAX_VALUE));
	char miro[126][126]={};
	int my_miro[126][126]={};
	for(int i=0; i<M; i++){
		scanf("%s",miro[i]);
	}
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			my_miro[i][j] = miro[i][j] - '0';
		}
	}
	dijkstra(0,0,my_miro,dist);
	printf("%d\n",dist[M-1][N-1]);
	return 0;
}