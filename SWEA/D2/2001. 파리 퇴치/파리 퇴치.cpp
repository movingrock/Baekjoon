#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
        int grid[15][15];
        cin >> n >> m;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
         		cin >> grid[i][j];       
            }
        }
        int max_sum = 0;
        for(int i= 0; i<n-m+1; i++){
         	for(int j =0; j<n-m+1; j++){   
                int sum = 0;
                for(int k = i; k<i+m; k++){
                 	for(int l = j; l<j+m; l++){
                    	   sum += grid[k][l];
                    }
                }
                max_sum = max(max_sum, sum);
            }
        }
        cout << "#" << test_case << " " << max_sum << endl;
	}
	return 0;
}