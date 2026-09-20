class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            // Reversed alphabet position: 'a' -> 26, 'b' -> 25, ..., 'z' -> 1
            int reversed_alphabet_pos = 26 - (s[i] - 'a');
            
            // 1-indexed string position
            int string_pos = i + 1;
            
            ans += reversed_alphabet_pos * string_pos;
        }
        return ans;
    }
};