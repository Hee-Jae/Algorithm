#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int vsize = commands.size();
    int start, end, k;
    for(int i=0; i<vsize; i++){
        vector<int> temp;
        start = commands[i][0];
        end = commands[i][1];
        k = commands[i][2];
        for(int j=start-1; j<end; j++){
            temp.push_back(array[j]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
    }
    return answer;
}