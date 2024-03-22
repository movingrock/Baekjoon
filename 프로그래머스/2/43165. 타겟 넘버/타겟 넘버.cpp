#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[20];



// 합, 개수
void bfs(vector<int> numbers, int target, int &answer){
    queue<pair<int, int>> q;
    q.push(make_pair(numbers[0], 1));
    q.push(make_pair(-numbers[0], 1));
    
    while(!q.empty()){
        int sum = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cnt == numbers.size() && sum == target) answer++;
        
        if(cnt < numbers.size()){
            q.push(make_pair(sum + numbers[cnt], cnt+1));
            q.push(make_pair(sum - numbers[cnt], cnt+1));    
        }

    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    bfs(numbers, target, answer);
    
    return answer;
}