#include <iostream>
#define MAX 1000000
using namespace std;

int tree[2098000]={};
int candy[1000001]={};
int update(int node, int value, int idx, int start, int end){
  if(idx < start || end < idx) return tree[node];
  if(start==end){
    tree[node] = value;
    // cout << start << " ";
    return tree[node];
  }
  int mid = (start+end)/2;
  tree[node] = update(node*2, value, idx, start, mid) + update(node*2+1, value, idx, mid+1, end);
  return tree[node];
}

int getcandy(int node, int value, int start, int end){
  // cout << start << " " << end << "\n";
  if(start==end) return start;
  int mid = (start+end)/2;
  if(tree[node*2] >= value) return getcandy(node*2, value, start, mid);
  else return getcandy(node*2+1, value-tree[node*2], mid+1, end);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, A,B,C, k;
  for(cin >> n; n; n--){
    // for(int i=1; i<=3; i++) cout << candy[i] << " ";
    // cout << "\n";
    cin >> A;
    if(A == 1){
      cin >> B;
      k = getcandy(1,B,1,MAX);
      cout << k << "\n";
      candy[k]--;
      update(1, candy[k], k, 1, MAX);
    }
    else{
      cin >> B >> C;
      candy[B] += C;
      update(1, candy[B], B, 1, MAX);
    }
  } 
}