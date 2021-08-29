#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int s1[1000010]={}, s2, N, M;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, low,high,mid;
  for(cin>>T; T; T--){
    cin >> N;
    for(int i=0; i<N; i++) cin >> s1[i];
    sort(s1, s1+N);
    cin >> M;
    for(int i=0; i<M; i++){
      cin >> s2;
      mid = 0;
      low = 0;
      high = N-1;
      while(low<=high){
        mid = (low+high)/2;
        if(s1[mid] < s2) low = mid+1;
        else if(s1[mid] > s2) high = mid-1;
        else{
          mid = -1;
          break;
        }
      }
      if(mid == -1) cout << "1\n";
      else cout << "0\n";
    }
  }
}