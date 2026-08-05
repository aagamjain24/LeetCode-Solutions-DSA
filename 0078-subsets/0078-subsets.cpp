class Solution {
public:
void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>res,int idx){
    if(idx==nums.size()){
        ans.push_back(res);
        return;
    }
    res.push_back(nums[idx]);
    solve(nums,ans,res,idx+1);
    res.pop_back();
    solve(nums,ans,res,idx+1);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(nums,ans,res,0);
        return ans;
    }
};