class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<int,int>mp;
        int l=0,r=0;
        int mx=0;
        while(r<n ){
           
            while(mp.find(s[r])!=mp.end() && l<r){
                mp[s[l]]-- ;
                if(mp[s[l]]==0)mp.erase(s[l]);
                l++;
            } 
            mx=max(mx,r-l+1);
            mp[s[r]]++;
            r++;
        }
        return mx;
    }
};