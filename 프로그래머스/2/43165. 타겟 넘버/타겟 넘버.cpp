#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[20];

int answer = 0;

// 합, 개수
void bfs(vector<int> numbers, int target){
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

void dfs(int n, int sum, vector<int> numbers, int target){
    if(n == numbers.size() && sum == target) answer++;
    else if(n >= numbers.size()) return;
    
    dfs(n+1, sum + numbers[n], numbers, target);
    dfs(n+1, sum - numbers[n], numbers, target);
}

int solution(vector<int> numbers, int target) {
    
    // bfs(numbers, target, answer);
    dfs(0, 0, numbers, target);
    
    return answer;
}