#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int parent[MAX];
vector<pair<int, int>> x;
vector<pair<int, int>> y;
vector<pair<int, int>> z;

vector<pair<int, pair<int, int>>> len;

int Find_Parent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = Find_Parent(parent[x]);
}

void Union(int x, int y) {
	x = Find_Parent(x);
	y = Find_Parent(y);

	if (x == y) return;
	parent[y] = x;
}

bool Same_Parent(int x, int y) {
	x = Find_Parent(x);
	y = Find_Parent(y);

	if (x == y) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a, i });
		y.push_back({ b, i });
		z.push_back({ c, i });
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	for (int i = 0; i < n - 1; i++) {
		len.push_back({ abs(x[i].first - x[i + 1].first), {x[i].second, x[i + 1].second} });
		len.push_back({ abs(y[i].first - y[i + 1].first), {y[i].second, y[i + 1].second} });
		len.push_back({ abs(z[i].first - z[i + 1].first), {z[i].second, z[i + 1].second} });
	}

	sort(len.begin(), len.end());

	int cnt = 0;
	int ans = 0;

	for (int i = 0; i < len.size(); i++) {
		int a = len[i].second.first;
		int b = len[i].second.second;
		int x = len[i].first;

		if (!Same_Parent(a, b)) {
			Union(a, b);
			ans += x;
		}
	}

	cout << ans;

	return 0;
}