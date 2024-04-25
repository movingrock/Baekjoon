#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
map<pair<int, int>, bool> node_visited;
map<pair<pair<int, int>, pair<int, int>>, bool> edge_visited;

int solution(vector<int> arrows) {
    int answer = 0;
    
    int x = 0;
    int y = 0;
    node_visited[{x,y}] = true;
    
    for(int i = 0; i<arrows.size(); i++){
        int dir = arrows[i];
        
        // 크기를 2배 해줬기 때문에 같은 방향으로 연산 두번 해줌.
        for(int j = 0; j<2; j++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            // 한 바퀴 순환이 되었을 때(방이 만들어졌을 때)
            if(node_visited[{nx, ny}] == true && edge_visited[{{x, y}, {nx, ny}}] == false){
                edge_visited[{{x, y}, {nx, ny}}] = true;
                edge_visited[{{nx, ny}, {x, y}}] = true;
                answer++;
                x = nx;
                y = ny;
                continue;
            }
            // 방이 만들어진 경우가 아닐때(방문 확인)
            node_visited[{nx, ny}] = true;
            edge_visited[{{x, y}, {nx, ny}}] = true;
            edge_visited[{{nx, ny}, {x, y}}] = true;
            x = nx;
            y = ny;
        }
    }
    
    return answer;
}