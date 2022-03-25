#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

enum class row_or_col {
	ROW,
	COL,
	NOT_CHANGE,
};

int count(char** arr, row_or_col x,int row, pair<int,int> num, int n) {
	int count = 1;
	int cur = 0;
	if (x == row_or_col::ROW) {
		swap(arr[row][num.first], arr[row][num.second]);
		count = 1;
		cur = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i][num.first] == arr[i - 1][num.first])
				count += 1;
			else {
				cur = max(count, cur);
				count = 1;
			}
		}
		cur = max(count, cur);
		count = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i][num.second] == arr[i - 1][num.second])
				count += 1;
			else {
				cur = max(count, cur);
				count = 1;
			}
		}
		cur = max(count, cur);
		count = 1;
		for (int i = 1; i < n; i++) {
			if (arr[row][i-1] == arr[row][i])
				count += 1;
			else {
				cur = max(count, cur);
				count = 1;
			}
		}
		swap(arr[row][num.first], arr[row][num.second]);
		cur = max(count, cur);
	}
	else if(x == row_or_col::COL){
		swap(arr[num.first][row], arr[num.second][row]);
		count = 1;
		cur = 0;
		for (int i = 1; i < n; i++) {
			if (arr[num.first][i] == arr[num.first][i - 1])
				count += 1;
			else {
				cur = max(count, cur);
				count = 1;
			}
		}
		cur = max(count, cur);
		count = 1;
		for (int i = 1; i < n; i++) {
			if (arr[num.second][i] == arr[num.second][i - 1])
				count += 1;
			else {
				cur = max(count, cur);
				count = 1;
			}
		}
		cur = max(count, cur);
		count = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i - 1][row] == arr[i][row])
				count += 1;
			else {
				cur = max(count, cur);
				count = 1;
			}
		}
		cur = max(count, cur);
		swap(arr[num.first][row], arr[num.second][row]);
	}
	else {
		count = 1;
		cur = 0;
		//row 세기
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (arr[i][j - 1] == arr[i][j])
					count += 1;
				else {
					cur = max(count, cur);
					count = 1;
				}
			}
			cur = max(count, cur);
			count = 1;
		}
		//col 세기
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (arr[j-1][i] == arr[j][i])
					count += 1;
				else {
					cur = max(count, cur);
					count = 1;
				}
			}
			cur = max(count, cur);
			count = 1;
		}
	}
	return cur;
}


int main() {
	int n;
	cin >> n;

	char** arr = new char*[n];

	for (int i = 0; i < n; i++) {
		arr[i] = new char[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}*/

	int max_count = 0;
	// no change
	max_count = max(max_count, count(arr, row_or_col::NOT_CHANGE, 0, make_pair(0, 0), n));
	// row 바꾸기.
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j] != arr[i][j-1])
				max_count = max(max_count, count(arr, row_or_col::ROW, i, make_pair(j - 1, j), n));
		}
	}
	// col 바꾸기.
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i - 1][j] != arr[i][j])
				max_count = max(max_count, count(arr, row_or_col::COL, j, make_pair(i - 1, i), n));
		}
	}

	cout << max_count << endl;
}