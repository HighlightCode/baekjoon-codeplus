#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int digit_count(int num) {

	int number_digit = 0;

	while (num > 0) {
		number_digit += 1;
		num /= 10;
	}

	return number_digit;
}


int main() {
	int k;
	cin >> k;

	//cout << digit_count(k);
	int d_number = digit_count(k);

	int result = 0;
	for (int i = 1; i <= d_number - 1; i++) {
		result += i * 9 * static_cast<int>(pow(10, i - 1));
	}
	result += d_number * (k - pow(10, d_number - 1) + 1);
	cout << result << endl;
}