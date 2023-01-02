#include<iostream>
#include<vector>
using namespace std;
// Swapping Technique -->
    void helper(int ind,vector<int> arr,vector<vector<int>>& ans) {
        // base case
        if(ind == arr.size()) {
            // as we are changing in arr itself
            ans.push_back(arr);
            return;
        }

        // Swapping through iterating
        for(int i=ind;i<arr.size();i++) {
            swap(arr[ind],arr[i]);
            helper(ind+1,arr,ans);
            swap(arr[ind],arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,nums,ans);
        return ans;
    }