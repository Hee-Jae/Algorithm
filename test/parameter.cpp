#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

void prt(char *m[100], int h, int w){
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
  m[0][0]='A';
}

void prt2(map<int, int> &mp){
  map<int, int> ::iterator it;
  for(it=mp.begin(); it!=mp.end(); it++){
    printf("%d ", it->first);
  }
}

void prt3(vector<vector<pair<int, int> > >&v){
  v[3][0].first = 5;
}
char m[100][100]={};
int main(){
  // char map[100][100]={};
  // for(int i=0; i<3; i++) scanf("%s", m[i]);
  // printf("--\n");
  // for(int i=0; i<3; i++) scanf("%s", m[i]);
  // for(int i=0; i<3; i++){
  //   for(int j=0; j<3; j++){
  //     printf("%c", m[i][j]);
  //   }
  //   printf("\n");
  // }
  // map<int, int> m;
  // m.insert(make_pair(1,1));
  // m.insert(make_pair(2,2));
  // m.insert(make_pair())
  // m.insert(make_pair(3,3));
  // prt2(m);
  vector<vector<pair<int, int> > > v(10);
  // v.push_back(make_pair(1,1));
  // v.push_back(make_pair(2,1));
  // v.push_back(make_pair(3,1));
  // prt3(v);
  // printf("[%d]", v[0].first);
  v[3].push_back(make_pair(1,2));
  printf("%d %d\n", v[3][0].first, v[3][0].second);
  prt3(v);
  printf("%d %d\n", v[3][0].first, v[3][0].second);
}