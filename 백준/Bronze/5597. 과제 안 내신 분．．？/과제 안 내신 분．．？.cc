#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool arr[31] = {0, };
    for(int i = 0; i<28; i++){
        int num;
        cin >> num;
        arr[num] = 1;
    }
    for(int i = 1; i<=30; i++){
        if(arr[i] == 0) cout << i << "\n";
    }
    return 0;
}