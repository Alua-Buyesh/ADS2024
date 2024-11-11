#include <iostream>

using namespace std;

int main(){
    string word, text;
    int n, k=0;
    cin >> word >> n >> text;

    for(int i=0; i<text.size()-word.size();i++){
        int j=0;
        while(j<word.size() && text[i+j]==word[j]){
            j++;
        }
        if(j==word.size()){
            k++;
        }
    }

    if(k==n){
        cout<< "YES";
    } else{
        cout << "NO";
    }
    
    return 0;
}