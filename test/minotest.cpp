#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int green_board[6][4], blue_board[4][6];
int score = 0;

void testprtg(){
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      if(i>=4 && j>=4) continue;
      cout << green_board[i][j] << " ";
    }
    cout << "\n";
  }
}

void testprtb(){
  for(int i=0; i<4; i++){
    for(int j=0; j<6; j++){
      // if(i>=4 && j>=4) continue;
      cout << blue_board[i][j] << " ";
    }
    cout << "\n";
  }
}
void fill_green(int t, int y){
  int idx = 5;
  if(t == 1 || t == 3){
    for(int i = 0 ; i < 6 ; i++){
      if(green_board[i][y]){
        idx = i - 1;
        break;
      }
    }

    green_board[idx][y] = t;

    if(t == 3) green_board[idx-1][y] = t;

    return;
  }else if(t == 2){
    for(int i = 0 ; i < 6 ; i++){
      if(green_board[i][y] || green_board[i][y+1]){
        idx = i - 1;
        break;
      }
    }
    green_board[idx][y] = t;
    green_board[idx][y+1] = t;
  }
  return;
}

void fill_blue(int t, int x){
  int idx = 5;

  if(t == 1 || t == 2){
    for(int j = 0 ; j < 6 ; j++){
      if(blue_board[x][j]){
        idx = j - 1;
        break;
      }
    }

    blue_board[x][idx] = t;
    if(t == 2) blue_board[x][idx-1] = t;
  }else if(t == 3){
    for(int j = 0 ; j < 6 ; j++){
      if(blue_board[x][j] || blue_board[x+1][j]){
        idx = j - 1;
        break;
      }
    }
    blue_board[x][idx] = t;
    blue_board[x+1][idx] = t;
  }
}

void delete_green(void){
  //행 지우기
  bool flag = false;

  for(int i = 2 ; i < 6 ; i++){

    bool line = true;

    for(int j = 0 ; j < 4 ; j++){
      if(green_board[i][j] == 0){
        line = false;
        break;
      }
    }

    if(!line) continue;

    score++;

    for(int j = 0 ; j < 4 ; j++){
      green_board[i][j] = 0;
    }

    flag = true;
  }

  //삭제 없으면 리턴
  if(!flag) return;

  //밑으로 내리기
  for(int i = 4 ; i >= 0 ; i--){

    for(int j = 0 ; j < 4 ; j++){
      int idx = 5;

      if(green_board[i][j] == 2){
        for(int q = i+1 ; q < 6 ; q++){
          if(green_board[q][j] || green_board[q][j+1]){
            idx = q-1;
            break;
          }
        }

        if(idx == i){
          j++;
          continue;
        }

        green_board[idx][j] = green_board[i][j];
        green_board[idx][j+1] = green_board[i][j+1];
        green_board[i][j] = 0;
        green_board[i][j+1] = 0;
        j++;

      }else{
        for(int q = i+1 ; q < 6 ; q++){
          if(green_board[q][j]){
            idx = q-1;
            break;
          }
        }

        if(idx == i) continue;

        green_board[idx][j] = green_board[i][j];
        green_board[i][j] = 0;
      }
    }
  }
  delete_green();
}

// void delete_blue(void){
//   //열 지우기
//   bool flag = false;

//   for(int j = 2 ; j < 6 ; j++){
//     bool line = true;
//     for(int i = 0 ; i < 4 ; i++){
//       if(!blue_board[i][j]){
//         line = false;
//         break;
//       }
//     }

//     if(!line) continue;

//     score++;

//     for(int i = 0 ; i < 4 ; i++) blue_board[i][j] = 0;

//     flag = true;
//   }

//   //삭제 없으면 리턴
//   if(!flag) return;

//   //밑으로 내리기
//   for(int j = 4 ; j >= 0 ; j--){

//     for(int i = 0 ; i < 4 ; i++){
//       int idx = 5;

//       if(blue_board[i][j] == 3){
//         for(int q = j+1 ; q < 6 ; q++){
//           if(blue_board[i][q] || blue_board[i+1][q]){
//             idx = q-1;
//             break;
//           }
//         }

