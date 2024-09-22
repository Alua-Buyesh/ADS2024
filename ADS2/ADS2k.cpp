#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

void f(int n, vector<char>& stream){
    unordered_map<char, int> freq;
    list<char> r;

    for(int i = 0; i < n; ++i){
        char ch = stream[i];
        freq[ch]++;

        if(freq[ch] == 1){
            r.push_back(ch);
        }

        while(!r.empty() && freq[r.front()] > 1){
            r.pop_front();
        }

        if(!r.empty()){
            cout << r.front() << " ";
        }
        else{
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<char> stream(n);
        for(int i = 0; i < n; ++i){
            cin >> stream[i];
        }
        f(n, stream);
    }

    return 0;
}