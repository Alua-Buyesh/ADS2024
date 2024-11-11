#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int minLength = INT_MAX;  // To store the minimum length of subarray
    int currentSum = 0;       // To store the current sum of the window
    int start = 0;

    // Sliding window
    for (int end = 0; end < n; ++end) {
        currentSum += arr[end];

        // Shrink the window from the left as long as the sum is greater than or equal to k
        while (currentSum >= k) {
            minLength = min(minLength, end - start + 1);
            currentSum -= arr[start];
            start++;
        }
    }

    // Output the result
    if (minLength == INT_MAX) {
        cout << 0 << endl;  // If no subarray meets the condition, return 0 (although in the given input it seems at least one subarray always exists)
    } else {
        cout << minLength << endl;
    }

    return 0;
}
