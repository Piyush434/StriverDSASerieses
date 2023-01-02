//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void helper(int ind,vector<int> arr,int n,vector<int>& ans,int sum) {
        // base case
        if(ind == n) {
            ans.push_back(sum);
            return;
        }
        
        
        // 1. Include
        helper(ind+1,arr,n,ans,sum+arr[ind]);
        // 2. Exclude
        helper(ind+1,arr,n,ans,sum);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        helper(0,arr,N,ans,0);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
