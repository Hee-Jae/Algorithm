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
  Trie *Node[4];
  Trie *Fail;
  bool Finish;

  Trie(){
    Finish = false;
    for(int i=0; i<4; i++) Node[i]=NULL;
  }

  ~Trie(){
    for(int i=0; i<4; i++){
      if(Node[i]) delete Node[i];
    }
  }

  void Insert(char* str){
    if(*str == '\0'){
      Finish = true;
      return;
    }

    int idx;
    if(*str == 'A') idx = 0;
    else if(*str == 'C') idx = 1;
    else if(*str == 'G') idx = 2;
    else idx = 3;

    if(Node[idx]==NULL) Node[idx] = new Trie();
    Node[idx]->Insert(str+1);
  }
};

char DNA[1000010]={}, Marker[110]={}, Mutation[110]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M,T;
  
  for(cin>>T; T; T--){
    queue<Trie*> q;
    Trie* root = new Trie();
    cin >> N >> M;
    cin >> DNA >> Marker;
    
    for(int i=1; i<=M; i++){
      for(int j=0; i+j<=M; j++){
        for(int k=0; k<j; k++) Mutation[k] = Marker[k];
        for(int k=0; k<i; k++) Mutation[k+j] = Marker[j+i-k-1];
        for(int k=i+j; k<M; k++) Mutation[k] = Marker[k];
        Mutation[M] = '\0';
        root->Insert(Mutation);
        // cout << Mutation << "\n";
      }
    }
    root->Fail = root;
    q.push(root);
    while(!q.empty()){
      Trie* current = q.front();
      q.pop();

      for(int i=0; i<4; i++){
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
    int idx, cnt=0;
    Trie* current = root;
    res = false;
    for(int i=0; i<N; i++){
      if(DNA[i] == 'A') idx = 0;
      else if(DNA[i] == 'C') idx = 1;
      else if(DNA[i] == 'G') idx = 2;
      else idx = 3;
      while(current!=root && current->Node[idx]==NULL)
        current = current->Fail;
      if(current->Node[idx]!=NULL) current = current->Node[idx];
      if(current->Finish == true) cnt++;
    }
    cout << cnt << "\n";
    delete root;
  }
}
