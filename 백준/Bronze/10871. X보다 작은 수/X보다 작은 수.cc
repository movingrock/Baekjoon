#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        if(num < x) cout << num << " ";
    }
    return 0;
}