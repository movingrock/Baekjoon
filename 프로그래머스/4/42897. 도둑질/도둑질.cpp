#include <string>
#include <vector>

using namespace std;

int dp[1000001];
int dp2[1000001];

int solution(vector<int> money) {
    int answer = 0;
    
    // 첫번째 집을 털었으면 마지막 집도 못털기 때문에 size() -1 전까지
    dp[0] = money[0];
    dp[1] = dp[0];
    for(int i = 2; i<money.size()-1; i++){
        dp[i] = max(dp[i-2] + money[i], dp[i-1]);
    }
    
    // 첫번째 집을 안 털었기 때문에 마지막 집을 털 수 있음.
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i = 2; i<money.size(); i++){
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    
    answer = max(dp[money.size()-2], dp2[money.size()-1]);
 
    return answer;
}