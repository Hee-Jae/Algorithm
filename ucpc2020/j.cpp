#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

vector<vector<int> > v(100002);
int N,M,K,Ai;
int origin[100002]={}, hwakjin[100002]={};
int comp[100002]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=1; i<=N; i++) origin[i] = -1;
  for(int i=0; i<M; i++){
    for(cin >> K; K; K--){
      cin >> Ai;
      v[i].pb(Ai);
    }
  }
  for(int i=1; i<=N; i++) cin >> hwakjin[i];

  int whatislove, whoareyou=0, howbigisit;
  howbigisit = v[M-1].size();
  whatislove = hwakjin[v[M-1][0]];
  for(int i=1; i<howbigisit; i++){
    if(hwakjin[v[M-1][i]] != whatislove) whoareyou = 1;
    whatislove = hwakjin[v[M-1][i]];
  }
  if(whoareyou){
    cout << "NO\n";
    return 0;
  }


  int size, check=1;
  for(int i=0; i<M; i++){
    size = v[i].size();
    check = 1;
    
    for(int j=0; j<size; j++)
      check = check & hwakjin[v[i][j]];
    
    for(int j=0; j<size; j++){
      if(origin[v[i][j]] == -1) origin[v[i][j]] = check;
    }
  }

  for(int i=1; i<=N; i++){
    if(origin[i] == -1) origin[i] = hwakjin[i];
  }
  int flag = 0;
  
  for(int i=1; i<=N; i++) comp[i] = -1;
  for(int i=0; i<M; i++){
    size = v[i].size();
    check = 0;
    for(int j=0; j<size; j++)
      check = check | origin[v[i][j]];
    for(int j=0; j<size; j++){
      comp[v[i][j]] = check;
    }
  }

  for(int i=1; i<=N; i++){
    if(comp[i] == -1) comp[i] = origin[i];
  }
  for(int i=1; i<=N; i++){
    if(comp[i] != hwakjin[i]) flag = 1;
  }
  if(flag==1) cout << "NO\n";
  else{
    cout << "YES\n";
    for(int i=1; i<=N; i++){
      cout << origin[i] << " ";
    }
  }
}