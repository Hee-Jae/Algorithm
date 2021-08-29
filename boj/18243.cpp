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
int N,M, A,B,top,sc;
int buddy[102][102]={};
queue<pair<int,int> > q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(cin>>M; M; M--){
    cin >> A >> B;
    buddy[A][B] = 1;
    buddy[B][A] = 1;
  }
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(buddy[i][j] == 1) q.push(mp(j,1));
    }
    while(!q.empty()){
      top = q.front().st;
      sc = q.front().nd;
      q.pop();
      for(int j=1; j<=N; j++){
        if(j==i) continue;
        if(buddy[i][j] == 0 && buddy[top][j] == 1){
          q.push(mp(j,sc+1));
          buddy[i][j] = sc+1;
        }
      }
    }
  }

  // for(int i=1; i<=N; i++){
  //   for(int j=1; j<=N; j++){
  //     cout << buddy[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  int sati=1;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(i==j) continue;
      if(buddy[i][j] > 6 || buddy[i][j]==0){
        sati = 0;
        break;
      }
    }
    if(sati==0) break;
  }
  if(sati) cout << "Small World!\n";
  else cout << "Big World!\n";
}
