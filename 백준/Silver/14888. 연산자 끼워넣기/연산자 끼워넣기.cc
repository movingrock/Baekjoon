#include <iostream>
#include <climits>

using namespace std;

int max_ans = INT_MIN;
int min_ans = INT_MAX;
int n;
int arr[12];
int op[4];

int Calc(int cnt, int sum, int op) {
	if (op == 0) {
		if (cnt == 0) return arr[cnt] + arr[cnt + 1];
		else return sum + arr[cnt + 1];
	}
	else if (op == 1) {
		if (cnt == 0) return arr[cnt] - arr[cnt + 1];
		else return sum - arr[cnt + 1];
	}
	else if (op == 2) {
		if (cnt == 0) return arr[cnt] * arr[cnt + 1];
		else return sum * arr[cnt + 1];
	}
	else if (op == 3) {
		if (cnt == 0) return arr[cnt] / arr[cnt + 1];
		else return sum / arr[cnt + 1];
	}
}

void Func(int cnt, int sum) {
	if (cnt == n - 1) {
		max_ans = max(max_ans, sum);
		min_ans = min(min_ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] >= 1) {
			op[i]--;
			Func(cnt + 1, Calc(cnt, sum, i));
			op[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	Func(0, 0);
	cout << max_ans << "\n" << min_ans;

	return 0;
}
