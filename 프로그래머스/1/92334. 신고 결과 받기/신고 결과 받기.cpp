#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

int grid[1001][1001] = {0, };
int mail[1001] = {0, };

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> m;
    for(int i=0; i<id_list.size(); i++){
        m.insert({id_list[i] , i});
    }
    
    for(int i = 0; i<report.size(); i++){
        istringstream iss(report[i]);
        string buffer;
        vector<string> result;
        
        while(getline(iss, buffer, ' ')){
            result.push_back(buffer);
        }
        grid[m[result[0]]][m[result[1]]] = 1;
    }
    
    vector<int> reported;
    
    for(int i =0; i<id_list.size(); i++){
        int cnt = 0;
        for(int j = 0; j<id_list.size(); j++){
            if(grid[j][i] == 1) cnt++;
        }
        if(cnt >= k) reported.push_back(i);
    }
    
    
    for(int i =0; i<id_list.size(); i++){
        for(int j = 0; j< reported.size(); j++){
            if(grid[i][reported[j]] == 1) mail[i]++;
        }
    }

    
    for(int i=0; i<id_list.size(); i++){
        answer.push_back(mail[i]);
    }
    
    return answer;
}

// 4번 신고했는데 신고가 통하면 네통을 받나?
