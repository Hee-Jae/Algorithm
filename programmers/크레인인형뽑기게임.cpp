#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
  int answer = 0;
  int ssize = board.size();
  // cout << "ssize: " <<ssize << "\n";
  stack<int> s;
  vector<stack<int> > vs(ssize);
  for(int i=board.size()-1; i>=0; i--){
    for(int j=0; j<board.size(); j++){
      if(board[i][j] != 0) {
        vs[j].push(board[i][j]);
      }
    }
  }

  int item, target;
  for(int i=0; i<moves.size(); i++){
    target = moves[i]-1;
    if(!vs[target].empty()){
      item = vs[target].top();
      vs[target].pop();
      if(!s.empty() && s.top() == item){
        s.pop();
        answer += 2;
      } else{
        s.push(item);
      }
    }
  }
  return answer;
}

int main(){
  vector<vector<int> > board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
  vector<int> moves = {1,5,3,5,1,2,1,4};

  cout << solution(board, moves) << "\n";
}