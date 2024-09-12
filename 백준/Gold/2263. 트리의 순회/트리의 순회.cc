#include <iostream>

#define MAX 100001

using namespace std;

int index[MAX];
int inorder[MAX];
int postorder[MAX];

void preorder(int instart, int inend, int poststart, int postend) {

	if (instart > inend || poststart > postend) return;

	int root = postorder[postend];
	int rootIndex = index[root];
	int left = rootIndex - instart;
	int right = inend - rootIndex;

	cout << root << " ";

	preorder(instart, rootIndex - 1, poststart, poststart + left - 1);
	preorder(rootIndex + 1, inend, poststart + left, postend - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		index[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}

	preorder(0, n-1, 0, n-1);

	return 0;
}