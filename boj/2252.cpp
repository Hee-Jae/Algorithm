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

int N,M,A,B;
int idgr[32002]={};
vector<vector<int> > v(32002);
queue<int> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int top,next;
  cin >> N;
  for(cin >> M; M; M--){
    cin >> A >> B;
    v[A].pb(B);
    idgr[B]++;
  }

  for(int i=1; i<=N; i++) if(idgr[i]==0) q.push(i);

  while(!q.empty()){
    top = q.front();
    q.pop();
    cout << top << " ";
    for(int i=0; i<v[top].size(); i++){
      next = v[top][i];
      idgr[next]--;
      if(idgr[next] == 0) q.push(next);
    }
  }
}
