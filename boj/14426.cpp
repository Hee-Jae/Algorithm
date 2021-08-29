#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int N,M,cnt=0;

struct Trie{
  bool Finish;
  Trie *Node[26];

  Trie(){
    Finish = false;
    for(int i=0; i<26; i++) Node[i] = NULL;
  }

  void Insert(char *str){
    if(*str == '\0'){
      Finish = true;
      return;
    }

    int idx = *str -'a';
    if(Node[idx] == NULL) Node[idx] = new Trie();
    Node[idx]->Insert(str+1);
  }

  bool Find(char *str){
    if(*str == '\0'){
      return true;
      // if(Finish = true) return true;
      // return false;
    }
    int idx = *str - 'a';
    if(Node[idx] == NULL) return false;
    return Node[idx]->Find(str+1);
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  char str[550]={};
  cin >> N >> M;
  Trie T;
  bool flag;
  for(int i=0; i<N; i++){
    cin >> str;
    T.Insert(str);
  }
  for(int i=0; i<M; i++){
    cin >> str;
    flag = T.Find(str);
    if(flag) cnt ++;
  }
  cout << cnt;
}
