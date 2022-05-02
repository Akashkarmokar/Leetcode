/**
    TimeComplexity: O(M+N)
    SpaceComplexity: O(1)
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        
        int skipForS = 0;
        int skipForT = 0;
        while( i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    skipForS++;
                    i--;
                }else if(skipForS > 0){
                    skipForS--;
                    i--;
                }else{
                    break;
                }
            }
            while(j>=0){
                if(t[j]=='#'){
                    skipForT++;
                    j--;
                }else if(skipForT > 0){
                    skipForT--;
                    j--;
                }else{
                    break;
                }
            }
            if(i>=0 && j>=0 && (s[i] != t[j])){ return false; }
            if((i>=0) != (j>=0)) { return false; }
            i--;
            j--;
        }
        return true;
    }
};