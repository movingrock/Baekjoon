#include <string>
#include <vector>

using namespace std;

int cnt = 0;
char arr[5] = {'A', 'E', 'I', 'O', 'U'};
int answer = 0;

void backtracking(string str, string word){
     if(str == word){
        answer = cnt;
        return;
    }
    cnt++;
    
    if(str.length() >= 5){
        return;
    }

    
    for(int i = 0; i<5; i++){
        backtracking(str + arr[i], word);
    }
}

int solution(string word) {
    string str = "";
    
    backtracking(str, word);
    
    return answer;
}