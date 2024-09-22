#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    deque<int> dek;
    for(int i=0; i<n; i++){
        for(int j=arr[i]; j>0; j--){
                dek.push_front(j);
                for(int k=0; k<j+1; k++){
                    int sw=dek.front();
                    dek.pop_front();
                    dek.push_back(sw);
                }
        }
        for (deque<int>::reverse_iterator itr = dek.rbegin(); itr != dek.rend(); ++itr) {
            cout << *itr << " ";
        }
        cout<< endl;
        dek.clear();
    }

}