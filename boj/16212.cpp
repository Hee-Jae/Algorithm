#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[500001]={};
int main(){
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &arr[i]);
  sort(arr, arr+N);
  for(int i=0; i<N; i++) printf("%d ", arr[i]);
}