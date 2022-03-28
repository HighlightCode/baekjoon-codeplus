#include <iostream>
#include <vector>
using namespace std;

void print(vector<bool>& n) {
	using iter = vector<bool>::iterator;
	int i = 1;
	for (iter it = n.begin(); it < n.end(); it++) {
		if (*it == true)
			cout << i << " ";
		i++;
	}
	cout << "\n";
}

void print_nm(vector<bool>& n, int m, int count, int depth) {
	if (count == m) {
		print(n);
	}
	else {
		if (depth < n.size()) {
			n[depth] = true;
			print_nm(n, m, count + 1, depth + 1);
			n[depth] = false;
			print_nm(n, m, count, depth + 1);
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<bool> print_n;
	for (int i = 0; i < n; i++) {
		print_n.push_back(false);
	}

	print_nm(print_n, m, 0, 0);
}