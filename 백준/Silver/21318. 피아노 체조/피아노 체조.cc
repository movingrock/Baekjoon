#include <iostream>

#define MAX 100001

using namespace std;

int arr[MAX];
int error[MAX];
int prefixSum[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i + 1]) error[i] = 1;

		prefixSum[i] = prefixSum[i - 1] + error[i];
	}
	prefixSum[n] = prefixSum[n - 1];

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		if(error[y] == 1) cout << prefixSum[y] - prefixSum[x - 1] -1 << "\n";
		else cout << prefixSum[y] - prefixSum[x - 1] << "\n";
	}

	return 0;
}