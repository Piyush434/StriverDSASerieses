#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(int ind,vector<int>& curr,int* arr,int size) {
    if(ind >= size) {
        
        for(auto i: curr) {
            cout<<i<<" ";
        }
        if(curr.size() == 0) {
            cout<<"{}";
        }
        cout<<endl;
        return; // This is requried alwaysss
    }

    // **1. Include
    curr.push_back(arr[ind]);
    printSubsequences(ind+1,curr,arr,size);
    // **2. Exclude
    curr.pop_back();
    printSubsequences(ind+1,curr,arr,size);
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<int> curr;
    printSubsequences(0,curr,arr,n);
    return 0;
}