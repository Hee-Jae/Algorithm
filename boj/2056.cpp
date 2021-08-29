#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int N, K, X, top, maxweight=0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int indg[10002]={}, weight[10002]={}, add[10002]={};
  vector<vector<int> > v(10002);
  queue<int> q;
  for(int i=1; i<=N; i++){
    cin >> weight[i] >> K;
    for(int j=1; j<=K; j++){
      cin >> X;
      v[i].pb(X);
      indg[X]++;
    }
  }

  for(int i=1; i<=N; i++)
    if(indg[i]==0) q.push(i);
    
  int next=0;
  while(!q.empty()){
    top = q.front();
    q.pop();
    if(weight[top] > maxweight) maxweight = weight[top];
    for(int i=0; i<v[top].size(); i++){
      next = v[top][i];
      indg[next]--;
      if(add[next] < weight[top]) add[next] = weight[top];
      if(indg[next] == 0){
        q.push(next);
        weight[next] += add[next];
      }
    }
  }
  cout << maxweight << "\n";
}
