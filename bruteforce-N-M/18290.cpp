#include <iostream>
#include <vector>
#include <numeric>
#include <limits.h>
#include <algorithm>
using namespace std;

int print(vector<int>& n, vector<int>& arr) {
	static auto arr_plus = [arr](int a, int b) mutable {
		return a + arr[b];
	};
	int result = accumulate(n.begin(), n.end(), 0, arr_plus);
	return result;
}

bool is_next_arr(int i, int row, int col, vector<int>& tmp_print) {
	using iter = vector<int>::const_iterator;
	for (iter it = tmp_print.begin(); it != tmp_print.end(); it++) {
		if ((abs(((*it) / row) - (i / row)) == 1) && (((*it) % col) - (i % col)) == 0)
			return true;
		else if ((abs(((*it) % col) - (i % col)) == 1) && (((*it) / row) - (i / row)) == 0)
			return true;
	}
	return false;
}

void print_nm(vector<bool>& n, int row, int col, int k, int count, int depth, vector<int>& tmp_print, vector<int>& int_arr, int& max_num) {
	if (count == k) {
		max_num = max(max_num, print(tmp_print, int_arr));
	}
	else {
		for (int i = depth; i < n.size(); i++) {
			if (!is_next_arr(i, row, col, tmp_print)) {
				n[i] = true;
				tmp_print.push_back(i);
				print_nm(n, row, col, k, count + 1, i+1, tmp_print, int_arr, max_num);
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

	int n, m, k;
	int max_num = INT_MIN;
	cin >> n >> m >> k;
	vector<bool> print_n;
	vector<int> tmp;
	vector<int> arr;
	for (int i = 0; i < n*m; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
		print_n.push_back(false);
	}

	print_nm(print_n, n, m, k, 0, 0, tmp, arr, max_num);

	cout << max_num << endl;
}