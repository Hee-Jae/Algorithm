#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int> > queries) {
  vector<int> answer;
  vector<vector<int> > arr(rows, vector<int>(columns));
  for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){
      arr[i][j] = i*columns + j + 1;
    }
  }

  int x1, y1, x2, y2, min_entry;
  int temp;
  for(int i=0; i<queries.size(); i++){
    x1 = queries[i][0]-1;
    y1 = queries[i][1]-1;
    x2 = queries[i][2]-1;
    y2 = queries[i][3]-1;
    min_entry = rows*columns+1;
    temp = arr[x1][y2];
    
    for(int j=y2; j>=y1+1; j--){
      if(min_entry > arr[x1][j]) min_entry = arr[x1][j];
      arr[x1][j] = arr[x1][j-1];
    }
    
    for(int j=x1; j<=x2-1; j++){
      if(min_entry > arr[j][y1]) min_entry = arr[j][y1];
      arr[j][y1] = arr[j+1][y1];
    }
    
    for(int j=y1; j<=y2-1; j++){
      if(min_entry > arr[x2][j]) min_entry = arr[x2][j];
      arr[x2][j] = arr[x2][j+1];
    }

    for(int j=x2; j>=x1+2; j--){
      if(min_entry > arr[j][y2]) min_entry = arr[j][y2];
      arr[j][y2] = arr[j-1][y2];
    }

    if(min_entry > arr[x1+1][y2]) min_entry = arr[x1+1][y2];
    arr[x1+1][y2] = temp;

    answer.push_back(min_entry);
  }

  
  return answer;
}

int main(){
  vector<vector<int> > v = {{2,2,5,4},{3,3,6,6},{5,1,6,3}};
  vector<int> ans = solution(6,6,v);
  for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
}