#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int N,s,e,w, dp[100020]={};
queue<pair<int, int> > q;
priority_queue<pair<int, int> > pq;
vector<pair<pair<int, int>,int > > v(100020);
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> s >> e >> w;
    v[i] = mp(mp(s,e),w);
  }
  sort(v.begin(),v.begin()+N);
  
  dp[0] = v[i].nd;
}
