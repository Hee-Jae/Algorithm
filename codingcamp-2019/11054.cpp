#include <stdio.h>
using namespace std;

int main(){
	int N;
	int arr[1001]={}, r_arr[1001]={};
	int dp[1001]={}, r_dp[1001]={};
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
  for(int i=0; i<N; i++) r_arr[i] = arr[N-1-i];
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
  for(int i=0; i<N; i++){
		count = 0;
		for(int j=0; j<i; j++){
			if(r_arr[i] > r_arr[j]){
				if(count < r_dp[j])	count = r_dp[j];
			}
		}
		r_dp[i] = count+1;
	}
  // for(int i=0; i<N; i++) printf("%d ", dp[i]);
  // printf("\n");
  // for(int i=N-1; i>=0; i--) printf("%d ", r_dp[i]);
	int max_len = 0;
	for(int i=0; i<N; i++){
		if(dp[i] + r_dp[N-1-i] > max_len) max_len = dp[i] + r_dp[N-1-i];
	}
	printf("%d", max_len-1);
}