#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

string makeU(string p){
  int left=0, right=0, i=0, size=p.size();
  while((left==0 && right==0) || left!=right){
    if(p[i]=='(') left++;
    else if(p[i]==')') right++;
    i++;
    if(i==size) break;
  }
  return p.substr(0,i);
}

bool correct(string p){
  stack<char> s;
  int size = p.size();
  for(int i=0; i<size; i++){
    if(p[i]=='(') s.push(p[i]);
    else{
      if(s.empty()) return false;
      s.pop();
    }
  }
  if(s.size() > 0) return false;
  return true;
}

string reverse(string p){
  string res = "";
  int size = p.size();
  for(int i=0; i<size; i++){
    if(p[i]=='(') res += ')';
    else res += '(';
  }
  return res;
}
string solution(string p) {
  if(p.size()==0) return p;
  string u,v;
  string answer = "";
  u = makeU(p);
  v = p.substr(u.size(), p.size()-u.size());
  if(correct(u)){
    answer += u;
    v = solution(v);
    answer += v;
  }
  else{
    answer += '(';
    answer += solution(v);
    answer += ')';
    u = u.substr(1,u.size()-2);
    answer += reverse(u);
  }
  return answer;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, ans;
  cin >> s;
  ans = solution(s);
  cout << ans << "\n";
}
