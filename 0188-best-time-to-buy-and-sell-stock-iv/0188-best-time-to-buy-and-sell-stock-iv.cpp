class Solution {
public:
    int helper(vector<int>& prices, int day, int state, int k,
               vector<vector<vector<int>>>& memo) {

        if (day == prices.size() || k == 0)
            return 0;

        if (memo[day][state][k] != -1)
            return memo[day][state][k];

        int profit = 0;

        if (state == 0) { // can buy
            int buy = -prices[day] + helper(prices, day + 1, 1, k, memo);
            int skip = helper(prices, day + 1, 0, k, memo);
            profit = max(buy, skip);
        } else { // can sell
            int sell = prices[day] + helper(prices, day + 1, 0, k - 1, memo);
            int skip = helper(prices, day + 1, 1, k, memo);
            profit = max(sell, skip);
        }

        return memo[day][state][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> memo(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return helper(prices, 0, 0, k, memo);
    }
};