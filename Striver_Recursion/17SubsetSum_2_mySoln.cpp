#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void helper(int ind,vector<int>& curr,vector<int> nums, vector<vector<int>>& ans)  {
        if(ind >= nums.size()) {
            ans.push_back(curr);
            return;
        }
        // 1. Include
        curr.push_back(nums[ind]);
        helper(ind+1,curr,nums,ans);
        // 2. Exclude
        // Need to skip all the similar numbers after including the same to avoid repetition
        curr.pop_back();
        while(ind+1 < nums.size() && nums[ind] == nums[ind+1]) ind++;
        helper(ind+1,curr,nums,ans);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,curr,nums,ans);
        return ans;
    }

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    subsetsWithDup(arr);
    // See on leetcode
    return 0;
}