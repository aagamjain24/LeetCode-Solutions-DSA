class Solution {
public:
    long long helper(vector<vector<int>>& q, int i, vector<long long>& memo) {
        if (i >= q.size()) return 0;

        if (memo[i] != -1) return memo[i];

        long long skip = helper(q, i + 1, memo);
        long long pick = q[i][0] + helper(q, i + q[i][1] + 1, memo);

        return memo[i] = max(pick, skip);
    }

    long long mostPoints(vector<vector<int>>& q) {
        vector<long long> memo(q.size(), -1);
        return helper(q, 0, memo);
    }
};