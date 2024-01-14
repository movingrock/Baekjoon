#include <iostream>
#include <algorithm>

using namespace std;

class User {
public:
	int age;
	string name;

	int join;
};

int cmp(User u1, User u2) {
	if (u1.age != u2.age) return u1.age < u2.age;
	else return u1.join < u2.join;
}

User user[100000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> user[i].age >> user[i].name;
		user[i].join = i;
	}
	
	sort(user, user + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << user[i].age << " " << user[i].name << "\n";
	}

	return 0;
}