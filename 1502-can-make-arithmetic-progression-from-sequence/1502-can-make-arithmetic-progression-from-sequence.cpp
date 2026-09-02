class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
       sort(arr.begin(),arr.end());
       int dist=arr[1]-arr[0];
       int n=arr.size();
       int i=1;
       for(int i=2;i<n;i++){
       if(arr[i]-arr[i-1] != dist)
       return false;
       }
       return true;
    }
};