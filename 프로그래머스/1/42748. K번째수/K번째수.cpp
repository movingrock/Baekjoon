#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i= 0; i<commands.size(); i++){
        vector<int> v;
        int x = commands[i][0] - 1;
        int y = commands[i][1] - 1;
        int z = commands[i][2] - 1;

        for(int j = x; j<=y; j++){
            v.push_back(array[j]);
        }
        sort(v.begin(), v.end());

        answer.push_back(v[z]);
    }
    
    
    return answer;
}