#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    while(true){
        getline(cin, str);
        if(str == "") break;
        cout << str << "\n";
    }
    return 0;
}