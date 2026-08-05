class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans,
               vector<int>& res, int idx) {
        if (idx == nums.size()) {
            ans.push_back(res);
            return;
        }

        // Include current element
        res.push_back(nums[idx]);
        solve(nums, ans, res, idx + 1);
        res.pop_back();

        // Exclude current element and all its duplicates
        int next = idx + 1;
        while (next < nums.size() && nums[next] == nums[idx]) {
            next++;
        }

        solve(nums, ans, res, next);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        solve(nums, ans, res, 0);
        return ans;
    }
};