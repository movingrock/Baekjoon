#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

// 소수 판별 함수
bool isPrime(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}


int solution(string numbers) {
    int answer = 0;
    
    // 오름차순으로 정렬해주어야 next_permutation이 처음부터 순열값을 구해줌.
    sort(numbers.begin(), numbers.end());
    unordered_set<int> s;
    
    // 모든 순열 조합을 구해주는 함수 next_permutation
    
    do {
        for(int i = 1; i<=numbers.size(); i++){
            int x = stoi(numbers.substr(0, i));
            if(isPrime(x)) s.insert(x);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    answer = s.size();
    return answer;
}