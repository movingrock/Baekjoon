#include <string>
#include <vector>
#include <stack>

using namespace std;

int arr[100001];

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    stack<pair<int, int>> s;
    
    for(int i= 0; i<prices.size(); i++){
        while(!s.empty() && prices[i] < s.top().first){
            arr[s.top().second] = i - s.top().second;
            s.pop();
        }

        s.push({prices[i], i});
    }
    while(!s.empty()){
        arr[s.top().second] = prices.size() - 1 - s.top().second;
        s.pop();
    }
    
    
    for(int i = 0 ; i<prices.size(); i++){
        answer.push_back(arr[i]);
    }
    
    return answer;
}