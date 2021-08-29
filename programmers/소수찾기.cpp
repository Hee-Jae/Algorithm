#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
#define PRIME 1
#define COMPOSITE 0


int mod_add(int a, int b, int m)
{
    a %= m;
    b %= m;
    if(a+b < b) return (a+(b-m))%m;
    return (a+b)%m;
}

int mod_mul(int a, int b, int m)
{
    int r = 0;
    while(b > 0){
        if(b&1) r = mod_add(r, a, m);
        b = b >> 1;
        a = mod_add(a, a, m);
    }
    return r;
}

int mod_pow(int a, int b, int m)
{
    int r = 1;
    while(b > 0){
        if(b&1) r = mod_mul(r, a, m);
        b = b >> 1;
        a = mod_mul(a, a, m);
    }
    return r;
}

int miller_rabin(int n)
{
    if(n==2) return PRIME;
    if(n<2 || n%2==0) return COMPOSITE;

    int a[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int k=1, q, aq, p;
    
    q = (n-1)>>1;
    while(!(q&1)){
        k++;
        q = q >> 1;
    }
    int i,j;
    for(i=0; i<12; i++){
        if(n <= a[i]) break;
        aq = mod_pow(a[i],q,n);
        if(aq==1) continue;
        for(j=0; j<k; j++){
            if(aq == n-1) break;
            aq = mod_mul(aq,aq,n);
        }
        if(aq == n-1) continue;
        return COMPOSITE;
    }
    return PRIME;
}

int visit[10]={}, primes=0;
map<int, int> m;
int makeNumber(string numbers){
    int ans = 0, len = numbers.length();
    for(int i=0; i<len; i++)
      ans = ans*10 + numbers[i]-'0';
    return ans;
}

void search(int n, string s, string numbers, int len, int nlen){
  visit[n]=1;
  s += numbers[n];
  int slen = s.length(), number;
  if(slen == len){
    // cout << s << "\n";
    number = makeNumber(s);
    if(m[number] == 0){
      m[number] = 1;
      if(miller_rabin(number)==PRIME) primes++;
    }
    visit[n] = 0;
  }
  else{
    for(int i=0; i<nlen; i++){
      // cout << "visit[" << i << "] : " << visit[i] << "\n";
      if(visit[i]==0) search(i,s,numbers,len, nlen);
    }
  }
  visit[n] = 0;
}
int solution(string numbers) {
    int answer = 0, len = numbers.length();
    string s="";
    for(int i=1; i<=len; i++){
      for(int j=0; j<len; j++) search(j,s,numbers,i,len);
    }
    
    answer = primes;
    return answer;
}
int main(void)
{
  string s="123";
  cout << solution(s);
}
