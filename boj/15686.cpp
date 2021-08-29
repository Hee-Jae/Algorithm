#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int N, M, cn=0, hn=0, mindist=100000000, minsum=100000000;
int city[55][55]={}, chicken[20][2]={}, house[110][2];
int dist(int x1, int y1, int x2, int y2){
  return abs(x2-x1)+abs(y2-y1);
}
void btk(int n, int arr[], int idx){
  arr[idx] = n;
  if(idx+1 == M){
    int x1, y1, x2, y2, tdist, summ=0;
    for(int i=0; i<hn; i++){
      x1 = house[i][0];
      y1 = house[i][1];
      mindist = 100000000;
      for(int j=0; j<=idx; j++){
        x2 = chicken[arr[j]][0];
        y2 = chicken[arr[j]][1];
        tdist = dist(x1,y1,x2,y2);
        if(mindist > tdist) mindist = tdist;
      }
      summ += mindist;
    }
    if(minsum > summ) minsum = summ;
  }
  else{
    for(int i=n+1; i<cn; i++) btk(i,arr,idx+1);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  int arr[15]={};
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> city[i][j];
      if(city[i][j]==1){
        house[hn][0] = i;
        house[hn++][1] = j;
      }
      else if(city[i][j]==2){
        chicken[cn][0] = i;
        chicken[cn++][1] = j;
      }
    }
  }
  for(int i=0; i<=cn-M; i++) btk(i,arr,0);
  cout << minsum << "\n";
}
