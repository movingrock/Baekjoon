#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int parent[1000001];

int find(int a)
{
	if (parent[a] == a)
		return a;

	return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
	a = find(parent[a]);
	b = find(parent[b]);

	if (a != b)
	{
		if (a >= b)
			parent[a] = b;
		else
			parent[b] = a;
	}
}

bool SameParent(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		parent[i] = i;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (SameParent(a, b))
		{
			cout << i + 1;
			return 0;
		}
		Union(a, b);
	}
	cout << "0";

	return 0;
}