#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<pair<int, int> > v;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, S,E;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> S >> E;
        v.push_back(make_pair(E,S));
    }
    sort(v.begin(), v.end());
    
    int count=1, endtime=v[0].first;
    for(int i=1; i<N; i++){
        if(v[i].second >= endtime){
            endtime = v[i].first;
            count ++;
        }
    }
    cout << count;
}