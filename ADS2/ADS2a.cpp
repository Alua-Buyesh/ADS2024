#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    int k;
    cin>>k;
    int closest_d=10000;
    int pos;
    for(int i=0;i<n;i++){
        int m=abs(arr[i]-k);
        if(m<closest_d){
            closest_d=m;
            pos=i;
        }
    }
    cout << pos;
}