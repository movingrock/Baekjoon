#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0;

vector<int> v;      // 입력값
vector<int> list;   // 순서대로 넣은 배열
int index[1000001]; // 값의 위치

int BinarySearch(int key) {
    int start = 0;
    int end = list.size() - 1;

    int mid;
    while (start < end) {
        mid = (start + end) / 2;

        if (key > list[mid]) {
            start = mid + 1;
        }
        else
            end = mid;
    }
    return end;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    // 입력받은 값을 순서대로
    // 만약 list배열이 비어있거나 마지막원소보다 작은값이면, 인덱스에 번호를 넣어주고 list에 삽입한다.
    // 마지막 원소보다 크거나 같다면, 이분탐색으로 list에 위치를 찾아서 값을 넣어준다.
    for (int i = 0; i < n; i++) {
        if (list.empty() || list.back() < v[i]) {
            index[i] = cnt;
            list.push_back(v[i]);
            cnt++;
        }
        else {
            int idx = BinarySearch(v[i]);
            list[idx] = v[i];
            index[i] = idx;
        }
    }
    
    // index에 기록된 순서대로 값을 빼서 출력한다.
    vector<int> tmp;
    int tCnt = cnt - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (index[i] == tCnt) {
            tmp.push_back(v[i]);
            tCnt--;
        }
    }

    cout << cnt << "\n";
    for (int i = tmp.size() - 1; i >= 0; i--) {
        cout << tmp[i] << " ";
    }

	return 0;
}