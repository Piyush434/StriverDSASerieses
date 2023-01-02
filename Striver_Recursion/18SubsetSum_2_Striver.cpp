#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void helper(int ind,vector<int> nums,vector<vector<int>>& ans,vector<int>& ds) {
        // as we are directly inserting data strucutre with the recursive call's update
        // no need to keep if condition
        ans.push_back(ds);

        // To loop through and make recursive calls without reptiting the same values
        for(int i=ind;i<nums.size();i++) {
            if(i!=ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(i+1,nums,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        // to avoid duplication
        sort(nums.begin(),nums.end());
        helper(0,nums,ans,ds);
        return ans;
    }

int main() {
    return 0;
}