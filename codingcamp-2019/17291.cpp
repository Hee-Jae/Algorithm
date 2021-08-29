#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    vector<pair<int, int> > v;
    int N;
    scanf("%d", &N);
    v.push_back(make_pair(0,0));
    v.push_back(make_pair(1,1));
    v.push_back(make_pair(2,1));
    for(int i=3; i<=20; i++){
        v.push_back(make_pair(v[i-1].first*2, v[i-1].first));
        if(i%2==0) v[i].first -= (v[i-4].second + v[i-3].second); 
    }
    printf("%d", v[N].first);
}