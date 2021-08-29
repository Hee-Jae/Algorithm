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

struct Trie{
  Trie *Node[26];
  Trie *Fail;
  bool Finish;

  Trie(){
    Finish = false;
    for(int i=0; i<26; i++) Node[i]=NULL;
  }

  void Insert(char* str){
    if(*str == '\0'){
      Finish = true;
      return;
    }

    int idx = *str - 'a';
    if(Node[idx]==NULL) Node[idx] = new Trie();
    Node[idx]->Insert(str+1);
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M;
  char str[10010]={};
  queue<Trie*> q;
  // Trie* current, next, dest, root;
  Trie* root = new Trie();

  for(cin >> N; N; N--){
    cin >> str;
    root->Insert(str);
  }

  root->Fail = root;
  q.push(root);
  while(!q.empty()){
    Trie* current = q.front();
    q.pop();

    for(int i=0; i<26; i++){
      Trie* next = current->Node[i];
      if(next == NULL) continue;

      if(current == root) next->Fail = root;
      else{
        Trie* dest = current->Fail;
        while(dest != root && dest->Node[i] == NULL)
          dest = dest->Fail;
        if(dest->Node[i]!=NULL) dest = dest->Node[i];
        next->Fail = dest;
      }
      if(next->Fail->Finish) next->Finish = true;
      q.push(next);
    }
  }

  bool res;
  int idx;
  for(cin >> M; M; M--){
    cin >> str;
    Trie* current = root;
    res = false;
    for(int i=0; str[i]!='\0'; i++){
      idx = str[i] - 'a';
      while(current!=root && current->Node[idx]==NULL)
        current = current->Fail;
      if(current->Node[idx]!=NULL) current = current->Node[idx];
      if(current->Finish == true){
        res = true;
        break;
      }
    }
    if(res) cout << "YES\n";
    else cout << "NO\n";
  }

}
