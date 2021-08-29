#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector< pair<int, long long> > v1;
  vector< pair<int, long long> > v2;
  int maximum;
  long long money;

  for(int i = 0; i < N; i++){
    cin >> maximum >> money;
    v1.pb(mp(maximum, money));
  }

  long long max_money = max(v1[0].second, v1[1].second);

  if(v1[0].second <= v1[1].first){
    v2.pb(mp(0, v1[0].second));
    v2.pb(mp(0, v1[1].second));
    v2.pb(mp(1, v1[0].second + v1[1].second));
  }
  else{
    v2.pb(mp(0, v1[0].second));
    v2.pb(mp(0, v1[1].second));
    v2.pb(mp(0, 0));
  }

  for(int i = 2; i < N; i++){
    max_money = max(max_money, v1[i].second);
    for(int j = 0; j < 3; j++){
      if(v2[j].second == 0){
        continue;
      }

      if(v2[j].second <= v1[i].first){
        v2[j].second = v2[j].second + v1[i].second;
      }
      else{
        if(v2[j].first == 0){
          v2[j].second = 0;
        }
        else{
          v2[j].first = 0;
          if(max_money != v1[i].second){
            v2[j].second = v2[j].second + v1[i].second - max_money;
          }
          else{
            v2[j].second = v2[j].second;
          }
        }
      }
    }
  }

  int check = 0;

  for(int i = 0; i < 3; i++){
    // cout <<v2[i].second << '\n';
    if(v2[i].second == 0){
      check++;
    }
  }

  if(check == 3){
    cout << "Zzz" << '\n';
  }
  else{
    cout << "Kkeo-eok" << '\n';
  }


  return 0;
}