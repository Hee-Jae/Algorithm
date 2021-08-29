#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
#define FULL 0x0000000003ffffff
using namespace std;

vector<lli> word;
lli getbit(int n){
  lli bit = 1;
  while(n){
    bit <<= 1;
    n--;
  }
  return bit;
}

lli stob(string s){
  int size = s.length();
  int bit;
  lli res=0;
  for(int i=0; i<size; i++){
    bit = s[i]-'a';
    res |= getbit(bit);
  }
  return res;
}
lli status = FULL;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M,o;
  string str,x;
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> str;
    word.pb(stob(str));
  }

  int bit, cnt;
  lli check;
  for(int i=0; i<M; i++){
    cnt = 0;
    cin >> o >> x;
    bit = getbit(x[0]-'a');
    if(o==1) status &= ~bit;
    else if(o==2) status |= bit;
    for(int j=0; j<N; j++){
      check = word[j]&status;
      if(check == word[j]) cnt++;
    }
    cout << cnt << "\n";
  }
}
