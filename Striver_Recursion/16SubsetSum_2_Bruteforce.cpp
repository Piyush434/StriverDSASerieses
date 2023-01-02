#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
// TC -> 2^n
    // Set -> arr of arr
    // -> m*log(m) --> m = 2^n --> 2^n log(2^n)
    void helper(int ind,vector<int> nums,int size,set<vector<int>>& ans,vector<int>& curr) {
        // base case
        if(ind == size) {
            ans.insert(curr);
            return;
        }
        
        // 1. Include 2. Exclude
        curr.push_back(nums[ind]);
        helper(ind+1,nums,size,ans,curr);
        // Exclude
        curr.pop_back();
        helper(ind+1,nums,size,ans,curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> listAns;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        helper(0,nums,nums.size(),ans,curr);
        for(auto i: ans) {
            listAns.push_back(i);
        }
        return listAns;
    }
    int main(){
        //
    return 0;
}