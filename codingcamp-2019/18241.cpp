#include <iostream>
#include <string.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char W[11]={}, S[300001]={}, O;
    int N, pos[300000]={}, p_idx=0,flag=0;
    cin >> W >> S >> N;
    int wlen = strlen(W);
    for(int i=0; S[i]!='\0'; i++){
        if(S[i]==W[0]){
            // cout << "find!" << endl;
            flag=1;
            for(int j=0; W[j]!='\0'; j++){
                if(S[i+j] != W[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                // cout << "good!" << endl;
                pos[p_idx++] = i;
                flag = 0;
                i+=wlen-1;
            }
        }
        // cout << i << endl;
    }
    // for(int i=0; i<p_idx; i++) cout << pos[i] << " ";
    int l_idx=0, r_idx=p_idx-1, count=0;
    for(int i=0; i<N; i++){
        cin >> O;
        if(l_idx > r_idx) continue;
        if(O == 'L'){
            for(int j=pos[l_idx]; j<pos[l_idx]+wlen; j++){
                S[j] = 'X';
            }
            l_idx++;
        }
        else if(O == 'R'){
            for(int j=pos[r_idx]; j<pos[r_idx]+wlen; j++){
                S[j] = 'X';
            }
            r_idx--;
        }
        count++;
    }

    cout << count << "\n";
    for(int i=0; S[i]!='\0'; i++){
        if(S[i] != 'X') cout << S[i];
    }
    cout << '\n';
    if(l_idx > r_idx) cout << "Perfect!";
    else cout << "You Lose!";
}