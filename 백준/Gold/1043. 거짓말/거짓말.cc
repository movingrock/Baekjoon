#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> truth;
vector<int> party[51];
int parent[51];

// 그룹 번호 반환
int find_parent(int x) {
	if (x != parent[x]) return parent[x] = find_parent(parent[x]);
	else return parent[x];
}

// 같은 그룹으로 묶기
void merge(int x, int y) {
	int a = find_parent(x);
	int b = find_parent(y);

	if (a != b) {
		if (a < b) parent[b] = a;
		else parent[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, kp;
	cin >> n >> m >> kp;
	int ans = m;

	// 각자 초기 그룹갖기
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	// 진실 아는 사람 입력
	while (kp--) {
		int tp;
		cin >> tp;
		truth.push_back(tp);
	}

	// 파티별 참가한 사람 입력
	for (int i = 0; i < m; i++) {
		int num, p;
		cin >> num;

		while (num--) {
			cin >> p;
			party[i].push_back(p);
		}
	}

	// 같은 파티에 속해 있으면 묶어줌.
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < party[i].size(); j++) {
			merge(party[i][0], party[i][j]);
		}
	}

	// 각 파티별로, 파티에 참가한 사람와
	// 진실을 아는 사람이 같은 그룹에 속했는지 확인
	for (int i = 0; i < m; i++) {
		bool isStoryTrue = true;

		for (int j = 0; j < party[i].size(); j++) {
			if (isStoryTrue == false) break;
			int n1 = party[i][j]; // 파티별 참가한 사람

			for (int k = 0; k < truth.size(); k++) {
				int n2 = truth[k]; // 진실을 아는 사람
				if (find_parent(n1) == find_parent(n2)) { // 같은 그룹에 속했는지 확인
					isStoryTrue = false; // 같은 그룹에 있다면 거짓말을 못함
					break;
				}

			}
		}
		if (isStoryTrue == false) ans--;
	}

	cout << ans;


	return 0;
}