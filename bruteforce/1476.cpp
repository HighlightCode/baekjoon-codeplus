#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cal(int x, int y, int z) {
	int result = 1;
	for(;;) {
		if ((result - x) % 15 == 0 && (result - y) % 28 == 0 && (result - z) % 19 == 0)
			break;
		else if ((result - y) != 0)
			result += 1;
		else
			result += 28;
	}

	return result;
}


int main() {
	int n, m, k;
	cin >> n >> m >> k;

	cout << cal(n, m, k) << endl;

}