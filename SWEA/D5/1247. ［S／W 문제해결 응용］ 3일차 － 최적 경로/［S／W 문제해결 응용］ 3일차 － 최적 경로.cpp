#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<pair<int, int>> v;
int visited[11];
pair<int, int> company;
pair<int, int> home;
int min_dis = INT_MAX;

void dfs(int x, int y , int cnt, int sum) {
	if (cnt == n) {
		sum += abs(x - home.first) + abs(y - home.second);
		min_dis = min(min_dis, sum);
	}
	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(v[i].first, v[i].second, cnt+1, sum + abs(x - v[i].first) + abs(y - v[i].second));
			visited[i] = false;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		v.clear();
		min_dis = INT_MAX;

		int x, y;

		cin >> x >> y; company = { x, y };
		cin >> x >> y; home = { x, y };

		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back({ x, y });
		}

		dfs(company.first, company.second, 0, 0);
		
		cout << "#" << test_case << " " << min_dis << endl;
	
	}
	return 0;
}