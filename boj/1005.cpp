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

int T, N, K, X, Y, W, top, seq;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(cin >> T; T; T--){
    cin >> N >> K;
    int indg[1002]={}, weight[1002]={}, add[1002]={};
    vector<vector<int> > v(1002);
    queue<int> q;
    for(int i=1; i<=N; i++) cin >> weight[i];
    for(int i=1; i<=K; i++){
      cin >> X >> Y;
      v[X].pb(Y);
      indg[Y]++;
    }
    cin >> W;

    for(int i=1; i<=N; i++)
      if(indg[i]==0) q.push(i);
    
    int next;
    while(!q.empty()){
      top = q.front();
      q.pop();
      if(top == W) break;
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
    cout << weight[W] << "\n";
  }
}
