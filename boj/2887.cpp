#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

typedef struct planet{
  int idx,x,y,z;
} plt;

bool compx(plt p1, plt p2){
  return p1.x < p2.x;
}
bool compy(plt p1, plt p2){
  return p1.y < p2.y;
}
bool compz(plt p1, plt p2){
  return p1.z < p2.z;
}
int getcost(plt p1, plt p2){
  int res;
  res = min(abs(p1.x-p2.x), abs(p1.y-p2.y));
  res = min(res, abs(p1.z-p2.z));
  return res;
}

int root[100010]={};
int find(int n){
  if(root[n] == n) return n;
  return root[n] = find(root[n]);
}
void merge(int a, int b){
  root[find(b)] = find(a);
}

vector<plt> v;
priority_queue<pair<int, pair<int, int> > > pq;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,x,y,z;
  plt p;
  cin >> N;
  for(int i=0; i<=N; i++) root[i] = i;
  for(int i=0; i<N; i++){
    cin >> p.x >> p.y >> p.z;
    p.idx = i;
    v.pb(p);
  }

  int vsize = v.size();
  int cost;

  sort(v.begin(), v.end(), compx);
  for(int i=1; i<vsize; i++){
    cost = getcost(v[i], v[i-1]);
    pq.push(mp(-cost, mp(v[i].idx, v[i-1].idx)));
  }

  sort(v.begin(), v.end(), compy);
  for(int i=1; i<vsize; i++){
    cost = getcost(v[i], v[i-1]);
    pq.push(mp(-cost, mp(v[i].idx, v[i-1].idx)));
  }

  sort(v.begin(), v.end(), compz);
  for(int i=1; i<vsize; i++){
    cost = getcost(v[i], v[i-1]);
    pq.push(mp(-cost, mp(v[i].idx, v[i-1].idx)));
  }

  int ans = 0;
  int node1, node2;
  while(!pq.empty()){
    cost = -pq.top().st;
    node1 = pq.top().nd.st;
    node2 = pq.top().nd.nd;
    pq.pop();
    if(find(node1) == find(node2)) continue;
    merge(node1, node2);
    ans += cost;
  }

  cout << ans;
}
