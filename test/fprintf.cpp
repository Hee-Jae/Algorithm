#include <cstdio>

using namespace std;

int main(){
  char buf[255];
  sprintf(buf, "hi");
  sprintf(buf, "%s/hello", buf);
  printf("%s", buf);
  return 0;
}