#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> powers(N);
    for (int i = 0; i < N; ++i) {
        cin >> powers[i];
    }

    // Sort the competitors' powers for efficient querying
    sort(powers.begin(), powers.end());

    // Create a prefix sum array for fast power summation
    vector<long long> prefixSum(N);
    prefixSum[0] = powers[0];
    for (int i = 1; i < N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + powers[i];
    }

    int P;
    cin >> P;
    while (P--) {
        int M;
        cin >> M;

        // Find the number of competitors Mark can defeat using upper_bound
        auto it = upper_bound(powers.begin(), powers.end(), M);
        int count = it - powers.begin();

        // Calculate the sum of defeated competitors' powers
        long long sum = (count > 0) ? prefixSum[count - 1] : 0;

        // Output the result for the current round
        cout << count << " " << sum << endl;
    }

    return 0;
}
