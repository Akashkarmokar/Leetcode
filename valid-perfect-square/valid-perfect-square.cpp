class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        while(r>l+1){
            int m = l+(r-l)/2;
            if((long long)m*m>num){
                r = m;
            }else{
                l = m;
            }
        }
        
        return l*l==num?true:false;
    }
};