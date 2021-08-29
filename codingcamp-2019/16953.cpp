#include <stdio.h>
#include <queue>
using namespace std;
queue<pair<long long, long long> > q;

int main(){
    long long a, b, count, tmp, flag=1;
    scanf("%lld %lld", &a, &b);
    q.push(make_pair(1,a));
    while(!q.empty()){
        count = q.front().first;
        tmp = q.front().second;
        q.pop();
        if(tmp*2 == b){
            printf("%lld", count+1);
            flag = 0;
            break;
        }
        else if((tmp*10 + 1) == b){
            printf("%lld", count+1);
            flag = 0;
            break;
        }
        if(tmp*2 < b) q.push(make_pair(count+1, tmp*2));
        if((tmp*10 + 1) < b) q.push(make_pair(count+1, tmp*10+1));
    }
    if(flag) printf("-1");
}