#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(int a, int b){
  string aa,bb,left,right;
  int l,r;
  aa = to_string(a);
  bb = to_string(b);
  left = aa+bb;
  right = bb+aa;
  l = stoi(left);
  r = stoi(right);
  if(l>r) return true;
  else return false;
}

string solution(vector<int> numbers) {
  string answer ="";
  int allzero = 0;
  int nsize = numbers.size();
  for(int i=0; i<nsize; i++) allzero += numbers[i];
  if(allzero == 0) answer = "0";
  else{
    sort(numbers.begin(), numbers.end(), compare);
    for(int i=0; i<nsize; i++) answer += to_string(numbers[i]);
  }
  return answer;
}

int main(){
  vector<int> t;
  t.push_back(0);
  t.push_back(0);
  t.push_back(0);
  t.push_back(0);
  t.push_back(0);
  string s = solution(t);
  cout << s << "\n";
}