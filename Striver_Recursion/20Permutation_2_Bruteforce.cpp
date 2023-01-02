#include<bits/stdc++.h>
using namespace std;

 void helper(vector<int> nums,vector<int>& curr,set<vector<int>>& ans,int* arr) 
    {
        if(curr.size() == nums.size()){
            ans.insert(curr);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(arr[i] == 1) continue;
            curr.push_back(nums[i]);
            arr[i] = 1;
            helper(nums,curr,ans,arr);
            curr.pop_back();
            arr[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<vector<int>> listAns;
        vector<int> curr;
        int* arr = new int[nums.size()];
        helper(nums,curr,ans,arr);
        for(auto i:ans) {
            listAns.push_back(i);
        }
        return listAns;
    }