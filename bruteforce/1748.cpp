#include <algorithm>
#include <iostream>

using namespace std;

int digit_count(int num) {

	int number_digit = 0;

	while (num > 10) {
		number_digit += 1;
		num %= 10;
	}

	return number_digit;
}


int main() {
	int k;
	cin >> k;


}