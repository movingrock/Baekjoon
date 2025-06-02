#include <string>
#include <vector>

using namespace std;

int toMin(int time) {
    int h = time / 100;
    int m = time % 100;
    
    return h * 60 + m;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    startday--;
    
    for(auto s: schedules) s += 10;
    
    for(int i =0; i<timelogs.size(); i++){
        bool flag = true;
        for(int j = 0; j<timelogs[i].size(); j++){
            int date = (startday + j) % 7;
            if(date == 5 || date == 6) continue;
            if(toMin(schedules[i] + 10) < toMin(timelogs[i][j])) flag = false;
        }
        if(flag) answer++;
    }

    
    return answer;
}