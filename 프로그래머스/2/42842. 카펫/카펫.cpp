#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int x= 1; x<=yellow; x++){ // 가로 길이 x라고 했을때
        int y = (brown - 4)/2 - x;

        if(x * y == yellow){
            answer.push_back(y + 2);
            answer.push_back(x + 2);
            break;
        }
    }
    
    return answer;
}
