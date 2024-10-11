#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

int n, m;

unordered_map<string, vector<pair<int, string>>> graph;
unordered_map<string, int> visited;

int file = 0, cnt = 0;


vector<string> parse(string s) {
	vector<string> v;
	istringstream iss(s);
	string stringbuffer;

	while (getline(iss, stringbuffer, '/')) {
		v.push_back(stringbuffer);
	}
	return v;
}

void dfs(string root) {
	for (int i = 0; i < graph[root].size(); i++) {
		if (graph[root][i].first == 0) {
			if (!visited[graph[root][i].second]) {
				visited[graph[root][i].second] = 1;
				file++;
			}
			cnt++;
		}
		else {
			dfs(graph[root][i].second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		string p, e;
		int c;
		cin >> p >> e >> c;
		vector<pair<int, string>> v = graph[p];
		v.push_back({ c, e });
		graph[p] = v;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		file = 0; cnt = 0;
		string query; cin >> query;
		vector<string> str = parse(query);
		dfs(str.back());
		cout << file << " " << cnt << "\n";
		visited.clear();
	}

	return 0;
}