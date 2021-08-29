#include <iostream>
#include <queue>
#include <utility>
#define mp make_pair
#define fst first
#define snd second

using namespace std;
int root[200001]={};

int find(int n){
  if(root[n] == n) return n;
  return root[n] = find(root[n]);
}
void merge(int h1, int h2){
  root[find(h1)] = find(h2);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<pair<int, pair<int, int> > > pq;
  int m,n,pay,x,y,z,h1,h2,cost,origin_pay;
  while(1){
    cin >> n >> m;
    if(m == 0 && n == 0) break;
    
    pay = 0;
    origin_pay = 0;
    for(int i=0; i<n; i++) root[i]=i;
    for(int i=0; i<m; i++){
      cin >> x >> y >> z;
      origin_pay += z;
      pq.push(mp(-z,mp(x,y)));
    }

    while(!pq.empty()){
      h1 = pq.top().snd.fst;
      h2 = pq.top().snd.snd;
      cost = -pq.top().fst;
      pq.pop();

      if(find(h1) == find(h2)) continue;
      merge(h1, h2);
      pay += cost;
    }
    cout << origin_pay - pay << "\n";
  }
}