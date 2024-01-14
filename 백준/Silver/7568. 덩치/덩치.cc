#include <iostream>
#include <algorithm>

using namespace std;

class Person {
public:
	int height;
	int weight;

	int ranking = 1;
};

int main() {
	int n;
	cin >> n;
	Person p[50];
	for (int i = 0; i < n; i++) {
		cin >> p[i].weight >> p[i].height;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i].height < p[j].height && p[i].weight < p[j].weight) p[i].ranking++;
		}
	}



	for (int i = 0; i < n; i++) {
		cout << p[i].ranking << " ";
	}
	return 0;
}