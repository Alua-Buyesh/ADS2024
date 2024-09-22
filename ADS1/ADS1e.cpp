#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> bor, nur;
    int a, b = 0;

    for (int i = 0; i < 5; i++) {
        cin >> a;
        bor.push(a);
    }

    for (int i = 0; i < 5; i++) {
        cin >> a;
        nur.push(a);
    }

    while (!bor.empty() && !nur.empty() && b < 1000000) {
        b++; 
        if (bor.front() == 0 && nur.front() == 9) {
            int bor_card = bor.front();
            int nur_card = nur.front();
            bor.pop();
            nur.pop();
            bor.push(bor_card);
            bor.push(nur_card);
        } else if (bor.front() == 9 && nur.front() == 0) {
            int bor_card = bor.front();
            int nur_card = nur.front();
            bor.pop();
            nur.pop();
            nur.push(bor_card);
            nur.push(nur_card);
        } else if (bor.front() > nur.front()) {
            int bor_card = bor.front();
            int nur_card = nur.front();
            bor.pop();
            nur.pop();
            bor.push(bor_card); 
            bor.push(nur_card);
        } else {
            int bor_card = bor.front();
            int nur_card = nur.front();
            bor.pop();
            nur.pop();
            nur.push(bor_card);  
            nur.push(nur_card);
        }
    }

    if (!bor.empty() && nur.empty()) {
        cout << "Boris " << b;
    } else if (!nur.empty() && bor.empty()) {
        cout << "Nursik " << b;
    } 

    return 0;
}
