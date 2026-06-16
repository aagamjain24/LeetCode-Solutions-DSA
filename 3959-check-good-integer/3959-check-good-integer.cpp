class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        int squareSum = 0;

        while (n > 0) {
            int d = n % 10;
            digitSum += d;
            squareSum += d * d;
            n /= 10;
        }

        return squareSum - digitSum >= 50;
    }
};