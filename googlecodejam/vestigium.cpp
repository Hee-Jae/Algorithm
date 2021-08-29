#include <iostream>
using namespace std;

int main(){
  int T, N;
  cin >> T;
  for(int test=1; test<=T; test++){
    int array[101][101]={};
    int row[101][101]={}, col[101][101]={};
    cin >> N;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        cin >> array[i][j];
      }
    }
    int k=0,r=0,c=0;
    for(int i=0; i<N; i++) k += array[i][i];
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        row[i][array[i][j]] ++;
        col[i][array[j][i]] ++;
      }
    }
    for(int i=0; i<N; i++){
      for(int j=0; j<=N; j++){
        if(row[i][j] >= 2){
          r++;
          break;
        }
      }
    }
    for(int i=0; i<N; i++){
      for(int j=0; j<=N; j++){
        if(col[i][j] >= 2){
          c++;
          break;
        }
      }
    }
    cout << "Case #" << test << ": " << k << " " << r << " " << c << "\n"; 
  }
}