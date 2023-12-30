#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int i = 0; i<t; i++){
        string str;
        cin >> str;
        cout << str[0] << str[str.length()-1] << "\n";
    }
    return 0;
}