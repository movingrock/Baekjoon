#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    getline(cin,str);
    
    if(str.empty()) {cout << 0; return 0;}
    
    int cnt = 1;
    for(int i = 0; i<str.length(); i++){
        if(str[i] == ' ') cnt++;
    }
    if(str[0] == ' ') cnt--;
    if(str[str.length()-1] == ' ') cnt--;
    
    cout << cnt;
    
    return 0;
}