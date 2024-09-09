#include <iostream>
#include <vector>

using namespace std;

int main(){
    string a,b;
    cin>> a >> b;
    vector<char> a1;
    vector<char> b1;
    for(int i=0;i<a.size();i++){
        if(a[i]=='#'){
            a1.pop_back();
        }else {
            a1.push_back(a[i]);
        }
    }
    for(int i=0;i<b.size();i++){
        if(b[i]=='#'){
            b1.pop_back();
        }else {
            b1.push_back(b[i]);
        }
    }
    if(a1.size()==b1.size()){
        for(int i=0; i<a1.size();i++){
            if(a1[i]!=b1[i]){
                cout <<"NO";
                return 0;
            }
        }
        cout <<"Yes";
    } else{
        cout <<"No";
    }
}