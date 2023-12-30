#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; string str;
    cin >> n >> str;
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += (int)(str[i] - '0');
    }

    cout << sum;
    
    return 0;
}