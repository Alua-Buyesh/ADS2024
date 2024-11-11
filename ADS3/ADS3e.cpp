#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

// Function to check if a square of side length L can cover at least K rectangles
bool canCover(int L, const vector<Rectangle>& rectangles, int K) {
    int count = 0;
    for (const auto& rect : rectangles) {
        if (rect.x2 <= L && rect.y2 <= L) {
            count++;
        }
        if (count >= K) {
            return true;
        }
    }
    return count >= K;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<Rectangle> rectangles(N);

    int maxCoord = 0;
    for (int i = 0; i < N; ++i) {
        cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2;
        maxCoord = max(maxCoord, max(rectangles[i].x2, rectangles[i].y2));
    }

    int low = 1, high = maxCoord, answer = high;

    // Binary search to find the minimum side length L
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canCover(mid, rectangles, K)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}
