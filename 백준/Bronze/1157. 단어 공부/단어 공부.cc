#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num_of_alphabet[26] = {0,}; //0~25 A~Z
    string str;
    cin >> str;
    
    for(int i = 0; i<str.length(); i++){
        if((int)str[i] >= 65 && (int)str[i] <=90) num_of_alphabet[(int)str[i] - 65]++;
        else if((int)str[i] >= 97 && (int)str[i] <=122) num_of_alphabet[(int)str[i] - 97]++;
    }
    
    int max_cnt = -1;
    char max_alpha = ' ';
    for(int i = 0; i<26; i++){
        max_cnt = max(max_cnt, num_of_alphabet[i]);
        if(max_cnt == num_of_alphabet[i]) max_alpha = (char)(i+65);
    }
    
    int cnt = 0;
    for(int i = 0; i<26; i++){
        if(max_cnt == num_of_alphabet[i]) cnt++;
    }
    
    if(cnt > 1) cout << "?";
    else cout << max_alpha;

    return 0;
}