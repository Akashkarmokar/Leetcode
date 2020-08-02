class Solution {
public:
    bool detectCapitalUse(string word) {
        int sz = word.size();
        if(sz==1)
        {
            return true;
        }
        bool f=false;
        int cap_on=0,cap_off=0;
        for(int i=0;i<sz;i++)
        {
            if(i==0)
            {
                if(65<=word[i] && word[i]<=90)
                {
                    f = true;
                }
            }
            else
            {
                if(65<=word[i] && word[i]<=90)
                {
                    cap_on++;
                }
                else
                {
                    cap_off++;
                }
            }
            
        }
        
        if(f && (cap_on && cap_off==0))
        {
            return true;
        }
        else if(f && (cap_off && cap_on==0))
        {
            return true;
        }
        else if(!f && (cap_off && cap_on==0))
        {
            return true;
        }
        else
        {
            return false;       
        }
   }
};
