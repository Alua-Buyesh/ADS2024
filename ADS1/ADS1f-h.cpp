#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n; 

    vector<int> primes; 
    vector<int> superPrimes; 
    int num = 2;

    while (superPrimes.size() < n) {
        if (isPrime(num)) {
            primes.push_back(num); 
            if (isPrime(primes.size())) {
                superPrimes.push_back(num);
            }
        }
        num++;  
    }

    cout << superPrimes[n - 1] << endl;

    return 0;
}
