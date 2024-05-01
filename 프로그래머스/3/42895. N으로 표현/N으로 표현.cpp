#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    
    unordered_set<int> s[9];
    
    int sum = 0;
    // n , nn, nnn 넣기
    for(int i = 1; i <= 8; i++){
        sum = 10*sum + N;
        s[i].insert(sum);
    }
    
    // i가 7이면 j는 1~6
    // 7 1+6 2+5 3+4 4+3 5+2 6+1
    for (int i = 1; i <= 8; i++){
        for(int j = 1; j < i; j++){
            for(int a : s[j]){
                for(int b : s[i-j]){
                    s[i].insert(a+b);
                    s[i].insert(a-b);
                    s[i].insert(a*b);
                    if(b != 0)
                        s[i].insert(a/b);
                }
            }
        }
    }
    
    
    // 찾아주기
    for(int i = 1; i <= 8; i++){
        if(s[i].find(number) != s[i].end()){
            answer = i;
            break;
        }  
    }
    
    return answer;
}