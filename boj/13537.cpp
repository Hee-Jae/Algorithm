#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;

int arr[100002]={}, cnt=0;
vector<int> tree[262200];

void init(int node, int start, int end){
  if(start == end) tree[node].pb(arr[start]);
  else{
    for(int i=start; i<=end; i++){
      tree[node].pb(arr[i]);
    }
    int mid = (start+end)/2;
    init(node*2, start, mid);
    init(node*2+1, mid+1, end);
  }
}

int bs(int node, int low, int high, int value){  
  int mid;
  while(high-low > 0){
    mid = (low+high)/2;
    if(tree[node][mid] <= value) low = mid+1;
    else high = mid;
  }
  return high;
}

void getcnt(int node, int start, int end, int left, int right, int value){
  if(start > right || end < left) return;
  if(left <= start && end <= right){
    int size = tree[node].size();
    int upbnd = bs(node,0,size,value);
    // cout << "upbnd : " << upbnd << "\n";
    cnt += (size-upbnd);
    return;
  }
  int mid = (start+end)/2;
  getcnt(node*2, start, mid, left, right, value);
  getcnt(node*2+1, mid+1, end, left, right, value);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, a,b,k;
  cin >> N;
  for(int i=1; i<=N; i++) cin >> arr[i];
  init(1,1,N);
  for(int i=0; i<262200; i++) sort(tree[i].begin(), tree[i].end());
  cin >> M;
  for(int i=0; i<M; i++){
    cnt = 0;
    cin >> a >> b >> k;
    getcnt(1,1,N,a,b,k);
    cout << cnt << "\n";
  }
}