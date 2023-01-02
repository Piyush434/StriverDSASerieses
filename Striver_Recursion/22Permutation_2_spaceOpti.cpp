#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void helper(int ind,vector<int> nums,vector<vector<int>>& ans) {
        if(ind == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // To avoid repition of same number at curr position
        // we will maintain one set

        unordered_set<int> s;

        for(int i=ind;i<nums.size();i++) {
            if(s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            swap(nums[ind],nums[i]);
            helper(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    helper(0,nums,ans);
    return ans;
}

int main() {
    return 0;
}