class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size();
        if(n>1){
        int si1=-1;
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                si1=i;
                break;
            }
        }
     if(si1!=-1){
        int si2=-1;
        for(int i=si1;i<n;i++){
            if(a[i]>a[si1]){
                si2=i;
            }
        }
        swap(a[si1],a[si2]);
     }
        reverse(a.begin()+si1+1,a.end());
        }
        
    }
};