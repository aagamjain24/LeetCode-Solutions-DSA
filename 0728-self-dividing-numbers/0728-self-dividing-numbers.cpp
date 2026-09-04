class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for(int n = left; n <= right; n++) {
            int x = n;
            bool ok = true;

            while(x) {
                int d = x % 10;
                if(d == 0 || n % d != 0) {
                    ok = false;
                    break;
                }
                x /= 10;
            }

            if(ok)
                ans.push_back(n);
        }

        return ans;
    }
};