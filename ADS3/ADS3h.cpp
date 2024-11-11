#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> blockSizes(M);
    vector<int> prefixSum(M);
    
    // Read block sizes and calculate prefix sums
    for (int i = 0; i < M; ++i) {
        cin >> blockSizes[i];
        prefixSum[i] = blockSizes[i] + (i == 0 ? 0 : prefixSum[i - 1]);
    }

    // Process each mistake
    for (int i = 0; i < N; ++i) {
        int mistakeLine;
        cin >> mistakeLine;

        // Binary search to find the block containing the mistakeLine
        int low = 0, high = M - 1, blockIndex = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mistakeLine <= prefixSum[mid]) {
                blockIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Output the block number (1-indexed)
        cout << blockIndex + 1 << endl;
    }

    return 0;
}
