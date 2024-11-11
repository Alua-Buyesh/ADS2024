#include <iostream>

using namespace std;
void merge(char arr[], char left[], int leftsize, char right[], int rightsize,int start){
    int i=0, j=0,k=start;
    while(i< leftsize && j < rightsize){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
        } else{
            arr[k++]=right[j++];
        }
    }

    while(i<leftsize){
        arr[k++]=left[i++];
    }
    while(j<rightsize){
        arr[k++]=right[j++];
    }
}

void MegaSort(char arr[], int left, int right){
    if(left >= right){
        return;
    } 
    int mid = left + (right - left)/2;
    MegaSort(arr, left,mid);
    MegaSort(arr, mid + 1, right);
    char leftarr[mid-left+1]; char rightarr[right - mid];
    for(int i=0; i<= mid-left; i++){
        leftarr[i]=arr[left+i];
    }
    for(int i=0;i<right-mid;i++){
        rightarr[i]=arr[mid+i+1];
    }
    merge(arr,leftarr,mid-left+1,rightarr, right-mid, left);
}



int main(){
    int n, t=0,u=0;
    cin >> n;
    char arrV[n];
    char arrC[n];
    string s;
    cin >>s;
    for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u'){
            arrV[t++]=s[i];
        } else {
            arrC[u++]=s[i];
        }
        
    }
    MegaSort(arrV, 0, t-1);
    MegaSort(arrC, 0, u-1);

    for(int i=0; i<t;i++){
        cout << arrV[i] ;
    }
    for(int i=0; i<u;i++){
        cout << arrC[i] ;
    }

}