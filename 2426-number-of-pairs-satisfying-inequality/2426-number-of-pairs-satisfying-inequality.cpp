#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, greater_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> oset;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        oset os;
        long long ans = 0, n = nums1.size();
        for (int i = 0; i < n; i++)
            nums1[i] -= nums2[i];
        for (int i = n - 1; i >= 0; i--) {
            ans += os.order_of_key(nums1[i] - 1);
            os.insert(nums1[i] + diff);
        }
        return ans;
    }
};