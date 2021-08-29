#include <iostream>
#include <vector>
using namespace std;

vector<int> tree(262144);
int arr[100002]={};
void init(int node, int start, int end){
  if(start == end){
    tree[node] = start;
  }
  else{
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    int left = node*2, right = node*2+1;
    if(arr[tree[left]] > arr[tree[right]]) tree[node] = tree[right];
    else tree[node] = tree[left];
  }
}

void update(int node, int start, int end, int index){
  if(index < start || index > end) return;
  if(start == end) tree[node] = start;
  else{
    update(node*2, start, (start+end)/2, index);
    update(node*2+1, (start+end)/2+1, end, index);
    int left = node*2, right = node*2+1;
    if(arr[tree[left]] > arr[tree[right]]) tree[node] = tree[right];
    else tree[node] = tree[left];
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M, p, v, o;
  cin >> N;
  for(int i=1; i<=N; i++) cin >> arr[i];
  init(1,1,N);
  cin >> M;
  for(int i=0; i<M; i++){
    cin >> o;
    if(o == 1){
      cin >> p >> v;
      arr[p] = v;
      update(1,1,N,p);
    }
    else if(o==2) cout << tree[1] << "\n";
  }
}