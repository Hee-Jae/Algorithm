#include <string>
#include <vector>
#define PRIME 1
#define COMPOSITE 0
using namespace std;


uint64_t mod_add(uint64_t a, uint64_t b, uint64_t m)
{
    a %= m;
    b %= m;
    if(a+b < b) return (a+(b-m))%m;
    return (a+b)%m;
}

uint64_t mod_mul(uint64_t a, uint64_t b, uint64_t m)
{
    uint64_t r = 0;
    while(b > 0){
        if(b&1) r = mod_add(r, a, m);
        b = b >> 1;
        a = mod_add(a, a, m);
    }
    return r;
}

uint64_t mod_pow(uint64_t a, uint64_t b, uint64_t m)
{
    uint64_t r = 1;
    while(b > 0){
        if(b&1) r = mod_mul(r, a, m);
        b = b >> 1;
        a = mod_mul(a, a, m);
    }
    return r;
}

int miller_rabin(uint64_t n)
{
    if(n==2) return PRIME;
    if(n%2==0 || n < 2) return COMPOSITE;

    uint64_t a[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    uint64_t k=1, q, aq, p;
    
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

string ntok(int n, int k){
  string res = "";
  while(n){
    res += '0' + n%k;
    n /= k;
  }
  string rev_str = "";
  for(int i=res.size()-1; i>=0; i--){
    rev_str += res[i];
  }
  return rev_str;
}

int solution(int n, int k) {
    int answer = 0;
    vector<uint64_t> karr;
    string kjin = ntok(n, k);
    int ksize = kjin.size();
    string tmp = "";
    for(int i=0; i<ksize; i++){
      if(kjin[i] == '0'){
        if(tmp.size() > 0){
          karr.push_back(stoull(tmp));
          tmp = "";
        }
      }
      else{
        tmp += kjin[i];
      }
    }
    karr.push_back(stoull(tmp));

    for(int i=0; i<karr.size(); i++){
      if(miller_rabin(karr[i]) == PRIME){
        // cout << karr[i] << "\n";
        answer ++;
      }
    }
    
    // cout << kjin << "\n";
    return answer;
}

int main(void)
{
    cout << solution(437674, 3) << "\n";
    cout << solution(110011, 10) << "\n";
}
