#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

priority_queue<int> pq;
vector<pair<int,int> > v(100010);
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,start,end;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> start >> end;
    v[i] = mp(start,end);
  }
  sort(v.begin(), v.begin()+N);
  pq.push(-v[0].nd);

  for(int i=1; i<N; i++){
    if(v[i].st >= -pq.top()){
      pq.pop();
      pq.push(-v[i].nd);
    }
    else pq.push(-v[i].nd);
  }
  cout << pq.size();
}
