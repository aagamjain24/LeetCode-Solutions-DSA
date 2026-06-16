#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define oset                                                                   \
    tree<int, null_type, less_equal<int>, rb_tree_tag,                         \
         tree_order_statistics_node_update>
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        oset os;
        int n = nums.size();
        vector<int> count(n);

        for (int i = n - 1; i >= 0; i--) {
            count[i] = os.order_of_key({nums[i]});
            os.insert({nums[i]});
        }
        return count;
    }
};