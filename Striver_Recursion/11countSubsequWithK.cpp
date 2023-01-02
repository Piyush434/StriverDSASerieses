#include<iostream>
#include<vector>
using namespace std;
/*
Technique to get count

## INSIDE THE BASE CASE -->
   1. If base case is satisfied --> Return 1
   2. If not satisfied          --> Return 0

## IN below code
   int sum = 0;
   for( i --> no of recursive calls) {
        s += recursiveCall(i);
   }
   return sum;
*/
int oneAnsKsubseq(int ind,int* arr,int size,vector<int>& curr,int sum,int k) {
    // base case
    if(ind >= size) {
        // condition satisfied
        if(sum == k) {
            return 1;
        }
        // condition not satisfied
        return 0;
    }
    // 1. Include with true/false check
    curr.push_back(arr[ind]);
    int incAns = oneAnsKsubseq(ind+1,arr,size,curr,sum+arr[ind],k);

    // 2. Exclude
    curr.pop_back();
    int excAns = oneAnsKsubseq(ind+1,arr,size,curr,sum,k);

    return incAns+excAns;
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
        cout<<"No of subsequnces: "<<oneAnsKsubseq(0,arr,n,curr,0,k)<<endl;
    return 0;
}