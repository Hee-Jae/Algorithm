#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int A[6][6]={}, B[6][6]={}, sum[6]={}, value;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++) cin >> A[i][j];
  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++) cin >> B[i][j];

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      value = 0;
      for(int k=0; k<5; k++){
        value += (A[i][k] * B[k][j]);
      }
      sum[i] += value;
    }
  }
  int minv = sum[0], mini = 0;
  for(int i=1; i<5; i++){
    if(sum[i] <= minv){
      minv = sum[i];
      mini = i;
    }
  }
  if(mini==0) cout << "Inseo";
  else if(mini==1) cout << "Junsuk";
  else if(mini==2) cout << "Jungwoo";
  else if(mini==3) cout << "Jinwoo";
  else if(mini==4) cout << "Youngki";
}
