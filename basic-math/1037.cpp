#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> input_val;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		input_val.push_back(k);
	}

	sort(input_val.begin(), input_val.end());
	cout << (input_val.front() * input_val.back()) << endl;
}