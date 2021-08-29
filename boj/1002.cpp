#include <iostream>
#include <cmath>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  float x1,x2,y1,y2,r1,r2;
  float d;
  for(cin >> T; T; T--){
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    if(d==0 && r1==r2) cout << "-1"; // 일치
    else if(d==0 && r1!=r2) cout << "0"; // 원점일치, 포함
    else if(r1 + d == r2) cout << "1"; // 내접
    else if(r2 + d == r1) cout << "1"; // 내접
    else if(r1+r2 == d) cout << "1"; // 외접
    else if(r1 > d+r2 || r2 > d+r1) cout << "0"; // 포함
    else if(r1+r2 > d) cout << "2"; // 두개의 접점
    else if(r1+r2 < d) cout << "0"; // 안 만남
    cout << "\n";
  }
}