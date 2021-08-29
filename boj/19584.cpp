#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
lli N,M, place[200010]={}, tree[524300]={};
lli x,y,u,v,c, maxv=0;

vector<pair<int, int> > pos(200010);
void update(int node, int start, int end, int left, int right, lli value){
  if(right<start || end<left) return;
  else if(left<=start && end<=right) tree[node] += value;
  else{
    int mid = (start+end)/2;
    update(node*2, start, mid, left, right, value);
    update(node*2+1, mid+1, end, left, right, value);
  }
}
void propagte(int node, int start, int end, lli value){
  tree[node] += value;
  if(start==end){
    if(tree[node] > maxv) maxv = tree[node];
    return;
  }
  int mid = (start+end)/2;
  propagte(node*2, start, mid, tree[node]);
  propagte(node*2+1, mid+1, end, tree[node]);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  int distance=1;
  for(int i=0; i<N; i++){
    cin >> x >> y;
    pos[i] = mp(y+1,i+1);
  }
  sort(pos.begin(), pos.begin()+N);
  place[pos[0].nd] = 1;
  for(int i=1; i<pos.size(); i++){
    if(pos[i].st == pos[i-1].st) place[pos[i].nd] = distance;
    else place[pos[i].nd] = ++distance;
  }
  // cout << "place : ";
  // for(int i=1; i<=N; i++) cout << place[i] << " ";
  for(int i=0; i<M; i++){
    cin >> u >> v >> c;
    if(place[u] > place[v]) update(1,1,distance,place[v],place[u],c);
    else update(1,1,distance,place[u],place[v],c);
  }
  propagte(1,1,distance,0);
  // for(int i=1; i<=maxy; i++) cout << last[i] << " ";
  cout << maxv;
}
