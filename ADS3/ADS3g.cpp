#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDeliverWithCapacity(long long capacity, const vector<int>& gifts, long long f) {
    long long flights = 0;
    for (int gift : gifts) {
        flights += (gift + capacity - 1) / capacity; // Equivalent to ceil(gift / capacity)
        if (flights > f) {
            return false; // If flights exceed f, it's not feasible
        }
    }
    return flights <= f;
}

int main() {
    int n;
    long long f;
    cin >> n >> f;

    vector<int> gifts(n);
    int maxGifts = 0;
    for (int i = 0; i < n; ++i) {
        cin >> gifts[i];
        maxGifts = max(maxGifts, gifts[i]);
    }

    long long low = 1, high = maxGifts, answer = high;

    // Binary search to find the minimum capacity
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canDeliverWithCapacity(mid, gifts, f)) {
            answer = mid;
            high = mid - 1; // Try to minimize the capacity
        } else {
            low = mid + 1; // Increase the capacity
        }
    }

    cout << answer << endl;
    return 0;
}
