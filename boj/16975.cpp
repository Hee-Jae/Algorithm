#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree(262144);
vector<long long> lazy(262144);
int arr[100002]={};

void propagate(int node, int start, int end){
  if(lazy[node]){ 
    if(start != end){
      lazy[node*2] += lazy[node]; 
      lazy[node*2+1] += lazy[node]; 
    }
    tree[node] += (end-start+1)*lazy[node];
    lazy[node] = 0;
  }
}
void init(int node, int start, int end){
  if(start == end){
    tree[node] = arr[start];
    return;
  }
  init(node*2, start, (start+end)/2);
  init(node*2+1, (start+end)/2+1, end);
}

long long prt(int node, int start, int end, int left, int right){
  propagate(node, start, end);
  if(right < start || end < left) return -1;
  else if(left <= start && end <= right) return tree[node];
  long long l = prt(node*2, start, (start+end)/2, left, right);
  long long r = prt(node*2+1, (start+end)/2+1, end, left, right);
  if(l == -1) return r;
  if(r == -1) return l;
}
void update(int node, int start, int end, int left, int right, int value){
  propagate(node, start, end);
  if(right < start || end < left) return;
  if(left <= start && end <= right){
    lazy[node] += value;
    propagate(node, start, end);
    return;
  }
  update(node*2, start, (start+end)/2, left,right, value);
  update(node*2+1, (start+end)/2+1, end, left,right, value);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M, l, r, o, x;
  long long d;
  cin >> N;
  for(int i=1; i<=N; i++) cin >> arr[i];
  init(1,1,N);
  cin >> M;
  for(int i=0; i<M; i++){
    cin >> o;
    if(o == 1){
      cin >> l >> r >> d;
      update(1,1,N,l,r,d);
    }
    else if(o==2){
      cin >> x;
      cout << prt(1,1,N,x,x) << "\n";
    }
  }
}