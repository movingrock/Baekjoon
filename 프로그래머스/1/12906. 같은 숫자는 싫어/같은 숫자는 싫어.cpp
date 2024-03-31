#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int cur_num = arr[0];
    answer.push_back(arr[0]);
    for(int i = 0; i<arr.size(); i++){
        if(cur_num != arr[i]) {
            answer.push_back(arr[i]);
            cur_num = arr[i];
        }
    }

    return answer;
}