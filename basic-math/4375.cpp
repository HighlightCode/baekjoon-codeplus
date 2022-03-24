#include <iostream>

using namespace std;

int return_max(int n) {
	long long val = 1;
	int length = 1;

	while (val % n != 0) {
		val *= 10;
		val += 1;
		val %= n;
		length += 1;
	}

	return length;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n;
	while ( cin >> n) {

		cout << return_max(n) << endl;
	}

}