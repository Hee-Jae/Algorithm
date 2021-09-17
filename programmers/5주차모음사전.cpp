#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

map<string, int> m;
int cnt = 0;
string vowel[5] = {"A", "E", "I", "O", "U"};
void dfs(string word){
  if(word.size() == 5){
    return;
  }
  for(int i=0; i<5; i++){
    cnt ++;
    m[word+vowel[i]] = cnt;
    dfs(word+vowel[i]);
  }
}

int solution(string word) {
  int answer = 0;
  dfs("");
  answer = m[word];
  return answer;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  cout << solution(s) << "\n";
}