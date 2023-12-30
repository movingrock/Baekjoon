#include <iostream>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int min_num = INT_MAX;
    int max_num = INT_MIN;
    int arr[1000000];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        min_num = min(min_num, arr[i]);
        max_num = max(max_num, arr[i]);
    }
    
    cout << min_num << " " << max_num;
    
    return 0;
}