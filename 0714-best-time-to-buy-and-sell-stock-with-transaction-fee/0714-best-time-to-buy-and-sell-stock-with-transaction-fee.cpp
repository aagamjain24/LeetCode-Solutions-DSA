class Solution {
public:
    int helper(vector<int>& prices, int day, int state,
               vector<vector<int>>& memo,int fee) {

        if (day == prices.size())
            return 0;
        if (memo[day][state] != -1)
            return memo[day][state];
        int profit = 0;
        if (state == 0) {
            int buy = -prices[day]-fee + helper(prices, day + 1, 1, memo,fee);
            int skip = helper(prices, day + 1, 0, memo,fee);
            profit = max(buy, skip);
        } else {
            int sell = prices[day] + helper(prices, day + 1, 0, memo,fee);
            int skip = helper(prices, day + 1, 1, memo,fee);
            profit = max(sell, skip);
        }
        memo[day][state] = profit;
        return profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n + 1, vector<int>(2, -1));
        int ans = helper(prices, 0, 0, memo,fee);
        return ans;
    }
};
