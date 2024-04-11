#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr1[5] = {1, 2, 3, 4, 5}; // 5
int arr2[8] = {2, 1, 2, 3, 2, 4, 2, 5}; // 8
int arr3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 10

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1 = 0, p2 = 0, p3 = 0;
    
    for(int i = 0; i<answers.size(); i++){
        if(answers[i] == arr1[i%5]) p1++;
        if(answers[i] == arr2[i%8]) p2++;
        if(answers[i] == arr3[i%10]) p3++;  
    }
    int max_ans = max({p1, p2, p3});
    if(max_ans == p1) answer.push_back(1);
    if(max_ans == p2) answer.push_back(2);
    if(max_ans == p3) answer.push_back(3);
    
    return answer;
}