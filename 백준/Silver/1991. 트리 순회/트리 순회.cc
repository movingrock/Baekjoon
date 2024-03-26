#include <iostream>

using namespace std;

int n;

struct Node {
    char data;
    char left;
    char right;
};

Node node[27];

void preorder(char d) {
    if (d == '.') return;

    cout << d;
    preorder(node[d - 'A'].left);
    preorder(node[d - 'A'].right);
}

void inorder(char d) {
    if (d == '.') return;

    inorder(node[d - 'A'].left);
    cout << d;
    inorder(node[d - 'A'].right);
}

void postorder(char d) {
    if (d == '.') return;

    postorder(node[d - 'A'].left);
    postorder(node[d - 'A'].right);
    cout << d;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        char d, l, r;
        cin >> d >> l >> r;
        node[d - 'A'].data = d;
        node[d - 'A'].left = l;
        node[d - 'A'].right = r;
    }
    
    preorder('A'); cout << "\n";
    inorder('A'); cout << "\n";
    postorder('A');

    return 0;
}