#include<iostream>
#include<vector>
using namespace std;
void printSubsequnceK(int ind,int* arr,int n,vector<int>& curr,int sum,int k) {
    // base case
    if(ind >= n) {
        if(sum == k) {
            for(auto i:curr) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return;
    }

    // 1. Include 2. Exclude
    curr.push_back(arr[ind]);
    printSubsequnceK(ind+1,arr,n,curr,sum+arr[ind],k);
    // 
    curr.pop_back();
    printSubsequnceK(ind+1,arr,n,curr,sum,k);
}
    int main(){
        vector<int> curr;
        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int k;
        cin>>k;
        printSubsequnceK(0,arr,n,curr,0,k);
    return 0;
}