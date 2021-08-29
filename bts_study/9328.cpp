#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
char map[101][101]={};
int search(int i, int j, int h, int w, int keyInfo[], vector<vector<pair<int, int> > >&v){
  if(map[i][j] == '*') return 0;
  int cnt = 0;
  queue<pair<int, int> > q;
  if(map[i][j] == '.'){
    q.push(make_pair(i,j));
    map[i][j] = '*';
  }
  else if(map[i][j] == '$'){
    q.push(make_pair(i,j));
    cnt ++;
    map[i][j] = '*';
  }
  else if('a' <= map[i][j] && map[i][j] <= 'z'){
    q.push(make_pair(i,j));
    keyInfo[map[i][j]-'a'] = 1;
    map[i][j] = '*';
  }
  else if('A' <= map[i][j] && map[i][j] <= 'Z'){
    if(keyInfo[map[i][j]-'A'] == 1){
      q.push(make_pair(i,j));
      map[i][j] = '*';
    }
    else{
      v[map[i][j]-'A'].push_back(make_pair(i,j));
    }
  } // end of first execution
  int x,y,xx,yy;
  while(!q.empty()){
    x = q.front().first;
    y = q.front().second;
    q.pop();
    for(int k=0; k<4; k++){
      xx = x + dir[k][0];
      yy = y + dir[k][1];
      if(xx < 0 || xx >= h || yy  < 0 || yy >= w) continue;
      if(map[xx][yy] == '*') continue;
      if(map[xx][yy] == '.'){
        q.push(make_pair(xx,yy));
        map[xx][yy] = '*';
      }
      else if(map[xx][yy] == '$'){
        cnt ++;
        map[xx][yy] = '*';
        q.push(make_pair(xx,yy));
      }
      else if('a' <= map[xx][yy] && map[xx][yy] <= 'z'){
        q.push(make_pair(xx,yy));
        int vsize = v[map[xx][yy]-'a'].size();
        for(int i=0; i<vsize; i++){
          q.push(make_pair(v[map[xx][yy]-'a'][i].first, v[map[xx][yy]-'a'][i].second));
        }
        keyInfo[map[xx][yy]-'a'] = 1;
        map[xx][yy] = '*';
      }
      else if('A' <= map[xx][yy] && map[xx][yy] <= 'Z'){
        if(keyInfo[map[xx][yy]-'A'] == 1){
          q.push(make_pair(xx,yy));
          map[xx][yy] = '*';
        }
        else{
          v[map[xx][yy]-'A'].push_back(make_pair(xx,yy));
        }
      }
    } // direction
  } // while queue is not empty
  return cnt;
} // end of search

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  for(cin>>T; T; T--){
    int h,w, cnt=0, keyInfo[26]={};
    char key[100]={};
    vector<vector<pair<int, int> > > v(26);
    cin >> h >> w;
    for(int i=0; i<h; i++) cin >> map[i];
    cin >> key;
    if(key[0] != '0'){
      for(int i=0; key[i]!='\0'; i++) keyInfo[key[i]-'a'] = 1;
    }
    for(int i=0; i<h; i++){
      if(i==0 || i==h-1){
        for(int j=0; j<w; j++){
          cnt += search(i,j,h,w,keyInfo,v);
        } //for top or bottom's all w.
      } //if top or bottom
      else{
        cnt += search(i,0,h,w,keyInfo,v);
        cnt += search(i,w-1,h,w,keyInfo,v);
      } //if middle
    } // for each h
    cout << cnt << "\n";
  } // test case
} // main