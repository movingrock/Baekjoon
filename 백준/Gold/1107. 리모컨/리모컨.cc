#include <iostream>
#include <string>

using namespace std;

bool arr[10] = { 0, };

bool diff(int n) {
    string str = to_string(n);
    for (int i = 0; i < str.length(); i++) {
        if (arr[str[i] - '0'] == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 10; i++) {
        arr[i] = true;
    }

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        arr[num] = false;
    }

    int cnt = abs(n - 100);

    for (int i = 0; i < 1000000; i++) {
        if (diff(i) == true) {
            cnt = min(cnt, (int)(abs(n - i) + to_string(i).length()));
        }
    }

    cout << cnt;

    return 0;
}