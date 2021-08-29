#include <stdio.h>
using namespace std;

int main(){
	int N;
	int arr[1001]={};
	int dp[1001]={};
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);

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
    // printf("dp[%d] : %d\n", i, dp[i]);
		if(dp[i] > max_len) max_len = dp[i];
	}
	printf("%d\n", max_len);
  int pos = max_len;
  int pos_arr[1001] = {}, idx=0;
  for(int i=N; i>=0; i--){
    // if(dp[i] == pos-1) pos_arr[idx-1] = i;
    // if(dp[i] == pos){
    //   pos ++;
    //   pos_arr[idx++] = i;
    // }
    if(dp[i] == pos){
      pos_arr[idx++] = i;
      pos --;
    }
  }
  for(int i=idx-1; i>=0; i--) printf("%d ", arr[pos_arr[i]]);
  // for(int i=0; i<idx; i++) printf("%d ", arr[pos_arr[i]]);
}