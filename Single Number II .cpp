class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long sumOfSet=0,sumOfNum=0;
        set<int>s;
        for(auto i:nums)
        {
            if(s.find(i)==s.end())
            {
                s.insert(i);
                sumOfSet+=i;
            }
            sumOfNum+=i;
        }
        return (3*sumOfSet - sumOfNum)/2;
    }
};

Approach : 
 2*(a+b+c)-(a+a+b+b+c) = c
 
 Same as the above approach 
  (3*(a+b+c)-(a+a+a+b+b+b+c))/2= c;



// Another Solution : 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<32;i++)
        {
            int count = 0;
            for(int num:nums)
            {
                count+=(num>>i) & 1;
            }
            if(count%3)
                res |=1<<i;
        }
        return res;
    }
};
