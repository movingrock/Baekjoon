#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int n, m;
int destroyChicken;
int ans = INT_MAX;

bool visited[14] = { 0, };
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int chickenDistance() {
	int sum = 0;

	for (int i = 0; i < house.size(); i++) {
		int x = house[i].first;
		int y = house[i].second;
		int min_dis = INT_MAX;
		for (int j = 0; j < chicken.size(); j++) {
			if (visited[j]) continue;
			int a = chicken[j].first;
			int b = chicken[j].second;

			min_dis = min(min_dis, abs(x - a) + abs(y - b));
		}
		sum += min_dis;
	}

	return sum;
}

void backTracking(int index, int cnt) {
	if (cnt == destroyChicken) {
		ans = min(ans, chickenDistance());
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			backTracking(i, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (num == 1) house.push_back({ i, j });
			if (num == 2) chicken.push_back({ i, j });
		}
	}
	destroyChicken = chicken.size() - m;
	
	backTracking(0, 0);

	cout << ans;

	return 0;
}