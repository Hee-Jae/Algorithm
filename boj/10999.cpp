#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree(2097152);
vector<long long> lazy(2097152);
int arr[1000002]={};

void propagate(int node, int start, int end){
  if(lazy[node]){ // 레이지를 딱 봤는데 값이 있다?
    if(start != end){
      lazy[node*2] += lazy[node]; // 좌짝자식한테 뿌려!
      lazy[node*2+1] += lazy[node]; // 우짝좌식한테 뿌려!
    }
    tree[node] += (end-start+1)*lazy[node]; // 본인한테는 더해진 만큼 추가!
    lazy[node] = 0; // 더했으면 레이지 다시 바꿔놔~
  }
}
void init(int node, int start, int end){
  if(start == end){
    tree[node] = arr[start];
  }
  else{
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    int left = node*2, right = node*2+1;
    tree[node] = tree[right] + tree[left];
  }
}

long long sum(int node, int start, int end, int left, int right){
  propagate(node, start, end); // 어.. 더하려고 보니까 아직 밀린게 있어? 더해! 더하고나서 시작해
  if(right < start || end < left) return -1;
  else if(left <= start && end <= right){
    return tree[node];
  }
  else{
    long long l = sum(node*2, start, (start+end)/2, left, right);
    long long r = sum(node*2+1, (start+end)/2+1, end, left, right);
    if(l == -1) return r;
    else if(r == -1) return l;
    return l + r;
  }
}
void update(int node, int start, int end, int left, int right, int value){
  propagate(node, start, end); // 방문 했으면 밀린거 더해!
  if(right < start || end < left) return; // 범위 밖이면 끝내!
  if(left <= start && end <= right){
    lazy[node] += value;
    propagate(node, start, end);
    return; // 범위 안에 딱 들어온다? 레이지에 추가하고 더해! 그리고 함수끝내. 더이상 들어가지마.
  }
  update(node*2, start, (start+end)/2, left,right, value); // 좌짝 재귀 ㄱㄱ
  update(node*2+1, (start+end)/2+1, end, left,right, value); // 우짝 재귀 ㄱㄱ
  tree[node] = tree[node*2] + tree[node*2+1]; // 그 외의 경우엔 좌짝놈 + 우짝놈
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M, K, l, r, o;
  long long d;
  cin >> N >> M >> K;
  for(int i=1; i<=N; i++) cin >> arr[i];
  init(1,1,N);
  for(int i=0; i<M+K; i++){
    cin >> o;
    if(o == 1){
      cin >> l >> r >> d;
      update(1,1,N,l,r,d);
    }
    else if(o==2){
      cin >> l >> r;
      cout << sum(1,1,N,l,r) << "\n";
    }
  }
}