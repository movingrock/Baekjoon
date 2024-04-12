#include <iostream>

using namespace std;

int arr[10001];

void postOrder(int start, int end) {
	if (start >= end) return;
	
	int root = arr[start];
	int idx = start + 1;

	while (idx < end) {
		if (root < arr[idx]) break; // 루트보다 큰 값을 찾으면 종료 그 지점을 나눠줌.
		idx++;
	}

	postOrder(start + 1, idx);
	postOrder(idx, end);
	cout << root << "\n";
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	int cnt = 0;
	while (cin >> n) {
		arr[cnt++] = n;
	}

	postOrder(0, cnt);

	return 0;
}