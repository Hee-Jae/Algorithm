#include <iostream>
#include <vector>
using namespace std;

vector<int> tree(262200);
int arr[100010]={};
void init(int node, int start, int end){
  if(start == end){
    if(arr[start] > 0) tree[node] = 1;
    else if(arr[start] == 0) tree[node] = 0;
    else tree[node] = -1;
  }
  else{
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    tree[node] = tree[node*2] * tree[node*2+1];
  }
}

int gop(int node, int start, int end, int left, int right){
  if(right < start || end < left) return 1;
  else if(left <= start && end <= right) return tree[node];
  else{
    int l = gop(node*2, start, (start+end)/2, left, right);
    int r = gop(node*2+1, (start+end)/2+1, end, left, right);
    return l * r;
  }
}
void update(int node, int start, int end, int index, int value){
  if(index < start || index > end) return;
  if(start == end){
    if(value > 0) tree[node] = 1;
    else if(value == 0) tree[node] = 0;
    else tree[node] = -1;
  }
  else{
    update(node*2, start, (start+end)/2, index, value);
    update(node*2+1, (start+end)/2+1, end, index, value);
    tree[node] = tree[node*2] * tree[node*2+1];
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M, K, l, r, p, v, res;
  char o;
  while(cin >> N >> K){
    for(int i=1; i<=N; i++) cin >> arr[i];
    init(1,1,N);
    for(int i=0; i<K; i++){
      cin >> o;
      if(o == 'C'){
        cin >> p >> v;
        arr[p] = v;
        update(1,1,N,p,v);
      }
      else if(o=='P'){
        cin >> l >> r;
        res = gop(1,1,N,l,r);
        if(res < 0) cout << "-";
        else if(res > 0) cout << "+";
        else cout << "0";
      }
    }
    cout << "\n";  
  }
}