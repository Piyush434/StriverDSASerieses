#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> nums,vector<vector<int>>& ans,vector<int>& curr,int* arr,int n) {
        // When our data structure is full
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++) {
            if(arr[i] == 1) continue;
            curr.push_back(nums[i]);
            arr[i] = 1;
            helper(nums,ans,curr,arr,n);
            curr.pop_back();
            arr[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int* arr = new int[n];
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums,ans,curr,arr,nums.size());
        return ans;
    }