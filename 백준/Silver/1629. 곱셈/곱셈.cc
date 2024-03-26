#include <iostream>

using namespace std;

long long a, b, c, k;

long long func(long long b) {
    if (b == 0) return 1;
    if (b == 1) return a % c;

    k = func(b / 2) % c;
    if (b % 2 == 0) return k * k % c;
    return k * k % c * a % c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    cout << func(b);

    return 0;
}