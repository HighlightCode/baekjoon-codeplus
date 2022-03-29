#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;

vector<string> calculate_condition(vector<char>& con, int n) {
	vector<string> result;
	vector<bool> p_number;
	for (int i = 0; i < 10; i++) {
		if (i < n)
			p_number.push_back(false);
		else
			p_number.push_back(true);
	}

	do {
		vector<int> number;
		for (int i = 0; i < 10; i++) {
			if (p_number[i] == false) {
				number.push_back(i);
			}
		}
		do {
			bool cal = true;
			for (int i = 0; i < n - 1; i++) {
				if (con[i] == '<') {
					if (number[i] > number[i + 1]) {
						//cout << '<';
						cal = false;
						break;
					}
				}
				else {
					if (number[i] < number[i + 1]) {
						//cout << '>';
						cal = false;
						break;
					}
				}
			}
			if (cal == true) {
				stringstream tmp;
				copy(number.begin(), number.end(), ostream_iterator<int>(tmp, ""));
				string n = tmp.str();
				result.push_back(n);
				//cout << n << endl;
			}
		} while (next_permutation(number.begin(), number.end()));
	} while (next_permutation(p_number.begin(), p_number.end()));

	return result;
}


int main() {
	int n;
	cin >> n;

	vector<char> char_container;
	for (int i = 0; i < n; i++) {
		char k;
		cin >> k;
		char_container.push_back(k);
	}
	vector<string> result = calculate_condition(char_container, n + 1);
	sort(result.begin(), result.end());

	cout << result.back() << endl;
	cout << result.front() << endl;
	return 0;

}