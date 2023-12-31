#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, result;
    int arr[10] = { 0, };

    cin >> a >> b >> c;
    result = a * b * c;

    while (result > 0) {
        arr[result % 10]++;
        result /= 10;
    }

    for (int i = 0; i <= 9; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}