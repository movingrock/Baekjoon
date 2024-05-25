#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string, int> m;
int grid[51][51];
int total[51];
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(int i =0; i<friends.size(); i++){
        m.insert({friends[i], i});
    }
    
    for(int i =0; i<gifts.size(); i++){
        istringstream iss(gifts[i]);
        string buffer;
        vector<string> result;
        
        while(getline(iss, buffer, ' ')){
            result.push_back(buffer);
        }
        int sendI = m[result[0]];
        int takeI = m[result[1]];
        
        grid[sendI][takeI]++;
        grid[takeI][sendI]--;
        total[sendI]++;
        total[takeI]--;
    }
    
    for(int i =0; i<friends.size(); i++){ // i번째 사람이 받게 되는 사람 수 구하기
        int cnt =0;
        for(int j =0; j<friends.size(); j++){
            if(i == j) continue;
            if(grid[i][j] > grid[j][i]){
                cnt++;
            }else if(grid[i][j] == grid[j][i] && total[i] > total[j]){
                cnt++;
            }
        }
        answer = max(answer, cnt);
    }
    
    return answer;
}