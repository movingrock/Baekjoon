#include <iostream>
#include <vector>

#define INF 99999999

using namespace std;

int dist[501];
int tc, n, m, w, s, e, t;

vector<pair<pair<int, int>, int>> v;

bool bf() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v.size(); j++) {
			int start = v[j].first.first;
			int end = v[j].first.second;
			int cnt = v[j].second;

			if (dist[end] > dist[start] + cnt) dist[end] = dist[start] + cnt;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int start = v[i].first.first;
		int end = v[i].first.second;
		int cnt = v[i].second;

		if (dist[end] > dist[start] + cnt) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> tc;
	while (tc--) {
		v.clear();

		cin >> n >> m >> w;
		while (m--) {
			cin >> s >> e >> t;
			v.push_back(make_pair(make_pair(s, e), t));
			v.push_back(make_pair(make_pair(e, s), t));
		}
		while (w--) {
			cin >> s >> e >> t;
			v.push_back(make_pair(make_pair(s, e), -t));
		}

		if (bf()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}