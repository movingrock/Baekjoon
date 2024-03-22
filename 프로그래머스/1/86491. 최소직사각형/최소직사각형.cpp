#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(int i= 0; i<sizes.size(); i++){
        sort(sizes[i].begin(), sizes[i].end());
    }
    
    int max_h = 0;
    int max_w = 0;    
    for(int i = 0; i<sizes.size(); i++){
        max_h = max(max_h, sizes[i][0]);
        max_w = max(max_w, sizes[i][1]);
    }
    answer = max_h * max_w;
    
    return answer;
}