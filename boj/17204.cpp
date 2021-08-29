#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,K, visit[151]={}, pointer[151]={}, cur=0, mini=0;
  cin >> N >> K;
  for(int i=0; i<N; i++) cin >> pointer[i];
  visit[0] = 1;

  while(1){
    cur = pointer[cur];
    mini++;
    if(visit[cur]==1){
      mini = -1;
      break;
    }
    if(cur == K) break;
    visit[cur] = 1;
  }

  cout << mini;
}
