#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

int main(){
  int T;
  cin >> T;
  for(int test=1; test<=T; test++){
    int N,s,e, impos=0, turn=0;
    vector<pair<pair<int, int>, pair<int, int> > > v;
    int sched[1441]={};
    cin >> N;
    for(int i=0; i<N; i++){
      cin >> s >> e;
      v.pb(mp(mp(s,e), mp(i,0)));
      for(int j=s; j<e; j++) sched[j] ++;
    }
    for(int j=0; j<=1440; j++){
      if(sched[j] > 2){
        impos = 1;
        break;
      }
    }
    sort(v.begin(), v.end());
    int next = v[0].first.second;
    v[0].second.second = 1;
    for(int j=1; j<N; j++){
      if(v[j].first.first >= next){
        v[j].second.second = 1;
        next = v[j].first.second;
      }
    }
    char ans[1001]={};
    for(int j=0; j<N; j++){
      if(v[j].second.second == 1) ans[v[j].second.first] = 'C';
      else ans[v[j].second.first] = 'J';
    }
    cout << "Case #" << test << ": ";
    if(impos) cout << "IMPOSSIBLE\n";
    else{
      for(int i=0; i<N; i++) cout << ans[i];
      cout << "\n";
    }
  } // test case
} // main