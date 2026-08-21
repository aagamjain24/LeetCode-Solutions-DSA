class Solution {
public:
    bool isSubsequence(string s, string t) {
    auto it = t.begin();

    for (char c : s) {
        it = find(it, t.end(), c);

        if (it == t.end())
            return false;

        it++;
    }

    return true;
}
};