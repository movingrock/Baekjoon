#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		deque<int> dq;
		string p, x;
		int n;
		cin >> p >> n >> x;
		bool reverse = false;
		bool isError = false;
		int del_cnt = 0;
		string tmp = "";

		for (int i = 0; i < x.length(); i++) {
			if (x[i] == '[') continue;

			if (isdigit(x[i])) tmp += x[i];
			else if((x[i] == ']' || x[i] == ',') && tmp != "") {
				int num = stoi(tmp);
				//cout << "tmp: " << tmp << endl;
				dq.push_back(num);
				tmp = "";
			}
		}

		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				reverse = !reverse;
			}
			else if (p[i] == 'D') {
				if (dq.size() == 0) isError = true;
				else if (reverse) {
					dq.pop_back();
				}
				else {
					dq.pop_front();
				}
			}
		}

		deque<int> rdq;
		if (reverse) {
			int s = dq.size();
			for (int i = 0; i < s; i++) {
				rdq.push_back(dq.back());
				dq.pop_back();
			}


			for (int i = 0; i < s; i++) {
				dq.push_back(rdq.front());
				rdq.pop_front();
			}
		}

		if (isError) cout << "error\n";
		else {
			cout << "[";
			for (int i = 0; i < dq.size(); i++) {
				cout << dq[i];
				if (i != dq.size() - 1) cout << ",";
			}
			cout << "]\n";
		}
	}

	return 0;
}