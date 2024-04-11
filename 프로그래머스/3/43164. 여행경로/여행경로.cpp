#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> ticket;
vector<string> answer;
bool visited[10001];
bool isAnswer = false;

void dfs(string city, int cnt){
    answer.push_back(city);
    
    if(cnt == ticket.size()){
        isAnswer = true;
        return;
    }
    
    for(int i= 0; i<ticket.size(); i++){

        if(!visited[i] && ticket[i][0] == city){
            visited[i] = true;
            dfs(ticket[i][1], cnt + 1);
            
            if(!isAnswer){
                visited[i] = false;
                answer.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    ticket = tickets;
    
    dfs("ICN" , 0);
    
    return answer;
}