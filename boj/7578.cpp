#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int N, A[1000002]={}, B[500002]={};
int tree[1050000]={};
void update(int node, int start, int end, int index){
  if(start == end && start == index) tree[node] = 1;
  else if(index < start || index > end) return;
  else{
    int mid=(start+end)/2;
    update(node*2, start, mid, index);
    update(node*2+1, mid+1, end, index);
    tree[node] = tree[node*2] + tree[node*2+1];
  }
}

lli inversion(int node, int start, int end, int left, int right){
  if(left<=start && end<=right) return tree[node];
  else if(right<start || left>end) return 0;
  else{
    int mid = (start+end)/2;
    return inversion(node*2,start,mid,left,right)+inversion(node*2+1,mid+1,end,left,right);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int machine;
  lli cnt=0;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> machine;
    A[machine]=i;
  }
  for(int i=0; i<N; i++){
    cin >> machine;
    B[i] = A[machine];
  }
  for(int i=0; i<N; i++){
    update(1,1,N,B[i]);
    cnt += inversion(1,1,N,B[i]+1,N);
  }
  cout << cnt;
}
