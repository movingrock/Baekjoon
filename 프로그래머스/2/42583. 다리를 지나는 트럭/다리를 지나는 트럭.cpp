#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<pair<int, int>> q; // 무게 , 들어온 시간
    
    int cnt = 0;
    int escape = 0;
    int sum = 0;
    
    while(true){
        if(escape == truck_weights.size()) break;
        answer++;
        
        if(!q.empty() && q.front().second + bridge_length == answer){
            sum -= q.front().first;
            q.pop();
            escape++;
        }
        
        if(cnt <= truck_weights.size() - 1 && sum+truck_weights[cnt] <= weight){
            q.push({truck_weights[cnt], answer});
            sum += truck_weights[cnt];
            cnt++;
        }

    }

    return answer;
}