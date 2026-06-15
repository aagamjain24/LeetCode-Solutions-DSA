class Solution {
public:
    long long dfs(vector<int>& prices, int day, int state, int k,
                  vector<vector<vector<long long>>>& dp) {

        if (day == prices.size()) {
            return state == 0 ? 0 : -1e15;
        }

        if (dp[day][state][k] != -1)
            return dp[day][state][k];

        long long ans = dfs(prices, day + 1, state, k, dp); // skip

        if (state == 0) {
            if (k > 0) {
                // open long
                ans = max(ans,
                          -1LL * prices[day] +
                          dfs(prices, day + 1, 1, k, dp));

                // open short
                ans = max(ans,
                          1LL * prices[day] +
                          dfs(prices, day + 1, 2, k, dp));
            }
        }
        else if (state == 1) {
            // close long
            ans = max(ans,
                      1LL * prices[day] +
                      dfs(prices, day + 1, 0, k - 1, dp));
        }
        else {
            // close short
            ans = max(ans,
                      -1LL * prices[day] +
                      dfs(prices, day + 1, 0, k - 1, dp));
        }

        return dp[day][state][k] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(3,
            vector<long long>(k + 1, -1)));

        return dfs(prices, 0, 0, k, dp);
    }
};