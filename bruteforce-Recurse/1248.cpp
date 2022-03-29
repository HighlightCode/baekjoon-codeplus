#include <iostream>
#include <vector>

using namespace std;

bool row_check(vector<int>& row, vector<char>& char_sign, int n) {
	int ans = 0;
	for (int i = n - row.size(), j = row.size() - 1 ; i < n ; i++, j--) {
		ans += row[j];
		if (char_sign[i] == '+') {
			if (ans <= 0) {
				return false;
			}
		}
		else if (char_sign[i] == '-') {
			if (ans >= 0) {
				return false;
			}
		}
		else {
			if (ans != 0)
				return false;
		}
	}

	return true;
}

bool go(vector<vector<char>>& matrix, int n, int depth, vector<int>& result) {
	if (result.size() == n && depth == n + 1) {
		return true;
	}
	if (matrix[n - depth][n - depth] == '0') {
		result.push_back(0);
		if (row_check(result, matrix[n - depth], n)) {
			if (go(matrix, n, depth + 1, result))
				return true;
		}
		result.pop_back();
	}
	else if (matrix[n - depth][n - depth] == '+') {
		for (int i = 1; i <= 10; i++) {
			result.push_back(i);
			if (row_check(result, matrix[n - depth], n)) {
				//cout << "plus__" << "depth : "<< depth << endl;
				if (go(matrix, n, depth + 1, result))
					return true;
			}
			result.pop_back();
		}
	}
	else {
		for (int i = -10 ; i < 0; i++) {
			result.push_back(i);
			if (row_check(result, matrix[n - depth], n)) {
				if (go(matrix, n, depth + 1, result))
					return true;
			}
			result.pop_back();
		}
	}
	return false;
}

int main() {
	int n;
	vector<vector<char>> matrix;
	vector<int> result;
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		vector<char> tmp;
		for (int j = 0; j < i; j++) {
			tmp.push_back('X');
		}
		for (int j = 0; j < n - i; j++) {
			char k;
			cin >> k;
			tmp.push_back(k);
		}
		matrix.push_back(tmp);
	}


	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}*/

	go(matrix, n, 1, result);

	for (int i = result.size() -1; i >= 0 ; i--) {
		cout << result[i] << " ";
	}
}