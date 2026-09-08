class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (long long i = 1000; i <= n; i++) {
            if (i >= 1000) ans++;
            if (i >= 1000000) ans++;
            if (i >= 1000000000) ans++;
            if (i >= 1000000000000LL) ans++;
        }

        return ans;
    }
};