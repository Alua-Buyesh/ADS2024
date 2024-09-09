#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
    deque<int> dek; 
    vector<int> arr;  
    bool work = true;

    while (work) {
        char a;
        int b;
        cin >> a;
        
        if (a == '!') {
            work = false;  
        } else if (a == '+') {
            cin >> b;
            dek.push_front(b); 
        } else if (a == '-') {
            cin >> b;
            dek.push_back(b);   
        } else if (dek.size()>=2 && a == '*') {
            int f = dek.front();
            int l = dek.back();
            arr.push_back(f + l); 
            dek.pop_back();       
            dek.pop_front();       
        }else if(dek.size()==1 && a== '*'){
            int m= dek.front()*2;
            arr.push_back(m);
            dek.pop_back();
        } else if (dek.empty() && a == '*') {
            arr.push_back(1999);
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        if(arr[i]==1999){
            cout<< "error"<<endl;
        } else{
            cout << arr[i] << endl;
        }
        
    }


    return 0;
}
