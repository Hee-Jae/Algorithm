#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int N,M,cnt=0, maxv=-1, res=0;

struct Trie{
  bool Finish;
  Trie *Node[2];

  Trie(){
    Finish = false;
    for(int i=0; i<2; i++) Node[i] = NULL;
  }

  void Insert(char *str){
    if(*str == '\0'){
      Finish = true;
      return;
    }

    int idx = *str -'0';
    if(Node[idx] == NULL) Node[idx] = new Trie();
    Node[idx]->Insert(str+1);
  }

  int Find(char *str){
    if(*str == '\0'){
      return res;
    }
    res <<= 1;
    int idx = *str - '0';
    if(idx == 0){
      if(Node[1] == NULL){
        return Node[0]->Find(str+1);
      }
      else{
        res |= 1;
        return Node[1]->Find(str+1);
      }
    }
    else if(idx == 1){
      if(Node[0] == NULL) return Node[1]->Find(str+1);
      else{
        res |= 1;
        return Node[0]->Find(str+1);
      }
    }
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int idx, temp;
  char binary[100010][33]={}, bin;
  cin >> N;
  Trie T;

  for(int i=0; i<N; i++){
    for(int j=0; j<32; j++) binary[i][j] = '0';
  }
  for(int i=0; i<N; i++){
    idx = 31;
    cin >> M;
    while(M>0){
      bin = (M&1) + '0';
      binary[i][idx--] = bin;
      M >>= 1;
    }
    T.Insert(binary[i]);
  }
  for(int i=0; i<N; i++){
    temp = T.Find(binary[i]);
    if(temp > maxv) maxv = temp;
  }
  cout << maxv << "\n";
}