//         if(idx == j){
//           i++;
//           continue;
//         }

//         blue_board[i][idx] = blue_board[i][j];
//         blue_board[i+1][idx] = blue_board[i+1][j];
//         blue_board[i][j] = 0;
//         blue_board[i+1][j] = 0;
//         i++;
//       }else{
//         for(int q = j+1 ; q < 6 ; q++){
//           if(blue_board[i][q]){
//             idx = q-1;
//             break;
//           }
//         }

//         if(idx == j) continue;

//         blue_board[i][idx] = blue_board[i][j];
//         blue_board[i][j] = 0;
//       }
//     }
//   }
//   delete_blue();
// }

void delete_blue(void){
  //열 지우기
  bool flag = false;

  for(int j = 2 ; j < 6 ; j++){
    bool line = true;
    for(int i = 0 ; i < 4 ; i++){
      if(!blue_board[i][j]){
        line = false;
        break;
      }
    }

    if(!line) continue;

    score++;

    for(int i = 0 ; i < 4 ; i++) blue_board[i][j] = 0;

    flag = true;
  }

  //삭제 없으면 리턴
  if(!flag) return;

  //밑으로 내리기
  for(int j = 4 ; j >= 0 ; j--){

    for(int i = 0 ; i < 4 ; i++){
      int idx = 5;
      if(blue_board[i][j] == 1 || blue_board[i][j] == 2){
        for(int q = j+1 ; q < 6 ; q++){
          if(blue_board[i][q]){
            idx = q-1;
            break;
          }
        }

        if(idx == j) continue;

        blue_board[i][idx] = blue_board[i][j];
        blue_board[i][j] = 0;
      }else if(blue_board[i][j] == 3){
        for(int q = j+1 ; q < 6 ; q++){
          if(blue_board[i][q] || blue_board[i+1][q]){
            idx = q-1;
            break;
          }
        }

        if(idx == j){
          i++;
          continue;
        }

        blue_board[i][idx] = blue_board[i][j];
        blue_board[i+1][idx] = blue_board[i+1][j];
        blue_board[i][j] = 0;
        blue_board[i+1][j] = 0;
        i++;
      }
    }
  }
  delete_blue();
}
void shift_green(void){
  int num = 0;
  for(int i = 0 ; i < 2 ; i++){
    for(int j = 0 ; j < 4 ; j++){
      if(green_board[i][j]){
        num++;
        break;
      }
    }
  }

  while(num--){
    for(int i = 5 ; i > 0; i--){
      for(int j = 0 ; j < 4 ; j++){
        green_board[i][j] = green_board[i-1][j];
      }
    }

    for(int j = 0 ; j < 4 ; j++) green_board[0][j] = 0;
  }
  return;
}

void shift_blue(void){
  int num = 0;
  for(int j = 0 ; j < 2 ; j++){
    for(int i = 0 ; i < 4 ; i++){
      if(blue_board[i][j]){
        num++;
        break;
      }
    }
  }

  while(num--){
    for(int j = 5 ; j > 0 ; j--){
      for(int i = 0 ; i < 4 ; i++){
        blue_board[i][j] = blue_board[i][j-1];
      }
    }

    for(int i = 0 ; i < 4 ; i++) blue_board[i][0] = 0;
  }

  return;
}

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    int t, x, y;
    cin >> t >> x >> y;

    // 보드 채우기
    fill_green(t,y);
    fill_blue(t,x);

    //green 실행
    delete_green();
    shift_green();

    // blue 실행
    delete_blue();
    shift_blue();
    // cout << "(" << t << "," << x << "," << y << ")\n";
    // testprtb();
    
  }
  cout << score << '\n';

  int cnt = 0;
  for(int i = 2 ; i < 6 ; i++){
    for(int j = 0 ; j < 4 ; j++){
      if(green_board[i][j]) cnt++;
      if(blue_board[j][i]) cnt++;
    }
  }

  cout << cnt << '\n';
  return 0;
}
