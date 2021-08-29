#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
int table[1000010]={};
stack<int> stk;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    k++;
    int back, tail = n, move;
    // for(int i=0; i<n; i++) table[i]=0;

    int cmdsize = cmd.size();
    for(int i=0; i<cmdsize; i++){
      // cout << "K : " << k << "\n";
      // cout << cmd[i] << "\n";
      if(cmd[i][0] == 'C'){
        table[k] = 1;
        stk.push(k);
        if(k == tail){
          while(table[k] == 1) k--;
          tail = k;
        }
        else
          while(table[k] == 1) k++;
      }
      if(cmd[i][0] == 'Z'){
        back = stk.top();
        stk.pop();
        table[back] = 0;
        if(back > tail) tail = back;
      }
      if(cmd[i][0] == 'D'){
        move = (cmd[i][2] - '0');
        while(move){
          k++;
          if(table[k] == 0) move--;
        }
      }
      if(cmd[i][0] == 'U'){
        move = (cmd[i][2] - '0');
        while(move){
          k--;
          if(table[k] == 0) move--;
        }
      }
    }
    for(int i=1; i<=n; i++){
      if(table[i]==0) answer += 'O';
      else answer += 'X';
      // cout << table[i] << " ";
    }
    return answer;
}

int main(){
  vector<string> cmd;
  int n = 8;
  int k = 2;
  // cmd.push_back("D 2");
  // cmd.push_back("C");
  // cmd.push_back("U 3");
  // cmd.push_back("C");
  // cmd.push_back("D 4");
  // cmd.push_back("C");
  // cmd.push_back("U 2");
  // cmd.push_back("Z");
  // cmd.push_back("Z");
  cmd.push_back("D 2");
  cmd.push_back("C");
  cmd.push_back("U 3");
  cmd.push_back("C");
  cmd.push_back("D 4");
  cmd.push_back("C");
  cmd.push_back("U 2");
  cmd.push_back("Z");
  cmd.push_back("Z");
  cmd.push_back("U 1");
  cmd.push_back("C");
  // cmd.push_back("C");
  // cmd.push_back("C");
  // cmd.push_back("C");
  // cmd.push_back("C");
  // cmd.push_back("Z");
  // cmd.push_back("Z");
  // cmd.push_back("C");
  cout << solution(n,k,cmd);
  // [,"C","U 3","C","D 4","C","U 2","Z","Z"]
}