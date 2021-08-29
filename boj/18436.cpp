#include <iostream>
using namespace std;

int tree[262200][2]={}, N, M, r, l, x, q, idx;
int arr[100002]={};

void init(int node, int start, int end){
  if(start==end){
    if(arr[start]%2==0) tree[node][0] = 1;
    else tree[node][1] = 1;
  }
  else{
    int mid = (start+end)/2;
    init(node*2, start, mid);
    init(node*2+1, mid+1, end);
    tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
    tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
  }
}
void update(int node, int start, int end, int index, int value){
  if(index < start || end < index) return;
  if(start == end){
    if(value%2==0){
      tree[node][0] = 1;
      tree[node][1] = 0;
    }
    else{
      tree[node][0] = 0;
      tree[node][1] = 1;
    }
    return;
  }
  int mid = (start+end)/2;
  update(node*2, start, mid, index, value);
  update(node*2+1, mid+1, end, index, value);
  tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
  tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
}

int getsum0(int node, int start, int end, int left, int right){
  if(start > right || end < left) return 0;
  if(left <= start && end <= right) return tree[node][0];
  int mid = (start+end)/2;
  return getsum0(node*2, start, mid, left, right) + getsum0(node*2+1, mid+1, end, left, right);
}

int getsum1(int node, int start, int end, int left, int right){
  if(start > right || end < left) return 0;
  if(left <= start && end <= right) return tree[node][1];
  int mid = (start+end)/2;
  return getsum1(node*2, start, mid, left, right) + getsum1(node*2+1, mid+1, end, left, right);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=1; i<=N; i++) cin >> arr[i];
  init(1,1,N);
  cin >> M;
  for(int i=0; i<M; i++){
    cin >> q;
    if(q == 1){
      cin >> idx >> x;
      update(1,1,N,idx,x);
    }
    else if(q==2){
      cin >> l >> r;
      cout << getsum0(1,1,N,l,r) << "\n";
    }
    else if(q==3){
      cin >> l >> r;
      cout << getsum1(1,1,N,l,r) << "\n";
    }
  }
}