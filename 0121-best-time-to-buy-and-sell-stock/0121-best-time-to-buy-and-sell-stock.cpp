class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy=prices[0], ans=0;
       for(int i:prices){
        ans=max(i-buy,ans);
        buy=min(buy,i);
       } 
       return ans;
    }
};