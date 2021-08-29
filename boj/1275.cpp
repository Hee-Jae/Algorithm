#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree(262144);
int arr[100002]={};

void init(int node, int start, int end){
  if(start == end) tree[node] = arr[start];
  else{
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    tree[node] = tree[node*2] + tree[node*2+1];
  }
}

long long sum(int node, int start, int end, int left, int right){
  if(start > right || end < left) return -1;
  if(left <= start && end <= right) return tree[node];
  long long l = sum(node*2, start, (start+end)/2, left ,right);
  long long r = sum(node*2+1, (start+end)/2+1, end, left, right);
  if(l == -1) return r;
  else if(r == -1) return l;
  return l+r;
}

void update(int node, int start, int end, int index, int value){
  if(index < start || index > end) return;
  if(start == end) tree[node] = value;
  else{
    update(node*2, start, (start+end)/2, index, value);
    update(node*2+1, (start+end)/2+1, end, index, value);
    tree[node] = tree[node*2] + tree[node*2+1];
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,Q,x,y,a,b;
  cin >> N >> Q;
  for(int i=1; i<=N; i++) cin >> arr[i];
  init(1,1,N);
  for(int t=0; t<Q; t++){
    cin >> x >> y >> a >> b;
    if(x>=y) cout << sum(1,1,N,y,x) << "\n";
    else cout << sum(1,1,N,x,y) << "\n";
    update(1,1,N,a,b);
  }
}