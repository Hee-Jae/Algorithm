#include <stdio.h>
using namespace std;

int main(){
	int N;
	int arr[1001]={};
	int dp[1001]={};
	scanf("%d", &N);
	for(int i=N-1; i>=0; i--) scanf("%d", &arr[i]);

	int count = 0;
	for(int i=0; i<N; i++){
		count = 0;
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j]){
				if(count < dp[j])	count = dp[j];
			}
		}
		dp[i] = count+1;
	}
	int max_len = 0;
	for(int i=0; i<N; i++){
		if(dp[i] > max_len) max_len = dp[i];
	}
	printf("%d", max_len);
}