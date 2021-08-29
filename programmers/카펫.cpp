#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int garo=yellow, sero;
    while(garo > 0){
      if(yellow%garo == 0){
        sero = yellow/garo;
        if((garo+sero+2)*2 == brown){
          answer.push_back(garo+2);
          answer.push_back(sero+2);
          break;
        }
      }
      garo--;
    }
    return answer;
}

int main(){
  vector<int> v;
  v = solution(24,24);
}