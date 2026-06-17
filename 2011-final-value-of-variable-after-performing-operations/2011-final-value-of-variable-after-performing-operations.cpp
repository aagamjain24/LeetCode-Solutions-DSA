class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto &s : operations)
            x += (s[1] == '+') ? 1 : -1;
        return x;
    }
};