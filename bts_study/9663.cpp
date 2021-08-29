#include <iostream>
#include <vector>
#include <cmath>
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
using namespace std;
int cnt = 0;
int N;

int check(int x, int y, int node[], int size){
  for(int i=0; i<size; i++){
    if(node[i] == y) return 0;
    if(abs(i-x) == abs(node[i]-y)) return 0;
  }
  return 1;
}
void btk(int x, int y, int count, int node[]){
  if(count == N){
    cnt ++;
    return;
  }
  node[count-1] = y;
  for(int i=0; i<N; i++){
    if(check(x+1,i, node, count)){
      btk(x+1, i, count+1, node);
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int node[16]={};
  cin >> N;
  for(int i=0; i<N; i++) btk(0, i, 1, node);
  cout << cnt << "\n";
}