#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int tree[8388608]={}, minsu[4000010]={};
bool bucket[4000010]={};
int N,M,K;

void init(int node, int start, int end){
  if(start==end) tree[node] = start;
  else{
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    int left = node*2, right = node*2+1;
    if(minsu[tree[left]] < minsu[tree[right]]) tree[node] = tree[right];
    else tree[node] = tree[left];
  }
}

void update(int node, int start, int end, int idx){
  if(idx < start || idx > end) return;
  if(start == end) tree[node] = start;
  else{
    update(node*2, start, (start+end)/2, idx);
    update(node*2+1, (start+end)/2+1, end, idx);
    int left = node*2, right = node*2+1;
    if(minsu[tree[left]] < minsu[tree[right]]) tree[node] = tree[right];
    else tree[node] = tree[left];
  }
}

int putCard(int node, int start, int end, int value){
  if(start==end) return start;
  if(minsu[tree[node*2]] > value){
    // cout << "left\n";
    return putCard(node*2, start, (start+end)/2, value);
  } 
  else{
    // cout << "right\n";
    return putCard(node*2+1, (start+end)/2+1, end, value);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;
  int num;
  for(int i=1; i<=M; i++){
    cin >> num;
    bucket[num] = true;
  }
  int idx = 1;
  for(int i=1; i<=N; i++)
    if(bucket[i]) minsu[idx++] = i;
  idx--;
  init(1,1,idx);

  int index;
  for(int i=0; i<K; i++){
    cin >> num;
    index = putCard(1, 1, idx, num);
    cout << minsu[index] << "\n";
    minsu[index] = 0;
    update(1, 1, idx, index);
  }
}
