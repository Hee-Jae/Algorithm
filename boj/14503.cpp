#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int N, M, r, c, d, area=0;
int room[55][55]={};

void clean(int r, int c){
  room[r][c] = 2;
  area++;
  // cout << "(" << r << "," << c << ")\n";
}

int search(int dir){
  if(dir == 0){
    if(c-1 >= 0 && room[r][c-1]==0) return 3;
    else if(r+1 < N && room[r+1][c]==0) return 2;
    else if(c+1 < M && room[r][c+1]==0) return 1;
    else if(r-1 >= 0 && room[r-1][c]==0) return 0;
    return 4;
  }
  else if(dir == 1){
    if(r-1 >= 0 && room[r-1][c]==0) return 0;
    else if(c-1 >= 0 && room[r][c-1]==0) return 3;
    else if(r+1 < N && room[r+1][c]==0) return 2;
    else if(c+1 < M && room[r][c+1]==0) return 1;
    return 5;
  }
  else if(dir == 2){
    if(c+1 < M && room[r][c+1]==0) return 1;
    else if(r-1 >= 0 && room[r-1][c]==0) return 0;
    else if(c-1 >= 0 && room[r][c-1]==0) return 3;
    else if(r+1 < N && room[r+1][c]==0) return 2;
    return 6;
  }
  else if(dir == 3){
    if(r+1 < N && room[r+1][c]==0) return 2;
    else if(c+1 < M && room[r][c+1]==0) return 1;
    else if(r-1 >= 0 && room[r-1][c]==0) return 0;
    else if(c-1 >= 0 && room[r][c-1]==0) return 3;
    return 7;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  cin >> r >> c >> d;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++) cin >> room[i][j];

  clean(r,c);
  int nextdir=d;
  while(1){
    nextdir = search(nextdir);
    if(nextdir==0) r--;
    else if(nextdir==1) c++;
    else if(nextdir==2) r++;
    else if(nextdir==3) c--;
    else{
      if(nextdir-4 == 0 && r+1 < N && room[r+1][c] != 1) r++;
      else if(nextdir-4 == 1 && c-1 >= 0 && room[r][c-1] != 1) c--;
      else if(nextdir-4 == 2 && r-1 >= 0 && room[r-1][c] != 1) r--;
      else if(nextdir-4 == 3 && c+1 < M && room[r][c+1] != 1) c++;
      else break;
    }
    if(0 <= nextdir && nextdir <= 3) clean(r,c);
    if(nextdir > 3) nextdir -= 4;
  }
  cout << area << "\n";
}
