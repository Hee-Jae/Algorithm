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

int A[103][103]={}, freq[101]={};
queue<int> q;
vector<pair<int, int> > v;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r,c,k, cnt=0, row=3, col=3, num,fr;
  int maxi, maxj, vsize;
  cin >> r >> c >> k;
  for(int i=1; i<=3; i++)
    for(int j=1; j<=3; j++) cin >> A[i][j];

  if(A[r][c] == k){
    cout << 0;
    return 0;
  }
  while(cnt<=100){
    if(row>=col){
      maxi = 0;
      maxj = 0;
      for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
          if(A[i][j] == 0) continue;
          if(freq[A[i][j]] == 0) q.push(A[i][j]);
          freq[A[i][j]]++;
        }
        // cout << "qsize : " << q.size() << "\n";
        while(!q.empty()){
          num = q.front();
          fr = freq[num];
          v.pb(mp(fr,num));
          q.pop();
          freq[num] = 0;
        }
        // cout << "vsize : " << v.size() << "\n";
        sort(v.begin(), v.end());
        for(int j=1; j<=100; j++){
          A[i][j] = 0;
        }
        vsize = v.size();
        if(vsize > 50) vsize = 50;
        for(int j=1; j<=vsize; j++){
          A[i][j*2-1] = v[j-1].nd;
          A[i][j*2] = v[j-1].st;
        }
        if(vsize*2 > maxj) maxj = vsize*2;
        // cout << "vsize : " << v.size() << "\n";
        v.clear();
        // cout << "vsize : " << v.size() << "\n";
      }
      col = maxj;
      // for(int i=1; i<=row; i++){
      //   for(int j=1; j<=col; j++){
      //     cout << A[i][j] << " ";
      //   }
      //   cout << "\n";
      // }
      // break;
    }
    else{
      maxi = 0;
      maxj = 0;
      for(int i=1; i<=col; i++){
        for(int j=1; j<=row; j++){
          if(A[j][i] == 0) continue;
          if(freq[A[j][i]] == 0) q.push(A[j][i]);
          freq[A[j][i]]++;
        }
        while(!q.empty()){
          num = q.front();
          fr = freq[num];
          v.pb(mp(fr,num));
          q.pop();
          freq[num] = 0;
        }
        sort(v.begin(), v.end());
        for(int j=1; j<=100; j++){
          A[j][i] = 0;
        }
        vsize = v.size();
        if(vsize > 50) vsize = 50;
        for(int j=1; j<=vsize; j++){
          A[j*2-1][i] = v[j-1].nd;
          A[j*2][i] = v[j-1].st;
        }
        if(vsize*2 > maxi) maxi = vsize*2;
        v.clear();
      }
      row = maxi;
    }  
    cnt++;
    if(A[r][c] == k){
      // for(int i=1; i<=row; i++){
      //   for(int j=1; j<=col; j++){
      //     cout << A[i][j] << " ";
      //   }
      //   cout << "\n";
      // }
      break;
    }
    // for(int i=1; i<=row; i++){
    //   for(int j=1; j<=col; j++){
    //     cout << A[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
  }
  if(cnt > 100) cout << -1;
  else cout << cnt;
}