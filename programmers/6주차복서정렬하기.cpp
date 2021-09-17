#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define pt pair<pair<double, int>, pair<int, int> >
using namespace std;

map<int, pair<pair<double, int>, pair<int, int> > > m;
map<int, pair<pair<double, int>, pair<int, int> > > ::iterator it;

bool cmp(const pt& a, const pt& b){
  if(a.first.first == b.first.first){
    if(a.first.second == b.first.second){
      if(a.second.first == b.second.first){
        return a.second.second < b.second.second;
      }
      return a.second.first > b.second.first;
    }
    return a.first.second > b.first.second;
  }
  return a.first.first > b.first.first;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
  vector<int> answer;
  double total, overwin, win = 0;
  double rate = 0;
  for(int i=0; i<head2head.size(); i++){
    total = 0;
    overwin = 0;
    win = 0;
    for(int j=0; j<head2head[i].size(); j++){
      if(head2head[i][j] == 'N') continue;
      if(head2head[i][j] == 'W'){
        if(weights[i] < weights[j]) overwin++;
        win++;
      }
      total++;
    }
    if(total == 0) rate = 0;
    else rate = win/total;
    m[i+1] = make_pair(make_pair(rate, overwin), make_pair(weights[i], i+1));
  }
  vector<pt> v;
  for(it=m.begin(); it!=m.end(); it++){
    v.push_back(it -> second);
  }
  sort(v.begin(), v.end(), cmp);
  for(int i=0; i<v.size(); i++){
    answer.push_back(v[i].second.second);
  }
  return answer;
}

int main(){
  vector<int> v;
  vector<string> vs;
  v.push_back(50);
  v.push_back(82);
  v.push_back(75);
  v.push_back(120);
  vs.push_back("NLWL");
  vs.push_back("WNLL");
  vs.push_back("LWNW");
  vs.push_back("WWLN");
  
  vector<int> answer = solution(v, vs);
  for(int i=0; i<answer.size(); i++){
    cout << answer[i] << " ";
  }
}