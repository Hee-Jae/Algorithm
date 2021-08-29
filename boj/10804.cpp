#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int arr[21]={};
  for(int i=1; i<=20; i++) arr[i] = i;

  int a,b, ta, tb, temp;
  for(int i=0; i<10; i++){
    cin >> a >> b;
    ta = a;
    tb = b;
    while(1){
      temp = arr[ta];
      arr[ta] = arr[tb];
      arr[tb] = temp;
      ta ++;
      tb --;
      if(ta >= tb) break;
    }
  }
  for(int i=1; i<=20; i++) cout << arr[i] << " ";
}