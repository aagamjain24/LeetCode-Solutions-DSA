class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    int n = nums.size();
    int res =0;
    for (auto x :nums) {
           res ^= x;
         }
         unsigned int unique =(unsigned int)res &   -(unsigned int)(res);
         int v1=0;
         int v2=0;
         for(int i=0;i<n;i++){
            if(nums[i] & unique){
                v1^=nums[i];
            }
            else{
                v2^=nums[i];
            }
         }

        return {v1,v2};
    }
};