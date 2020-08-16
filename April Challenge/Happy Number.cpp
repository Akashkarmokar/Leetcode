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
        while(true)
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



// Here is the another solution : 
/*
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
        for(int i = 0;i<19;i++)    // Here we need maximum 18 iteration here is the link of Errichto youtube link and get the proof : https://www.youtube.com/watch?v=lgjWXi21IAg&list=PLl0KD3g-oDOHElCF7S7q6CRGz1qG8vQkS&index=2
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

/*
