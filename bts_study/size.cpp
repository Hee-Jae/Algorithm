#include <stdio.h>

int* change(int arr[]){
  arr[2] = 3;
  return arr;
}
int main(){
  int array[10]={0,1,2,3,4,5,6,7,8,9};
  printf("before : %d\n", array[2]);

  int *s;
  s = change(array);
  printf("after : %d\n", s[2]);
}