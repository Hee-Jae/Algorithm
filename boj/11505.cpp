#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree(2097152);
int arr[1000002]={};
void init(int node, int start, int end){
  if(start == end){
    tree[node] = arr[start];
  }
  else{
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    int left = node*2, right = node*2+1;
    tree[node] = (tree[right] * tree[left])%1000000007;
  }
}

long long query(int node, int start, int end, int left, int right){
  if(right < start || end < left) return -1;
  else if(left <= start && end <= right) return tree[node];
  else{
    long long l = query(node*2, start, (start+end)/2, left, right);
    long long r = query(node*2+1, (start+end)/2+1, end, left, right);
    if(l == -1) return r;
    else if(r == -1) return l;
    return (l * r)%1000000007;
  }
}
void update(int node, int start, int end, int index, int value){
  if(index < start || index > end) return;
  if(start == end) tree[node] = value;
  else{
    update(node*2, start, (start+end)/2, index, value);
    update(node*2+1, (start+end)/2+1, end, index, value);
    int left = node*2, right = node*2+1;
    tree[node] = (tree[right] * tree[left])%1000000007;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M, K, l, r, o, p,v;
  cin >> N >> M >> K;
  for(int i=1; i<=N; i++) cin >> arr[i];
  init(1,1,N);
  for(int i=0; i<M+K; i++){
    cin >> o;
    if(o == 1){
      cin >> p >> v;
      arr[p] = v;
      update(1,1,N,p,v);
    }
    else if(o==2){
      cin >> l >> r;
      cout << query(1,1,N,l,r) << "\n";
    }
  }
}