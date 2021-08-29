#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int root[10010]={};
int find(int n){
  if(root[n] == n) return n;
  return root[n] = find(root[n]);
}

void merge(int a, int b){
  root[find(b)] = find(a);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M,K,v,w,cost[10010]={};
  cin >> N >> M >> K;
  for(int i=1; i<=N; i++) root[i] = i;
  for(int i=1; i<=N; i++) cin >> cost[i];
  for(int i=1; i<=M; i++){
    cin >> v >> w;
    if(find(v) == find(w)) continue;
    if(cost[find(v)] > cost[find(w)]) merge(w,v);
    else merge(v,w);
  }
  int ans=0;
  for(int i=1; i<=N; i++){
    if(root[i]==i) ans += cost[i];
  }
  if(ans <= K) cout << ans << "\n";
  else cout << "Oh no\n";
}
