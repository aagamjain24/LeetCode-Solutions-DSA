#include <string>
#include <algorithm>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string result = "";
        
        while (columnNumber > 0) {
            // Subtract 1 to make it 0-indexed (0 to 25)
            columnNumber--; 
            
            // Get the current last character
            int remainder = columnNumber % 26;
            result += (char)('A' + remainder);
            
            // Move to the next "digit"
            columnNumber /= 26;
        }
        
        // Since we extracted from right to left, we need to reverse the string
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};