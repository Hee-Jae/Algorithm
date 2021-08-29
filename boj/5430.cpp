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
  char p[100002]={}, nums[500000]={};
  int arr[100002]={};
  int T,n,tmp=0, idx=0, start,end, error;
  bool flip=true;
  for(cin>>T; T; T--){
    cin >> p >> n >> nums;
    idx = 0;
    start = 0;
    end = n-1;
    tmp = 0;
    error = 0;
    for(int i=1; nums[i]!='\0'; i++){
      if('0' <= nums[i] && nums[i] <= '9') tmp = tmp*10 + (nums[i]-'0');
      if(nums[i]==']' || nums[i] == ','){
        arr[idx++] = tmp;
        tmp = 0;
      }
    }
    // cout << "test\n";
    // for(int i=0; i<n; i++) cout << arr[i] << " ";
    // cout << "\n";
    flip = true;
    for(int i=0; p[i]!='\0'; i++){
      if(p[i]=='R') flip=!flip;
      else if(p[i]=='D'){
        if(flip) start++;
        else end--;
        if(start-1>end){
          error = 1;
          break;
        }
      }
    }
    // cout << "start : " << start << " | end : " << end << "\n";
    if(error) cout << "error\n";
    else{
      if(flip){
        cout << "[";
        for(int i=start; i<=end; i++){
          if(i==end) cout << arr[i];
          else cout << arr[i] << ",";
        }
        cout << "]\n";
      }
      else{
        cout << "[";
        for(int i=end; i>=start; i--){
          if(i==start) cout << arr[i];
          else cout << arr[i] << ",";
        }
        cout << "]\n";
      } // reverse 
    } // if no error
  } // for T
}
