#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int arr[5000000]={};

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int main(){
    int N, L;
    // scanf("%d %d", &N, &L);
    ios::sync_with_stdio(0);
    cin.tie(0);    
    cin >> N >> L;
    for(int i=0; i<N; i++) cin >> arr[i];
    //scanf("%d", &arr[i]);
    int start = 0-L+1, end=0;
    while(end < N){
        pq.push(make_pair(arr[end], end));
        // printf("%d ", pq.top().first);
        cout << pq.top().first << " ";
        start ++;
        end ++;
        while(pq.top().second < start && !pq.empty()){
            pq.pop();
        }
    }
}