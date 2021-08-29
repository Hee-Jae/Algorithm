#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int num[51]={};
char op[51]={};
int numidx=0, opidx=0;
vector<pair<int, int> > cmp;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  char sik[52]={};
  int tmp=0, len, res=0, minus=-1;
  cin >> sik;
  len = strlen(sik);
  for(int i=0; i<len; i++){
    if('0' <= sik[i] && sik[i] <= '9')
      tmp = tmp*10 + (sik[i]-'0');
    else{
      num[numidx++] = tmp;
      tmp = 0;
      if(sik[i] == '-' && minus == -1) minus = opidx;
      op[opidx++] = sik[i];
    }
    if(i==len-1) num[numidx++] = tmp;
  }
  

  // for(int i=0; i<size; i++){
  //   cout << cmp[i].fst << " " << cmp[i].snd << "\n";
  // }
  
  // for(int i=0; i<numidx; i++) cout << num[i] << " ";
  // cout << "\n";
  // for(int i=0; i<opidx; i++) cout << op[i] << " ";
  // cout << "\n";
  res = num[0];
  if(minus != -1){
    for(int i=0; i<minus; i++) res += num[i+1];
    for(int i=minus; i<opidx; i++) res -= num[i+1];
  }
  else for(int i=0; i<opidx; i++) res += num[i+1];
  
  cout << res;
}