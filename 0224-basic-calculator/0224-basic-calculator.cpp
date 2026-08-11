#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> st;
        int result = 0;
        long number = 0; // Use long to prevent potential overflow during intermediate steps
        int sign = 1;    // 1 represents '+', -1 represents '-'
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                // Form the number (handles multi-digit numbers)
                number = 10 * number + (c - '0');
            } else if (c == '+') {
                // Add the previous number to the result
                result += sign * number;
                number = 0;
                sign = 1; // Update sign for the next number
            } else if (c == '-') {
                // Subtract the previous number from the result
                result += sign * number;
                number = 0;
                sign = -1; // Update sign for the next number
            } else if (c == '(') {
                // We push the current result and the sign onto the stack
                // so we can use them after evaluating the expression in the ()
                st.push(result);
                st.push(sign);
                
                // Reset result and sign for the new sub-expression
                sign = 1;
                result = 0;
            } else if (c == ')') {
                // Add the last number inside the parentheses to the inner result
                result += sign * number;
                number = 0;
                
                // st.top() is the sign just before the '('
                result *= st.top(); 
                st.pop();
                
                // st.top() is the accumulated result just before the '('
                result += st.top(); 
                st.pop();
            }
        }
        
        // Add any remaining number to the result
        if (number != 0) {
            result += sign * number;
        }
        
        return result;
    }
};