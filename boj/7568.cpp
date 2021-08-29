#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;

int main(){
  int N,x,y;
  vector<pair<int, int> > v;
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d %d", &x, &y);
    v.pb(mp(x,y));
  }
  
  int rank[52]={}, cnt=0;
  for(int i=0; i<N; i++){
    cnt = 0;
    for(int j=0; j<N; j++){
      if(v[i].st < v[j].st && v[i].nd < v[j].nd){
        cnt++;
      }
    }
    rank[i] = cnt+1;
  }
  for(int i=0; i<N; i++) printf("%d ", rank[i]);
}