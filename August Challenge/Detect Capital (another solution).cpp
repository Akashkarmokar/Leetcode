class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.size();
        int c=0,s=0;
        for(int i=0;i<len;i++)
        {
            if(word[i]>96 && word[i]<123)
                s++;
            else
                c++;
        }
        if(c==len || s==len)
        {
            return true;
        }
        else if(s==len-1 && (word[0]>64&& word[0]<91))
        {
           return true;     
        }
        else{
            return false;
        }
    }
};
