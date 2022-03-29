#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[21][21];
int back(int index, vector<int>& first, vector<int>& second) {
    if (index == n + 1) {
        if (first.size() < 1) return -1;
        if (second.size() < 1) return -1;
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < first.size(); i++) {
            for (int j = 0; j < first.size(); j++) {
                if (i == j) continue;
                t1 += arr[first[i]][first[j]];
            }
        }
        for (int i = 0; i < second.size(); i++) {
            for (int j = 0; j < second.size(); j++) {
                if (i == j) continue;
                t2 += arr[second[i]][second[j]];
            }
        }
        int diff = abs(t1 - t2);
        return diff;
    }
    int ans = -1;
    first.push_back(index);
    int x = back(index + 1, first, second);
    if (ans == -1 || (x != -1 && x < ans)) {
        ans = x;
    }
    first.pop_back();
    second.push_back(index);
    int y = back(index + 1, first, second);
    if (ans == -1 || (y != -1 && y < ans)) {
        ans = y;
    }
    second.pop_back();
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<int> first, second;
    cout << back(1, first, second);
}