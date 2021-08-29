#include <iostream>
#include <vector>
using namespace std;

struct Test{
  vector<int> v;
  int X,Y;
  // Test(int n):v(10){
  //   for(int i=0; i<n; i++) v[i]=i;
  // }
  Test(int x, int y):X(x), Y(y){
    ;
  }
};
int main(){
  // int n;
  // cin >> n; 
  // Test a(n);
  // for(int i=0; i<n; i++) cout << a.v[i] << " ";
  int x, y;
  cin >> x >> y;
  Test a(x,y);
  cout << a.X << " " << a.Y << "\n";
}