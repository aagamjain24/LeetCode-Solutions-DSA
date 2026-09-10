class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        multiset<int> ms;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ms.insert(nums[i] * nums[i]);
        }
        for (auto x : ms) {
            ans.push_back(x);
        }
        return ans;
    }
};