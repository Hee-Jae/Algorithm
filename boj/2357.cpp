#include <iostream>
#include <vector>
using namespace std;

vector<int> mintree(262144);
vector<int> maxtree(262144);
int arr[100002]={};
void mininit(int node, int start, int end){
  if(start == end){
    mintree[node] = start;
    // cout << arr[start] << "\n";
  }
  else{
    mininit(node*2, start, (start+end)/2);
    mininit(node*2+1, (start+end)/2+1, end);
    int left = node*2, right = node*2+1;
    if(arr[mintree[left]] > arr[mintree[right]]) mintree[node] = mintree[right];
    else mintree[node] = mintree[left];
  }
}

int min(int node, int start, int end, int left, int right){
  if(right < start || end < left) return -1;
  else if(left <= start && end <= right) return mintree[node];
  else{
    int l = min(node*2, start, (start+end)/2, left, right);
    int r = min(node*2+1, (start+end)/2+1, end, left, right);
    if(l == -1) return r;
    else if(r == -1) return l;
    
    if(arr[l] < arr[r]) return l;
    else return r;
  }
}

void maxinit(int node, int start, int end){
  if(start == end){
    maxtree[node] = start;
  }
  else{
    maxinit(node*2, start, (start+end)/2);
    maxinit(node*2+1, (start+end)/2+1, end);
    int left = node*2, right = node*2+1;
    if(arr[maxtree[left]] < arr[maxtree[right]]) maxtree[node] = maxtree[right];
    else maxtree[node] = maxtree[left];
  }
}

int max(int node, int start, int end, int left, int right){
  if(right < start || end < left) return -1;
  else if(left <= start && end <= right) return maxtree[node];
  else{
    int l = max(node*2, start, (start+end)/2, left, right);
    int r = max(node*2+1, (start+end)/2+1, end, left, right);
    if(l == -1) return r;
    else if(r == -1) return l;
    
    if(arr[l] > arr[r]) return l;
    else return r;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M, l, r;
  cin >> N >> M;
  for(int i=1; i<=N; i++) cin >> arr[i];
  mininit(1,1,N);
  maxinit(1,1,N);
  for(int i=0; i<M; i++){
    cin >> l >> r;
    cout << arr[min(1,1,N,l,r)] << " " << arr[max(1,1,N,l,r)]<< "\n";
  }
}