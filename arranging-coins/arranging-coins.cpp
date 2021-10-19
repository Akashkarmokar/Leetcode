class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 0; // bad
        long long r = n; // good
        while(r>=l){
            long long m = l+(r-l)/2;
            long long cur = m*(m+1)/2;
            if(cur>n){
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return r;
    }
};