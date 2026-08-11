class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        
        for (char c : columnTitle) {
            // Multiply the current result by 26 (shifting left in base-26)
            // and add the 1-indexed value of the current character
            result = result * 26 + (c - 'A' + 1);
        }
        
        return result;
    }
};