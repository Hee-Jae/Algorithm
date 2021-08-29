#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
vector<pair<int, pair<int, int> > > v;
int N, nc[110]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int nation, number, score;
  for(int i=0; i<N; i++){
    cin >> nation >> number >> score;
    v.pb(mp(-score,mp(nation,number)));
  }
  sort(v.begin(), v.end());
  int cnt=0, r=0;
  while(cnt<3){
    if(nc[v[r].nd.st] == 2){
      r++;
      continue;
    }
    cout << v[r].nd.st << " " << v[r].nd.nd << "\n";
    cnt++;
    nc[v[r].nd.st]++;
    r++;
  }
}
