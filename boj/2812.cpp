#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
char num[500020]={};
stack<char> s;
vector<char> v;
int main(){
  int N, K;
  scanf("%d %d", &N, &K);
  scanf("%s", num);
  s.push(num[0]);
  for(int i=1; i<N; i++){
    while(!s.empty() && num[i] > s.top() && K > 0){
      s.pop();
      K--;
    }
    s.push(num[i]);
  }
  while(K > 0){
    s.pop();
    K--;
  }
  while(!s.empty()){
    v.push_back(s.top());
    s.pop();
  }
  int size = v.size();
  for(int i=size-1; i>=0; i--){
    printf("%c", v[i]);
  }
}