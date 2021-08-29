#include <stdio.h>
#include <vector>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

struct Trie{
  Trie *children[26];
  bool flag;
  int count;
  Trie(){
    flag = false;
    count = 0;
    for(int i=0; i<26; i++)
      children[i] = NULL;
  }

  ~Trie(){
    for(int i=0; i<26; i++)
      if(children[i]) delete children[i];
  }

  void insert(const char *str){
    if (*str == '\0'){
      flag = true;
      return;
    }

    int index = *str - 'a';
    if(children[index] == NULL){
      count ++;
      children[index] = new Trie;
    }
    children[index]->insert(str+1);
  }

  int search(const char *str, int cnt, int first){
    if(*str == '\0'){
      return cnt;
    }

    int index = *str - 'a';

    if(first == 1 || count > 1 || (count == 1 && flag))
      return children[index]->search(str+1, cnt+1, first+1);
    else
      return children[index]->search(str+1, cnt, first+1);
  }
};

char v[100010][82];
int n;
double temp;
int main(){
  while(scanf("%d", &n) != EOF){
    Trie root;
    temp = 0;
    for(int i=0; i<n; i++){
      scanf("%s", &v[i]);
      root.insert(v[i]);
    }

    for(int i=0; i<n; i++){
      temp += root.search(v[i], 0, 1);
    }
    printf("%.2lf\n", (double)temp/n);
    // delete root;
  }
}
