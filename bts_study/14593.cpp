#include <iostream>
#include <vector>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<pii, pii> > v;
  int N,S,C,L;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> S >> C >> L;
    v.pb(mp(mp(S,-C), mp(-L,i)));
  }
  sort(v.begin(), v.end(), greater<pair<pii, pii> >());
  // for(int i=0; i<N; i++)
  //   cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.first << "\n";
  cout << (v[0].second.second + 1);
}