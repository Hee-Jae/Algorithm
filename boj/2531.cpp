#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int belt[3000010]={}, sushi[3010]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,d,k,c, pick, cnt=1, maxcnt=0;
  cin >> N >> d >> k >> c;
  sushi[c]++;
  for(int i=0; i<N; i++) cin >> belt[i];
  for(int i=0; i<k; i++){
    pick = belt[i];
    if(sushi[pick]==0) cnt++;
    sushi[pick]++;
  }
  maxcnt = cnt;
  int start=0, end=k-1;
  for(int i=0; i<N; i++){
    pick = belt[start];
    sushi[pick]--;
    if(sushi[pick]==0) cnt--;
    start = (start+1)%N;
    end = (end+1)%N;
    pick = belt[end];
    if(sushi[pick]==0) cnt++;
    sushi[pick]++;
    if(cnt > maxcnt) maxcnt = cnt;
  }
  cout << maxcnt << "\n";
}
