#include <iostream>
using namespace std;

int paper[10][10]={};
int cnt=0, flag=1;
void check(int n){
  int temp=0, use=5;
  for(int i=0; i<=10-n; i++){
    for(int j=0; j<=10-n; j++){
      temp = 0;
      for(int k=i; k<n+i; k++){
        for(int l=j; l<n+j; l++){
          if(paper[k][l] == 1) temp++; 
        }
      }
      if(temp == n*n){
        cnt ++;
        use --;
        if(use < 0 ) return;
        for(int k=i; k<n+i; k++){
          for(int l=j; l<n+j; l++){
            paper[k][l] = 0; 
          }
        }
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++) cin >> paper[i][j];
  }
  for(int i=5; i>=1; i--) check(i);
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++) if(paper[i][j] == 1) flag = 0;
  }
  if(!flag) cout << "-1";
  else cout << cnt;
}