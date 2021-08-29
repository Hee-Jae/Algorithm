#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int apple[100001]={}, idx=0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, tree, sum=0, flag = 0;
  int cnt_one = 0, cnt_n = 0;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> tree;
    if(tree == 1) cnt_one++;
    else apple[idx++] = tree;
  }
  int tmpi=0, sub;
  while(cnt_one > 0 && tmpi<idx){
    if(cnt_one*2 > apple[tmpi]){
      sub = apple[tmpi]/2;
      apple[tmpi] -= sub*2;
      if(apple[tmpi] == 1) cnt_one++;
      apple[tmpi] = 0;
      cnt_one -= sub;
    }
    else{
      apple[tmpi] -= cnt_one*2;
      cnt_one = 0;
    }
    tmpi++;
  }
  for(int i=0; i<idx; i++) sum += apple[i];
  if(cnt_one > 0) flag = 0;
  else{
    if(sum%3 != 0) flag = 0;
    else flag = 1;
  }
  if(flag) cout << "YES\n";
  else cout << "NO\n";
}
