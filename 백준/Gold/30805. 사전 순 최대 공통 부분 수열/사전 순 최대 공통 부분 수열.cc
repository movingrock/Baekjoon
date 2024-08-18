#include <iostream>
#include <vector>

using namespace std;

vector<int> dp[101][101];

vector<int> longestCommonSubsequence(vector<int>& A, vector<int>& B) {
    int N = A.size(), M = B.size();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                if (dp[i][j].empty()) dp[i][j].push_back(A[i - 1]);
                else {
                    vector<int> tmp;
                    for (int k = 0; k < dp[i][j].size(); k++) {
                        if (dp[i][j][k] < A[i - 1]) {
                            break;
                        }
                        else {
                            tmp.push_back(dp[i][j][k]);
                        }
                    }
                    dp[i][j] = tmp;
                    dp[i][j].push_back(A[i - 1]);
                }

                //dp[i][j].push_back(A[i - 1]);
            }
            else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    //for (int i = 0; i <= N; i++) {
    //    for (int j = 0; j <= M; j++) {
    //        for (int k = 0; k < dp[i][j].size(); k++) {
    //            cout << dp[i][j].size();
    //            //cout << dp[i][j][k];
    //        }
    //        cout << " ";
    //    }
    //    cout << endl;
    //}

    return dp[N][M];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    vector<int> result = longestCommonSubsequence(A, B);

    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

	return 0;
}



