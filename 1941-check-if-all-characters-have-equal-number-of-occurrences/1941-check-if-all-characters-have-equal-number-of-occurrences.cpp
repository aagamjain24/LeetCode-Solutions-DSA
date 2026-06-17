class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;

        for (char c : s) mp[c]++;

        int freq = mp.begin()->second;

        for (auto &p : mp)
            if (p.second != freq)
                return false;

        return true;
    }
};