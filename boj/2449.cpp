#include <iostream>
#include <algorithm>
using namespace std;

int N,K,light[201]={}, arr[201]={}, dp[201][201]={0};
int cnt(int start, int end){
	if(start == end) return 0;
	if(dp[start][end] != -1) return dp[start][end];
	dp[start][end] = 987654321;
	for(int i=start; i<=end; i++){
		int temp = 0;
		if(arr[start] == arr[i+1]) temp = 0;
		else temp = 1;
		dp[start][end] = min(dp[start][end], cnt(start,i)+cnt(i+1,end)+temp);
	}
	return dp[start][end];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for(int i=0; i<N; i++) cin >> light[i];
	
	int prev=light[0], index=1;
	arr[0] = light[0];
	for(int i=1; i<N; i++){
		if(prev == light[i]) continue;
		else{
			arr[index++] = light[i];
			prev = light[i];
		}
	}
	for(int i=0; i<index; i++)
		for(int j=0; j<index; j++) dp[i][j] = -1;
	
	cout << cnt(0,index-1);
	return 0;
}