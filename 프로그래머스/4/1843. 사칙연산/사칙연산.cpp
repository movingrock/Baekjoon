#include <vector>
#include <string>
#include <climits>

using namespace std;

int dp_max[101][101];
int dp_min[101][101];

int solution(vector<string> arr)
{
    int answer = -1;
    
    int num = arr.size() / 2 + 1;
    
    // i부터 j까지 구간 연산의 최대값과 최솟값
    for(int i =0 ; i<num; i++){
        for(int j = 0; j<num; j++){
            // i, j가 같다면 
            if(i == j){
                dp_max[i][j] = stoi(arr[i*2]);
                dp_min[i][j] = stoi(arr[i*2]);
            }else{
                dp_max[i][j] = INT_MIN;
                dp_min[i][j] = INT_MAX;
            }
        }
    }

    for(int cnt = 1; cnt < num; cnt++){     // i와 j의 간격
        for(int i = 0; i<num-cnt; i++){
            int j = i + cnt;
            for(int k = i; k<j; k++){
                if(arr[k*2 + 1] == "+"){
                    // i부터 k까지의 값과 k+1부터 j까지의 값의 연산
                    dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k+1][j]);
                    dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k+1][j]);
                }else if(arr[k*2+1] == "-"){
                    dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] - dp_min[k+1][j]);
                    dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] - dp_max[k+1][j]);
                }
            }
        }
    }
    
    answer = dp_max[0][num-1];
    
    return answer;
}