#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree(2097153);
int arr[1000002]={};

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
  if(start == end) tree[node] += value;
  else{
    update(node*2, start, (start+end)/2, index, value);
    update(node*2+1, (start+end)/2+1, end, index, value);
    tree[node] = tree[node*2] + tree[node*2+1];
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M,i,j,k,o;
  cin >> N >> M;
  for(int t=0; t<M; t++){
    cin >> o;
    if(o==2){
      cin >> i >> j;
      cout << sum(1,1,N,i,j) << "\n";
    }
    else if(o==1){
      cin >> i >> k;
      update(1,1,N,i,k);
    }
  }
}