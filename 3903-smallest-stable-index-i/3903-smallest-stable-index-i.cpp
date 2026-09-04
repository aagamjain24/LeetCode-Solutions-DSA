class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int max_ele = *max_element(nums.begin(), nums.begin() + i + 1);
            int min_ele = *min_element(nums.begin() + i, nums.end());

            if (max_ele - min_ele <= k)
                return i;
        }

        return -1;
    }
};