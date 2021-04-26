class Solution {
    int fun(int n)
    {
        int sum = 0 ;
        while(n)
        {
            int dig = n%10;
            n/=10;
            sum+=dig*dig;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int>visited;
        for(int i = 0;i<19;i++)
        {
            if(n==1)
            {
                return true;
            }
            n=fun(n);
            if(visited.count(n)==1)
            {
                return false;
            }
            visited.insert(n);
        }
        return true;
    }
};