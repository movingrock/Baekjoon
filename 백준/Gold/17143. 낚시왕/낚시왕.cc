#include <iostream>
#include <vector>

using namespace std;

struct Shark {
	int r;
	int c;
	int s;
	int d;
	int z;
};

vector<Shark> shark[102][102];
int R, C, M;
int r, c, s, d, z;
int answer = 0;

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

bool InRange(int x, int y) {
	return x >= 1 && x <= R && y >= 1 && y <= C;
}

// 모든 상어가 1초동안 움직인거
void Move() {
	vector<Shark> copy[102][102];
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (shark[i][j].empty()) continue;
			int nr = shark[i][j][0].r;
			int nc = shark[i][j][0].c;
			int ns = shark[i][j][0].s;
			int nd = shark[i][j][0].d;
			int nz = shark[i][j][0].z;
			
			int cnt = ns;
			while (cnt--) {
				if (InRange(nr + dx[nd], nc + dy[nd])) {
					nr += dx[nd];
					nc += dy[nd];
					//cout << "dd" << endl;
				}
				else {
					if (nd == 1) nd = 2;
					else if (nd == 2) nd = 1;
					else if (nd == 3) nd = 4;
					else if (nd == 4) nd = 3;
					//cout << "hello" << endl;
					nr += dx[nd];
					nc += dy[nd];
				}
			}
			if(copy[nr][nc].empty()) copy[nr][nc].push_back({ nr, nc, ns, nd, nz });
			else {
				if (copy[nr][nc][0].z < nz) {
					copy[nr][nc].clear();
					copy[nr][nc].push_back({ nr, nc, ns, nd, nz });
				}
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			shark[i][j] = copy[i][j];
		}
	}
}

void Catch(int p) {
	for (int i = 1; i <= R; i++) {
		if (!shark[i][p].empty()) {
			answer += shark[i][p].front().z;
			shark[i][p].clear();
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2) s %= ((R - 1) * 2);
		if (d == 3 || d == 4) s %= ((C - 1) * 2);
		shark[r][c].push_back({ r,c,s,d,z });
	}

	int p = 0;
	while (++p <= C) {
		Catch(p);
		Move();
	}

	cout << answer;

	return 0;
}