#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
  int answer = 0;
  bool noPrime[3005]={true, true};
  for(int i=2; i<=60; i++){
    if(noPrime[i]) continue;
    for(int j=i+i; j<=3000; j+=i)
      noPrime[j] = true;
  }
  
  vector<int> comb(nums.size());
  
  int cmbsize = comb.size();
  for(int i=cmbsize-1; i>=cmbsize-3; i--) comb[i] = 1;
  int temp = 0;
  do{
    temp = 0;
    for(int i=0; i<nums.size(); i++){
      temp += nums[i]*comb[i];
    }
    if(!noPrime[temp]) answer ++;
  }while(next_permutation(comb.begin(), comb.end()));

  return answer;
}

int main(){
  // vector<int> v = {1,2,3,4};
  // vector<int> v = {1,2,7,6,4};
  vector<int> v = {1,6,4};
  cout << solution(v) << "\n";
}