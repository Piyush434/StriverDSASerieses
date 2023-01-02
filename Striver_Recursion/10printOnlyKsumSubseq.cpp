#include<iostream>
#include<vector>
using namespace std;
/*
Technique to print only one Ans ->

## INSIDE THE BASE CASE -->
   1. If base case is satisfied --> Return True
   2. If not satisfied          --> Return False;
*/
bool oneAnsKsubseq(int ind,int* arr,int size,vector<int>& curr,int sum,int k) {
    // base case
    if(ind >= size) {
        // condition satisfied
        if(sum == k) {
            for(auto i: curr) {
                cout<<i<<" ";
            }
            cout<<endl;
            return true;
        }
        // condition not satisfied
        return false;
    }
    // 1. Include with true/false check
    curr.push_back(arr[ind]);
    bool incAns = oneAnsKsubseq(ind+1,arr,size,curr,sum+arr[ind],k);
    if(incAns) return true;

    // 2. Exclude
    curr.pop_back();
    bool excAns = oneAnsKsubseq(ind+1,arr,size,curr,sum,k);
    if(excAns) return true;

    return false;
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
        oneAnsKsubseq(0,arr,n,curr,0,k);
    return 0;
}