#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  lli n, fibonachibismurihansooyeol[120]={1,1,1,1};
  cin >> n;
  for(int i=4; i<=n; i++)
    fibonachibismurihansooyeol[i] = fibonachibismurihansooyeol[i-1]+fibonachibismurihansooyeol[i-3];
  
  cout << fibonachibismurihansooyeol[n];
}
