class Solution {
public:
int helper(vector<int>& nums){
    int p1 = 0;
    int p2 = 0;
    for(int i = 0; i < nums.size();i++){
        int curr = max(p1,p2+nums[i]);
        p2 = p1;
        p1 = curr;
    }
    return p1;
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int x = nums[n-1];
        nums.pop_back();
        int m1 = helper(nums);
        nums.push_back(x);
        nums.erase(nums.begin());
        int m2 = helper(nums);
        return max(m1,m2);
    }
};