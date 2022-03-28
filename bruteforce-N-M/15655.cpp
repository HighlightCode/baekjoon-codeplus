#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int>& n) {
	using iter = vector<int>::iterator;
	for (iter it = n.begin(); it < n.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";
}

void print_nm(vector<bool>& n, int m, int count, int depth, vector<int>& tmp_print, vector<int>& int_arr) {
	if (count == m) {
		print(tmp_print);
	}
	else {
		for (int i = depth; i < n.size(); i++) {
			if (n[i] == false) {
				n[i] = true;
				tmp_print.push_back(int_arr[i]);
				print_nm(n, m, count + 1, i, tmp_print, int_arr);
				n[i] = false;
				tmp_print.pop_back();
			}
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
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		arr.push_back(k);
		print_n.push_back(false);
	}
	sort(arr.begin(), arr.end());

	print_nm(print_n, m, 0, 0, tmp, arr);
}