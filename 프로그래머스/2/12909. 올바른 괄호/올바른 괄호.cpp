#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> stk;
    for(int i= 0; i<s.length(); i++){
        if(s[i] == '(') stk.push('(');
        else{
            if(stk.empty()) answer = false;
            else stk.pop();
        }
    }
    
    if(answer && stk.empty()) answer = true;
    else answer = false;

    return answer;
}