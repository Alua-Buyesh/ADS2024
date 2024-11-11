#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

const long long MOD = 1e9 + 7;

long long calculateHash(const string &s) {
    long long hash = 0;
    long long power = 1;

    for (char c : s) {
        hash = (hash + (c - 47) * power) % MOD;
        power = (power * 11) % MOD;
    }

    return hash;
}

int main() {
    int N;
    cin >> N;

    unordered_map<long long, string> hashTable;
    vector<pair<string, long long> > output;

    for (int i = 0; i < 2 * N; ++i) {
        string input;
        cin >> input;

        if (std::isdigit(input[0])) { 
            long long hash = stoll(input);
            hashTable[hash] = "";  
        } else {
            long long hash = calculateHash(input);
            output.emplace_back(input, hash);
        }
    }

    for (const auto &pair : output) {
        cout << "Hash of string \"" << pair.first << "\" is " << pair.second << std::endl;
    }

    return 0;
}
