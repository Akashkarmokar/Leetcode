class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0;
        int r = 0;
        
        int sSize = s.size();
        int tSize = t.size();
        
        while(l<sSize && r<tSize){
            if(s[l] == t[r]){
                l++;
                r++;
            }else{
                r++;
            }
        }
        if(l==s.size()){
            return true;
        }
        return false;
    }
};