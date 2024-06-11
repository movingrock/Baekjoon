#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int accSum[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    int answer = 0;
    
    for(int i =0; i<skill.size(); i++){
        int x1 = skill[i][1];
        int y1 = skill[i][2];
        int x2 = skill[i][3];
        int y2 = skill[i][4];
        int degree = skill[i][5];
        if(skill[i][0] == 1) degree *= -1;
        
        accSum[x1][y1] += degree;
        accSum[x2 +1][y2+1] += degree;
        accSum[x1][y2+1] -= degree;
        accSum[x2+1][y1] -= degree;     
    }
    
    for(int i=0; i<board.size(); i++){
        for(int j= 0; j<board[0].size(); j++){
            accSum[i][j+1] += accSum[i][j];
        }
    }
    
    for(int j= 0; j<board[0].size(); j++){
        for(int i=0; i<board.size(); i++){
            accSum[i+1][j] += accSum[i][j];
        }
    }
    
    for(int i =0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++){
            if(board[i][j] + accSum[i][j] > 0) answer++;
        }
    }
    
    
    return answer;
}