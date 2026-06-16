#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define oset tree<l, null_type,less_equal<l>, rb_tree_tag,tree_order_statistics_node_update>
using l=long;
class Solution {
public:
    l reversePairs(vector<int>& nums) {
        oset os;
        l n=nums.size();
        l ans=0;
        for (int i = n - 1; i >= 0; i--) {
    ans += os.order_of_key(nums[i]);
    os.insert(2LL * nums[i]);
}
        return ans;
    }
};