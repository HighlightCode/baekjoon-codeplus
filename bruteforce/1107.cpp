#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int check(int n, vector<bool>& n_pressed) {
	if (n == 0) {
		if (n_pressed[0] == 1) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int result = 0 ;
	while (n > 0) {
		if (n_pressed[n % 10])
			return 0;
		n /= 10;
		result += 1;
	}
	return result;
}


int main() {
	vector<bool> not_pressed(10);
	int n;
	cin >> n;

	int break_num = 0;
	cin >> break_num;
	for (int i = 0; i < break_num; i++) {
		int k;
		cin >> k;
		not_pressed[k] = true;
	}

	int min_press = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		int tmp = check(i, not_pressed);
		if (tmp > 0) {
			int press_number = abs(i - n);
			min_press = min(min_press, press_number + tmp);
		}
	}

	cout << min_press << endl;
}