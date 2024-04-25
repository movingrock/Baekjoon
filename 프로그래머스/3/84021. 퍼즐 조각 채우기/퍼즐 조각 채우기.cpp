#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool visited[51][51] = {0, };

vector<vector<pair<int, int>>> blank;
vector<vector<pair<int, int>>> block;
int answer = 0;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void rotation(vector<pair<int, int>> &v){
    int row =0;
    for(int i = 0; i<v.size(); i++){
        if(row < v[i].first) row = v[i].first;
    }
    for(int i = 0; i<v.size(); i++){
        int y = v[i].first;
        int x = v[i].second;
        v[i].first = x;
        v[i].second = row - y;
    }
}

bool InRange(int x, int y, vector<vector<int>> map) {
    return x>=0 && x<map.size() && y>=0 && y<map.size();
}

vector<pair<int, int>> Tozero(vector<pair<int, int>> v){
    int min_i = 51;
    int min_j = 51;
    for(int i = 0; i<v.size(); i++){
        if(min_i > v[i].first) min_i = v[i].first;
        if(min_j > v[i].second) min_j = v[i].second;
    }
    
    for(int i = 0; i<v.size(); i++){
        v[i].first -= min_i;
        v[i].second -= min_j;
    }
    
    return v;
}

vector<pair<int, int>> bfs(int a, int b, vector<vector<int>> map, int find){
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    vector<pair<int, int>> output;
    output.push_back({a, b});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(nx, ny, map) && map[nx][ny] == find && !visited[nx][ny]){
                q.push({nx, ny});
                output.push_back({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return output;
}

void Func(){
    vector<bool> used(block.size(), false);
    
    for(vector<pair<int, int>> a : blank){ // 빈칸 a를 기준으로
        for(int i = 0; i<block.size(); i++){ // i개의 블럭 하나씩 끼워보기
            vector<pair<int, int>> b = block[i];
            if(used[i]) continue;
            if(a.size() != b.size()) continue;
            
            bool flag = false;
            // 4방향 회전하며 비교
            for(int j = 0; j<4; j++){
                int k = 0;
                for(int x = 0; x< a.size(); x++){ // 크기가 같기에 좌표 하나하나 위치비교
                    for(int y = 0; y< b.size(); y++){
                        if(a[x].first == b[y].first && a[x].second == b[y].second) k++;
                    }
                }
                // cout << endl;
                if (k != a.size()){
                    rotation(b);
                    continue;
                }
                answer += a.size();
                used[i] = true;
                flag = true;
                cout << a.size() << endl;
                break;
            }
            if(flag) break;
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    
    // 빈칸 찾기
    for(int i= 0; i<game_board.size(); i++){
        for(int j = 0; j<game_board.size(); j++){
            if(game_board[i][j] == 0 && !visited[i][j]) blank.push_back(Tozero(bfs(i, j, game_board, 0)));
        }
    }
    
    for(int i = 0; i<game_board.size(); i++){
        for(int j= 0; j<game_board.size(); j++){
            visited[i][j] = false;
        }
    }
    
    // 블럭 찾기
    for(int i= 0; i<table.size(); i++){
        for(int j = 0; j<table.size(); j++){
            if(table[i][j] == 1 && !visited[i][j]) block.push_back(Tozero(bfs(i, j, table, 1)));
        }
    }
    
    Func();
    
    return answer;
}