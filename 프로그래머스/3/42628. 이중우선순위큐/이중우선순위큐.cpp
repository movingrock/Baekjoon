#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq; // 큰게 우선순위
    priority_queue<int, vector<int>, greater<int>> pqg; // 작은게 우선순위
    
    int cnt = 0;
    for(int i = 0; i<operations.size(); i++){
        if(operations[i][0] == 'I'){
            pq.push(stoi(operations[i].substr(2)));
            pqg.push(stoi(operations[i].substr(2)));
            cnt++;
        }else if(operations[i][0] == 'D'){
            if(operations[i][2] == '1'){
                if(cnt > 0) {
                    pq.pop();
                    cnt--;
                }
            }else if(operations[i][2] == '-'){
                if(cnt > 0){
                    pqg.pop();
                    cnt--;
                }
            }
        }
        
        if (cnt == 0){
            while(!pq.empty()){
                pq.pop();
            }
            while(!pqg.empty()){
                pqg.pop();
            }
        }
        
    }
    if(cnt > 0) answer.push_back(pq.top());
    else answer.push_back(0);
    
    if(cnt > 0) answer.push_back(pqg.top());
    else answer.push_back(0);
    
    
    return answer;
}