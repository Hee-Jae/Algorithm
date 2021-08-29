#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int root[110]={};
vector<pair<double, double> > pos(110);
vector<pair<double, pair<int, int> > > edge;

int find(int n){
  if(root[n] == n) return n;
  return root[n] = find(root[n]);
}

void merge(int a, int b){
  root[find(b)] = find(a);
}

int main(){
  int n,s1,s2;
  double x,y,x1,y1,cost,ans=0;
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%lf %lf", &x,&y);
    pos[i] = mp(x,y);
    root[i] = i;
  }
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      x = pos[i].st;
      y = pos[i].nd;
      x1 = pos[j].st;
      y1 = pos[j].nd;
      cost = (x-x1)*(x-x1) + (y-y1)*(y-y1);
      cost = sqrt(cost);
      edge.pb(mp(cost,mp(i,j)));
    }
  }
  sort(edge.begin(), edge.end());
  int size = edge.size();
  for(int i=0; i<size; i++){
    cost = edge[i].st;
    s1 = edge[i].nd.st;
    s2 = edge[i].nd.nd;
    if(find(s1) == find(s2)) continue;
    merge(s1,s2);
    ans += cost;
  }
  printf("%.2lf\n", ans);
}
