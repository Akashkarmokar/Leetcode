/**
    Time Complexity: O(N+M)
    Space Complexity: O (N+M)
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> forS, forT;
        for(auto ch: s){
            if(ch=='#' && !forS.empty()){
                forS.pop();
            }else if(ch == '#' && forS.empty()){
                continue;
            }else{
                forS.push(ch);
            }
        }
        for(auto ch: t){
            if(ch=='#' && !forT.empty()){
                forT.pop();
            }else if(ch == '#' && forT.empty()){
                continue;
            }else{
                forT.push(ch);
            }
        }
        if(forS == forT){
            return true;
        }
        return false;
    }
};