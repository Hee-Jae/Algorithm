#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int N;
	int num[500001]={};
	int freq[4001]={}, freq2[4001]={}, mostfreq[8002]={};
	int max=0, idx=0;
	double avg=0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &num[i]);
		avg += num[i];
		if(num[i] < 0) freq2[-num[i]]++;
		else freq[num[i]]++;
	}
	sort(num, num+N);
	printf("%.0f\n", avg/N);
	printf("%d\n", num[N/2]);

	for(int i=0; i<4001; i++){
		if(max < freq[i]) max = freq[i];
		if(max < freq2[i]) max = freq2[i];
	}

	for(int i=4000; i>=1; i--){
		if(freq2[i] == max) mostfreq[idx++] = -i;
	}
	for(int i=0; i<4001; i++){
		if(freq[i] == max) mostfreq[idx++] = i;
	}
	if(idx == 1) printf("%d\n", mostfreq[0]);
	else printf("%d\n", mostfreq[1]);
	printf("%d", num[N-1]-num[0]);
}