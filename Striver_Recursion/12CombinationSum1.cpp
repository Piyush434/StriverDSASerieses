#include<bits/stdc++.h>
using namespace std;

void helper(int ind,int target,vector<int> nums,vector<vector<int>>& ans,vector<int>& curr) {
        // base case
        if(ind >= nums.size()) {
            if(target == 0) {
                ans.push_back(curr);
            }
            return;
        }

        // 1. Include
        // Need to check if our current value is not greater thant current target
        if(nums[ind] <= target) {
            curr.push_back(nums[ind]);
            helper(ind,target-nums[ind],nums,ans,curr);
            curr.pop_back();
        }
        // ^ no change in ind ans we can take same element again
        // 2. exclude
        helper(ind+1,target,nums,ans,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,target,candidates,ans,curr);
        return ans;
}

int main() {
    vector<vector<int>> ans;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    int target;
    cin>>target;
    ans = combinationSum(nums,target);
    for(auto i:ans) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
