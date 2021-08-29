#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define NODE 300
#define EDGE 300
using namespace std;
typedef pair<int, int> pp;
typedef pair<pp, int> p;


int n, m, ans = 0;

int dir[4][2] = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
int root[EDGE];
int map[NODE][NODE];
int visited[NODE][NODE];
pp nodes[EDGE];
p edges[70000];
queue<p> q;

bool compare(p a, p b) {
  return a.nd < b.nd;
}

int find(int x) {
  if(x == root[x]) return x;

  int curRoot = root[x];
  return root[x] = find(curRoot);
}

int _union(int x, int y) {
  int rootX = find(x), rootY = find(y);
  if(rootX == rootY) return 0;
  
  root[rootY] = rootX;
  return 1;
}

void initRoot() {
  for(int i=0;i<=m;i++) root[i] = i;
}

int getNodeNum(pp x, int nodeLen) {
  for(int i=0;i<nodeLen;i++) if(x.st == nodes[i].st && x.nd == nodes[i].nd) return i;
  return -1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  initRoot();
  int node_idx = 1, edge_idx = 0;
  char input[NODE];
  for(int i=1;i<=n;i++) {
    cin >> input;
    for(int j=0;j<n;j++) {
      if(input[j] == 'K' || input[j] == 'S') {
        if(input[j] == 'S') nodes[0] = mp(i, j+1);
        else nodes[node_idx++] = mp(i, j+1);
        map[i][j+1] = input[j];
      }
      else map[i][j+1] = input[j] - '0';
    }
  }
  for(int i=0;i<node_idx;i++) {
    for(int u=1;u<=n;u++) for(int l=1;l<=n;l++) visited[u][l] = 0;
    pp start = nodes[i];
    q.push(mp(start, 0));
    visited[start.st][start.nd] = 1;
    int isAllFinded = 0;
    while(!q.empty()) {
      p cur = q.front();
      q.pop();
      int curdx = cur.st.st, curdy = cur.st.nd;
      for(int j=0;j<4;j++) {
        int dx = curdx + dir[j][0], dy = curdy + dir[j][1];
        if(dx >= n || dx < 1 || dy >= n || dy < 1) continue;
        if(map[dx][dy] == 1 || visited[dx][dy]) continue;
        if (map[dx][dy] == 'K' || map[dx][dy] == 'S') {
          isAllFinded++;
          int nextNodeNum = getNodeNum(mp(dx,dy), node_idx);
          edges[edge_idx++] = mp(mp(i, nextNodeNum), cur.nd + 1);
        }
        visited[dx][dy] = 1;
        q.push(mp(mp(dx, dy), cur.nd+1));
      }
    }
    if(isAllFinded != m) {
      cout << "-1\n";
      return 0;
    }
  }
  cout << "edge_idx : " <<edge_idx << "\n";
  sort(edges, edges+edge_idx, compare);
  for(int i=0;i<edge_idx;i++) {
    p cur = edges[i];
    int from = cur.st.st, to = cur.st.nd, val = cur.nd;
    if(!_union(from, to)) continue;
    ans += val;
  }
  cout << ans << "\n";
  return 0;
}