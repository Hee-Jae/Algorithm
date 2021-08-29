#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
vector<pair<pair<int,int>, pair<int,int> > > v(101);
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T,n,k,t,m, team, prb, scr;
  for(cin >>T; T; T--){
    cin >> n >> k >> t >> m;
    int sb[102][102]={}, ss[102]={};
    int sbcnt[102]={}, sbtime[102]={};
    for(int i=0;i<m;i++){
      cin >> team >> prb >> scr;
      if(sb[team][prb] < scr) sb[team][prb] = scr;
      sbcnt[team]++;
      sbtime[team] = i;
    }
    for(int i=1; i<=n; i++){
      for(int j=1; j<=k; j++){
        ss[i] += sb[i][j];
      }
      v[i]=mp(mp(-ss[i],sbcnt[i]), mp(sbtime[i],i));
      // v.pb(mp(mp(-ss[i],sbcnt[i]), mp(sbtime[i],i)));
    }
    sort(v.begin()+1, v.begin()+n+1);
    
    for(int i=1; i<=n; i++){
      // cout << v[i].nd.nd << " : " << v[i].st.st << " " << v[i].st.nd << " " << v[i].nd.st << "\n";
      if(v[i].nd.nd == t) cout << i << "\n";
    }
  }
}
