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

int N,M, X,Y,indg[32002]={};
vector<vector<int> > v(32002);
priority_queue<int> pq;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cur, next;
  cin >> N;
  for(cin >> M; M; M--){
    cin >> X >> Y;
    v[X].pb(Y);
    indg[Y]++;
  }

  for(int i=1; i<=N; i++)
    if(indg[i]==0) pq.push(-i);

  while(!pq.empty()){
    cur = -pq.top();
    pq.pop();
    cout << cur << " ";
    for(int i=0; i<v[cur].size(); i++){
      next = v[cur][i];
      indg[next]--;
      if(indg[next]==0) pq.push(-next);
    }
  }
  cout << "\n";
}
