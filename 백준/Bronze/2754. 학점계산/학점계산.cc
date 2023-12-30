#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    double score = 0;
    if(str[0] == 'A') score = 4.0;
    else if(str[0] == 'B') score = 3.0;
    else if(str[0] == 'C') score = 2.0;
    else if(str[0] == 'D') score = 1.0;
    else score = 0.0;
    
    if(str[1] == '+') score += 0.3;
    else if(str[1] == '-') score -= 0.3;
    cout << fixed;
    cout.precision(1);
    cout << score;
    return 0;
}