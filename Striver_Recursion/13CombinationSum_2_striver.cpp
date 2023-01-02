#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void modify(int ind,vector<int> nums,int target,vector<vector<int>>& ans, vector<int>& curr) {
        //base case
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        // 2nd base case
        // if(ind >= nums.size()) return; --> this condn is inside loop

        // looping through 

        for(int i=ind;i<nums.size();i++) {
            // skipping the similar ones
            if(i!=ind && nums[i] == nums[i-1]) continue;
            // if arr[i] exceeds target
            if(nums[i] > target) break;
            
            curr.push_back(nums[i]);
            modify(i+1,nums,target-nums[i],ans,curr);
            curr.pop_back();
        }
    }
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        modify(0,candidates,target,ans,curr);
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
    ans = combinationSum2(nums,target);
    for(auto i:ans) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}