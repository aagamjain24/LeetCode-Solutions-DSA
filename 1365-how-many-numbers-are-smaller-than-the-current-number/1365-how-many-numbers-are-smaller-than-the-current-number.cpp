class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        vector<int> ans;

        for(int x : nums) {
            ans.push_back(lower_bound(temp.begin(), temp.end(), x) - temp.begin());
        }

        return ans;
    }
};