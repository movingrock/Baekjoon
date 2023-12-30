#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sum =0;
    for(int i = 0; i<5; i++){
        int num;
        cin >> num;
        sum += num*num;
    }
    cout << sum % 10;
    return 0;
}