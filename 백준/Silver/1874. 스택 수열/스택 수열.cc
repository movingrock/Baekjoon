#include <iostream>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	stack<int> s;
	queue<char> ans;
	int arr[100000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	int pushNum = 1; // 현재 넣을 숫자
	bool isNo = false;
	while (true) {
		if (pushNum <= n && (s.empty() || s.top() < arr[cnt])) {
			for (int i = pushNum; i <= arr[cnt]; i++) {
				s.push(i);
				ans.push('+');
			}
			pushNum = arr[cnt] + 1;

		}
		else if (s.top() == arr[cnt]) {
			s.pop();
			cnt++;
			ans.push('-');
		}
		else if (arr[cnt] < s.top()) {
			isNo = true;
			break;
			
		}

		if (cnt == n) {
			break;
		}
	}

	if (isNo) cout << "NO";
	else {
		while (!ans.empty()) {
			cout << ans.front() << "\n";
			ans.pop();
		}
	}

	return 0;
}