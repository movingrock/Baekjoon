#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[9];
    for (int i = 1; i <= 8; i++) {
        cin >> arr[i];
    }

    bool isascending = true;
    bool isdescnding = true;

    for (int i = 1; i <= 8; i++) {
        if (i != arr[i]) isascending = false;
        if (i != 9 - arr[i]) isdescnding = false;
    }

    if (isascending) cout << "ascending";
    else if (isdescnding) cout << "descending";
    else cout << "mixed";

    return 0;
}