class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> mn(n);
        mn[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            mn[i] = min(mn[i + 1], nums[i]);

        int max_ele = nums[0];

        for (int i = 0; i < n; i++) {
            max_ele = max(max_ele, nums[i]);

            if (max_ele - mn[i] <= k)
                return i;
        }

        return -1;
    }
};