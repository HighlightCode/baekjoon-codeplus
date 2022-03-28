#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Password {
	Password(int n, int m): n(n),m(m) {
		for (int i = 0; i < m; i++) {
			if (i < n) {
				permute.push_back(false);
			}
			else {
				permute.push_back(true);
			}
		}
	}

	void push(char k) {
		alps.push_back(k);
	}

	void sort() {
		std::sort(alps.begin(), alps.end());
		using iter = vector<char>::const_iterator;
		int i = 0;
		for (iter it = alps.begin(); it != alps.end(); it++) {
			if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u')
				vowels[i] = true;
			i++;
		}
	}

	bool next() {
		if (check())
			print();
		if (std::next_permutation(permute.begin(), permute.end()))
			return true;
		else
			return false;
	}

	bool check() {
		int v_tmp = 0;
		int c_tmp = 0;
		using iter = vector<bool>::const_iterator;
		int i = 0;

		for (iter it = permute.begin(); it != permute.end(); it++) {
			if (*it == false) {
				if (vowels[i] == true)
					v_tmp += 1;
				else
					c_tmp += 1 ;
			}
			i++;
		}

		if (v_tmp >= 1 && c_tmp >= 2)
			return true;
		else
			return false;
	}

	void print() {
		for (int i = 0; i < m; i++) {
			if (permute[i] == 0) {
				cout << alps[i];
			}
		}
		cout << endl;
	}

	void print_all() {
		for (int i = 0; i < m; i++) {
			cout << alps[i];
		}
		cout << endl;
	}

private:
	int n, m;
	vector<char> alps;
	vector<bool> permute;
	int vowels[15] = { 0, };
};

int main() {
	int n, m;
	cin >> n >> m;

	Password password(n, m);

	for (int i = 0; i < m; i++) {
		char k;
		cin >> k;
		password.push(k);
	}

	password.sort();
	//password.print_all ();


	while (true) {
		if (!password.next()) {
			break;
		}
	}

	return 0;
}