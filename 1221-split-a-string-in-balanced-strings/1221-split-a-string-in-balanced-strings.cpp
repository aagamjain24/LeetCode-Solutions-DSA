class Solution {
public:
    int balancedStringSplit(string s) {
        int bal = 0, ans = 0;

        for (char c : s) {
            bal += (c == 'L') ? 1 : -1;
            if (bal == 0) ans++;
        }

        return ans;
    }
};