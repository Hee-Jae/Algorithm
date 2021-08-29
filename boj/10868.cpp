#include <iostream>
#include <vector>
using namespace std;

vector<int> tree(262144);
int arr[100002]={};
void init(int node, int start, int end){
  if(start == end){
    tree[node] = start;
    // cout << arr[start] << "\n";
  }
  else{
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    int left = node*2, right = node*2+1;
    if(arr[tree[left]] > arr[tree[right]]) tree[node] = tree[right];
    else tree[node] = tree[left];
  }
}

int min(int node, int start, int end, int left, int right){
  if(right < start || end < left) return -1;
  else if(left <= start && end <= right) return tree[node];
  else{
    int l = min(node*2, start, (start+end)/2, left, right);
    int r = min(node*2+1, (start+end)/2+1, end, left, right);
    if(l == -1) return r;
    else if(r == -1) return l;
    
    if(arr[l] < arr[r]) return l;
    else return r;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M, l, r;
  cin >> N >> M;
  for(int i=1; i<=N; i++) cin >> arr[i];
  init(1,1,N);
  // for(int idx=1; idx<=25; idx++){
  //   cout << idx << " : "<< tree[idx] << "\n";
  // }
  for(int i=0; i<M; i++){
    cin >> l >> r;
    cout << arr[min(1,1,N,l,r)] << "\n";
  }
}