#include <iostream>
#include <string>

using namespace std;

bool checkstr(const string& A, const string& B) {
    int n = A.size();
    int m = B.size();
    
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && A[i + j] == B[j]) {
            j++;
        }
        if (j == m) {
            return true;
        }
    }
    return false;
}

int main() {
    string A, B;
    cin >> A >> B;

    if (checkstr(A, B)) {
        cout << 1 << endl;
        return 0;
    }

    string repeatedA = A;
    int t = 1;

    while (repeatedA.size() < B.size() + A.size()) {
        repeatedA += A;
        t++;
        if (checkstr(repeatedA, B)) {
            cout << t << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
