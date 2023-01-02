#include<bits/stdc++.h>
using namespace std;

/*
Just Made Sum changes in Combination Sum 1 -->

1. Sorted the input array
2. As we want to take each element only once so did (ind+1) in Include as well
3. Used set<vector<int>> to avoid repition and to get in lexicographical order
4. Converted set into list of list

Done !!!

But it will give you TLE :)..

*/
void helper(int ind,int target,vector<int> nums,set<vector<int>>& ans,vector<int>& curr) {
        if(ind == nums.size()) {
            if(target == 0) {
                ans.insert(curr);
            }
            return;
        }
        if(nums[ind] <= target) {
            curr.push_back(nums[ind]);
            helper(ind+1,target-nums[ind],nums,ans,curr);
            curr.pop_back();
        }

        helper(ind+1,target,nums,ans,curr);

    }
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>> ans;
        vector<vector<int>> liAns;
        vector<int> curr;
        helper(0,target,candidates,ans,curr);
        for(auto i: ans) {
            liAns.push_back(i);
        }
        return liAns;
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
    ans = combinationSum2(nums,target);
    for(auto i:ans) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
