#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
lli N,contest[100010][2]={}, tmpsum;
lli cur=0, noshow=0, maxc=0, maxi, chance=0, firstnoshow;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++) cin >> contest[i][0] >> contest[i][1];
  
  for(int i=0; i<N; i++){ 
    if(cur <= contest[i][0]){
      cur += contest[i][1];
      if(maxc < contest[i][1]){
        maxc = contest[i][1];
        maxi = i;
        tmpsum = cur;
      }
    }
    else{
      // cout << "noshow : " << i << "\n";
      if(noshow==0){
        firstnoshow = i;
      }
      noshow++;
      if(noshow >= 2){
        if(chance==1 || firstnoshow < maxi){
          cout << "Zzz\n";
          return 0; 
        }
        cur = tmpsum;
        cur -= maxc;
        noshow--;
        i=maxi;
        chance = 1;
      } // if noshow == 2
    } // else 
    // cout << "cur : " << cur << "\n";
  } // for N
  cout << "Kkeo-eok\n";
}
