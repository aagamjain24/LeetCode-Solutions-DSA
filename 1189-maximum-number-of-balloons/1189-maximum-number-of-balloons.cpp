class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.length();
        int count=0;
        unordered_map<char,int>freq;
        for(char ch:text){
            freq[ch]++;
        }
         return min({
            freq['b'],
            freq['a'],
            freq['l'] / 2,
            freq['o'] / 2,
            freq['n']
        });
    }
};