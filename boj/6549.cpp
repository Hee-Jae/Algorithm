#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
lli tree[262200]={}, histogram[100002]={};
int N;

void init(int node, int start, int end){
  if(start == end) tree[node] = start;
  else{
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    int left = node*2, right = node*2+1;
    if(histogram[tree[left]] > histogram[tree[right]]) tree[node] = tree[right];
    else tree[node] = tree[left];
  }
}
int min(int node, int start, int end, int left, int right){
  if(right < start || end < left) return -1;
  else if(left <= start && end <= right) return tree[node];
  else{
    int l = min(node*2, start, (start+end)/2, left, right);
    int r = min(node*2+1, (start+end)/2+1, end, left, right);
    if(l == -1) return r;
    else if(r == -1) return l;
    
    if(histogram[l] < histogram[r]) return l;
    else return r;
  }
}

lli width(int left, int right){
  int minindex = min(1,1,N,left,right);
  lli maxwidth = histogram[minindex]*(right-left+1);

  if(left <= minindex-1){
    lli tmp = width(left, minindex-1);
    if(tmp > maxwidth) maxwidth = tmp;
  }
  if(right >= minindex+1){
    lli tmp = width(minindex+1, right);
    if(tmp > maxwidth) maxwidth = tmp;
  }
  return maxwidth;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    cin >> N;
    if(N==0) break;
    for(int i=1; i<=N; i++) cin >> histogram[i];
    init(1,1,N);
    lli maxwidth = width(1,N);
    cout << maxwidth << "\n";
  } 
}