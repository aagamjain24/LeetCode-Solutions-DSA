class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int digitSum = 0;
        int digitProduct = 1;

        while (n != 0) {
            int digit = n % 10;
            digitSum += digit;
            digitProduct *= digit;
            n = n / 10;
        }

        int Sum = digitSum + digitProduct;

        return original % Sum == 0;
    }
};