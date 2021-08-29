#include <stdio.h>
#include <queue>
using namespace std;
int main(){
  queue<int> q;
  int N,K, c, pas[101]={}, flag=0, count=0;
  scanf("%d %d", &N, &K);
  for(int i=0; i<N; i++){
    scanf("%d", &c);
    q.push(c);
  }
  for(int i=0; i<N; i++){
    flag = 0;
    for(int j=0; j<K; j++){
      if(q.front() > pas[j]){
        pas[j] = q.front();
        q.pop();
        flag = 1;
        break;
      }
    }
    if(flag == 0) break; 
  }
  if(flag) printf("YES");
  else printf("NO");
}