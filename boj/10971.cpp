#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int N, W[20][20]={};
int minw = 1e9;
void search(int cur, int weight, vector<int> visit, int cnt, int dest){
  visit[cur] = 1;
  if(cnt==N){
    if(W[cur][dest]==0) return;
    weight += W[cur][dest];
    if(minw > weight){
      minw = weight;
    }
    return;
  }
  for(int i=0; i<N; i++){
    if(W[cur][i] > 0 && !visit[i]){
      search(i, weight+W[cur][i], visit, cnt+1, dest);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  vector<int> visit(20);
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> W[i][j];
  
  for(int i=0; i<N; i++) search(i,0,visit,1,i);
  cout << minw;
}