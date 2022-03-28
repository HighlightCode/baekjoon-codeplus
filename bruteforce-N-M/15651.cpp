#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& n) {
	using iter = vector<int>::iterator;
	for (iter it = n.begin(); it < n.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";
}

void print_nm(vector<bool>& n, int m, int count, vector<int>& tmp_print) {
	if (count == m) {
		print(tmp_print);
	}
	else {
		for (int i = 0; i < n.size(); i++) {
			n[i] = true;
			tmp_print.push_back(i + 1);
			print_nm(n, m, count + 1, tmp_print);
			n[i] = false;
			tmp_print.pop_back();
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
	vector<int> tmp;
	for (int i = 0; i < n; i++) {
		print_n.push_back(false);
	}

	print_nm(print_n, m, 0, tmp);
}