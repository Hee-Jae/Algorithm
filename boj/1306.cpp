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

priority_queue<pair<int, int> > pq;
int N,M,light,idx;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i=1; i<=N; i++){
    cin >> light;
    while(!pq.empty() && pq.top().nd<=i-(M*2)+1) pq.pop();
    pq.push(mp(light,i));
    if(i<2*M-1) continue;
    cout << pq.top().st << " ";
  }
}
