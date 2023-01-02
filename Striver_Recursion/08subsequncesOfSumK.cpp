#include<iostream>
#include<vector>
using namespace std;

void subsequncesK(int ind,int* arr,int size,vector<int>& curr,int sum,int k) {
    if(ind >= size) {
        if(sum == k) {
            for(auto i:curr) 
                cout<<i<<" ";
            cout<<endl;
        }
        return;
    }

    // 1. Include
    curr.push_back(arr[ind]);
    // sum = sum+arr[ind];
    subsequncesK(ind+1,arr,size,curr,sum+arr[ind],k);

    // 2. Exclude
    curr.pop_back();
    // sum = sum-arr[ind];
    subsequncesK(ind+1,arr,size,curr,sum,k);
    
}
    int main(){
        int n,k;
        // cout<<"Enter n: ";
        cin>>n;
        // cout<<"Enter arr: ";
        int* arr = new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        // cout<<"Enter K: ";
        cin>>k;
        vector<int> curr;

        subsequncesK(0,arr,n,curr,0,k);

    return 0;
}