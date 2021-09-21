#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

string names = "ACFJMNRT";

int getDist(char a, char b){
  int a_idx=0, b_idx=0;
  for(int i=0; i<8; i++){
    if(names[i] == a) a_idx = i;
    else if(names[i] == b) b_idx = i;
  }
  return abs(a_idx-b_idx)-1;
}

bool check(string data){
  char a = data[0];
  char b = data[2];
  char comp = data[3];
  int limit = data[4]-'0';

  int dist = getDist(a, b);
  if(comp == '='){
    if(dist == limit) return true;
    else return false;
  }
  else if(comp == '>'){
    if(dist > limit) return true;
    else return false;
  }
  else if(comp == '<'){
    if(dist < limit) return true;
    else return false;
  }
  return false;
}

int solution(int n, vector<string> data) {
  int answer = 0;
  int TF[50000]={};
  int tf_idx = 0;
  for(int i=0; i<data.size(); i++){
    tf_idx = 0;
    names = "ACFJMNRT";
    do{
      if(!check(data[i])) TF[tf_idx] = 1;
      tf_idx++;
    } while(next_permutation(names.begin(), names.end()));
  }
  for(int i=0; i<tf_idx; i++){
    if(TF[i] == 0) answer ++;
  }
  return answer;
}

int main(){
  int n = 2;
  vector<string> v = {"N~F=0", "R~T>2"};
  cout << solution(n, v) << "\n";
}