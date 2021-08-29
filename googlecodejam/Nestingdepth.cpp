#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for(int test=1; test<=T; test++){
    string s;
    stack<char> st;
    cin >> s;
    int size=s.size(), cnt=0, stsize=0;
    char ans[5000]={};
    for(int i=0; i<size; i++){
      while(cnt < s[i]-'0'){
        st.push('(');
        cnt ++;
      }
      while(cnt > s[i]-'0'){
        st.push(')');
        cnt --;
      }
      st.push(s[i]);
    }
    while(cnt){
      st.push(')');
      cnt--;
    }
    stsize = st.size();
    for(int i=stsize-1; i>=0; i--){
      ans[i] = st.top();
      st.pop();
    }
    cout << "Case #" << test << ": ";
    for(int i=0; i<stsize; i++) cout << ans[i];
    cout << "\n"; 
  }
} 