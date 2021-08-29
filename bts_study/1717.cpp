#include <iostream>
#include <vector>
using namespace std;

struct Unf{
  vector<int> v;

  Unf(int n):v(n+1){
    for(int i=0; i<=n; i++){
      v[i] = i;
    }
  }

  int find(int n){
    if(v[n] == n) return n;
    return v[n] = find(v[n]);
  } // linear 한 트리가 만들어질 수 있기 때문에 find 를 할 때마다 최신화 해주는거지.

  void merge(int a, int b){
    v[find(a)] = find(b); // a와 b를 합칠 때는 a의 대장을 b의 대장 밑으로 보내 버린다.
  } // 살짝 굴욕적인 합병이다~~ 라고 생각하는거야. ㅇㅋ?
};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m, o,a,b;
  cin >> n >> m;
  Unf tree(n);
  for(int i=0; i<m; i++){
    cin >> o >> a >> b;
    if(o == 0){
      tree.merge(a, b);
    }
    else if(o == 1){
      if(tree.find(a) == tree.find(b)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
}