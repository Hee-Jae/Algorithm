#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int

using namespace std;

int solution(string s) {
    int length = s.length(), previdx;
    int answer = 1000, case_ans = 0, pcnt = 0;
    bool flag;
    string prev;
    if(length==1) return 1;
    for(int psize=1; psize<=length/2; psize++){
        prev = s.substr(0,psize);
        // cout << "prev : " << prev << "\n";
        case_ans = length;
        pcnt = 1;
        for(int i=psize; i<length; i+=psize){
            previdx = 0;
            flag = false;
            for(int j=i; j<i+psize; j++){
                if(s[j] != prev[previdx++]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                pcnt++;
                case_ans -= psize;
            }
            else{
                if(i+psize < length) prev = s.substr(i, psize);
                if(pcnt >= 2){
                  while(pcnt > 0){
                    pcnt /= 10;
                    case_ans ++;
                  }
                }
                pcnt = 1;
            }
        }
        if(pcnt >= 2){
          while(pcnt > 0){
            pcnt /= 10;
            case_ans ++;
          }
        }
        if(case_ans < answer) answer = case_ans;
        // cout << psize <<" : " << case_ans << "\n";
    }
    return answer;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = solution(s);
  cout << ans << "\n"; 
}