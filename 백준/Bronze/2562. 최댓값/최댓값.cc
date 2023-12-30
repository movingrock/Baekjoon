#include <iostream>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[9];
    int max_num = INT_MIN;
    int max_index = 0;
    for(int i = 0; i<9; i++){
        cin >> arr[i];
        max_num = max(max_num, arr[i]);
        if(max_num == arr[i]) max_index = i;
    }
    
    cout << max_num << "\n" <<  max_index+1;
    
    
    return 0;
}