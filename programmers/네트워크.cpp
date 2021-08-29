#include <string>
#include <vector>

using namespace std;
int root[210]={};

int find(int n){
  if(root[n] == n) return n;
  return root[n] = find(root[n]);
}

void merge(int a, int b){
  root[find(b)] = find(a);
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, size=computers.size();
    for(int i=0; i<n; i++) root[i]=i;
    for(int i=0; i<size; i++){
      for(int j=0; j<size; j++){
        if(computers[i][j]){
          if(find(i)==find(j)) continue;
          merge(i,j);
        }
      }
    }
    for(int i=0; i<n; i++){
      if(root[i]==i) answer++;
    }
    return answer;
}