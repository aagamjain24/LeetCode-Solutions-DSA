class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int,int> mp;

        for(int x : nums)
            mp[x]++;

        // duplicate
        for(int i = 1; i <= n; i++) {
            if(mp[i] == 2)
                ans.push_back(i);
        }

        // missing
        for(int i = 1; i <= n; i++) {
            if(mp[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};