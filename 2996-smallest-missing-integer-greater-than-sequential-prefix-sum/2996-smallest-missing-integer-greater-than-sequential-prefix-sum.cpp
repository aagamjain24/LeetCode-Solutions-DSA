class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        
        // 1. Calculate the sum of the longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                // Break as soon as the sequence is no longer sequential
                break;
            }
        }
        
        // 2. Store all elements in a hash set for quick lookup
        unordered_set<int> present_nums(nums.begin(), nums.end());
        
        // 3. Find the smallest missing integer greater than or equal to the sum
        int x = sum;
        while (present_nums.count(x)) {
            x++;
        }
        
        return x;
    }
};