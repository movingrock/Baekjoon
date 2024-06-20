#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << "\n";
    string sa, sb;
    sa = to_string(a);
    sb = to_string(b);
    cout << stoi(sa + sb) - c;
    return 0;
}