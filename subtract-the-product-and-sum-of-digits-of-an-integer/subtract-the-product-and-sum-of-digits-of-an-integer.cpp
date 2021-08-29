class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, mul = 1;
        while(n){
            int dig = n%10;
            sum+=dig;
            mul*=dig;
            n/=10;
        }
        return (int)mul-sum;
    }
    
};