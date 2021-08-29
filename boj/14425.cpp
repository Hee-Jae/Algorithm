#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int N,M,cnt=0;
vector<string> s1;
vector<string> s2;
// int myCmp(int low, int high, string s){
//   if(low > high) return 0;
//   int mid = (low+high)/2;
//   if(s < s1[mid]) mid = myCmp(low, mid, s);
//   else if(s > s1[mid]) mid = myCmp(mid, high, s);
//   else return 1;
//   return 0;
// }
void myCmp(int low, int high, string s){
  // cout << s << "\n";
  // cout << "low : " << low << "\n";
  // cout << "high : " << high << "\n";
  if(low > high) return;
  int mid = (low+high)/2;
  if(s < s1[mid]) myCmp(low, mid-1, s);
  else if(s > s1[mid]) myCmp(mid+1, high, s);
  else{
    cnt++;
    return;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> str;
    s1.pb(str);
  }
  for(int i=0; i<M; i++){
    cin >> str;
    s2.pb(str);
  }
  sort(s1.begin(), s1.end());

  // if(s1[0] < s2[0]) cout << "s2\n";
  // else if(s1[0] > s2[0]) cout << "s1\n";
  // else cout << "==\n";
  // cout << s1[0] << "\n";
  // cout << s2[0] << "\n";
  for(int i=0; i<M; i++){
    myCmp(0, N-1, s2[i]);
  }
  cout << cnt;
}
