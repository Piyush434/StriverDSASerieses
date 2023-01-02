#include<iostream>
using namespace std;

void reverseArray(int i,int* arr,int size) {
    if(i >= size/2) return;

    swap(arr[i],arr[size-i-1]);
    reverseArray(i+1,arr,size);
}

int main(){

        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        reverseArray(0,arr,n);

        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    return 0;
}