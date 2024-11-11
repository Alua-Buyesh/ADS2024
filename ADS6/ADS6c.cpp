#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    int minDiff = INT_MAX;
    vector<pair<int, int>> result;

    for (int i = 1; i < n; i++) {
        int diff = points[i] - points[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
            result.clear();
            result.push_back({points[i - 1], points[i]});
        } else if (diff == minDiff) {
            result.push_back({points[i - 1], points[i]});
        }
    }

    for (auto p : result) {
        cout << p.first << " " << p.second << " ";
    }

    return 0;
}