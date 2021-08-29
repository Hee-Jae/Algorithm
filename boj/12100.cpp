#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int N, max_score=0;

int score(vector<int> board){
  int res = 0;
  for(int i=0; i<N*N; i++){
    if(board[i] < 0) board[i] = -board[i];
    if(board[i] > res) res = board[i];
  }
  return res;
}
void prtboard(vector<int> board){
  cout << "\n";
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout << board[i*N+j] << " ";
    }
    cout << "\n";
  }
}

void simulation(vector<int> board, int dir, int play){
  int k;
  bool hapche;
  // prtboard(board);
  for(int i=0; i<N*N; i++) if(board[i]<0) board[i] *= -1;
  if(dir==1){ // 오른쪽
    for(int i=0; i<N; i++){
      for(int j=(i+1)*N-2; j>=i*N; j--){
        hapche = false;
        if(board[j] == 0) continue;
        k = j;
        while(k+1 <= (i+1)*N-1){
          k++;
          if(board[k] != 0){
            if(board[k] == board[j]){
              board[k] += board[j];
              board[k] = -board[k];
              board[j] = 0;
              hapche = true;
            }
            k--;
            break;
          }
        }
        if(!hapche){
          if(k == j) continue;
          board[k] = board[j];
          board[j] = 0;
        }
      }
    }
  }
  if(dir==2){ // 왼쪽
    for(int i=0; i<N; i++){
      for(int j=i*N+1; j<=(i+1)*N-1; j++){
        hapche = false;
        if(board[j] == 0) continue;
        k = j;
        while(k-1 >= i*N){
          k--;
          if(board[k] != 0){
            if(board[k] == board[j]){
              board[k] += board[j];
              board[k] = -board[k];
              board[j] = 0;
              hapche = true;
            }
            k++;
            break;
          }
        }
        if(!hapche){
          if(k == j) continue;
          board[k] = board[j];
          board[j] = 0;
        }
        // cout << "[k,j] : " << k  << ","<< j << "\n";
        // prtboard(board);
      }
    }
  }
  else if(dir==3){ // 위
    for(int i=0; i<N; i++){
      for(int j=i+N; j<=N*(N-1)+i; j+=N){
        hapche = false;
        if(board[j] == 0) continue;
        k = j;
        while(k-N >= i){
          k-=N;
          if(board[k] != 0){
            if(board[k] == board[j]){
              board[k] += board[j];
              board[k] = -board[k];
              board[j] = 0;
              hapche = true;
            }
            k+=N;
            break;
          }
        }
        if(!hapche){
          if(k == j) continue;
          board[k] = board[j];
          board[j] = 0;
        }
      }
    }
  }
  else if(dir==4){ // 아래
    for(int i=0; i<N; i++){
      for(int j=N*(N-1)+i-N; j>=i; j-=N){
        hapche = false;
        if(board[j] == 0) continue;
        k = j;
        while(k+N <= N*(N-1)+i){
          k += N;
          if(board[k] != 0){
            if(board[k] == board[j]){
              board[k] += board[j];
              board[k] = -board[k];
              board[j] = 0;
              hapche = true;
            }
            k -= N;
            break;    
          }
        }
        if(!hapche){
          if(k == j) continue;
          board[k] = board[j];
          board[j] = 0;
        }
      }
    }
  }
  // prtboard(board);
  if(play<5) for(int dir=1; dir<=4; dir++) simulation(board, dir, play+1);
  else if(play==5){
    int tmp = score(board);
    if(max_score < tmp){
      max_score = tmp;
      // prtboard(board);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> board(500);
  cin >> N;
  for(int i=0; i<N*N; i++) cin >> board[i];
  if(N == 1) cout << board[0];
  else{
    for(int dir=1; dir<=4; dir++) simulation(board,dir,1);
    cout << max_score << "\n";
  }
}
