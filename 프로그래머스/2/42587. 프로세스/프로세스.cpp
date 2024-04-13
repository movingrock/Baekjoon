#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for(int i= 0 ; i<priorities.size(); i++){
        q.push(make_pair(priorities[i], i)); // {2, 0}{1, 1}{3,2}{2,3}
    }
    sort(priorities.begin(), priorities.end(), greater<>());
    
    // for(int i= 0; i<priorities.size(); i++){
    //     cout << priorities[i] << " ";
    // }
    
    
    for(int i = 0; i<priorities.size(); i++){
        while(q.front().first != priorities[i]){
            q.push(q.front());
            q.pop();
        }
        if(q.front().second == location) answer = i + 1;
        q.pop();
    }
    
    return answer;
}