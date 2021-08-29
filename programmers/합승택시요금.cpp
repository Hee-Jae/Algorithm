#include <string>
#include <vector>
#include <algorithm>
#define INF 1e8
using namespace std;

int dist[205][205]={};
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0, vsize=fares.size();
    int from, to, cost;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i=0; i<vsize; i++){
        from = fares[i][0];
        to = fares[i][1];
        cost = fares[i][2];
        dist[from][to] = cost;
        dist[to][from] = cost;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    int direct = dist[s][a] + dist[s][b];
    int indirect = INF;
    for(int k=1; k<=n; k++){
        if(indirect > dist[s][k]+dist[k][a]+dist[k][b])
            indirect = dist[s][k]+dist[k][a]+dist[k][b];
    }
    if(direct > indirect) answer = indirect;
    else answer = direct;
    return answer;
}