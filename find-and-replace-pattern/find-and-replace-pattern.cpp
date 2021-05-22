class Solution {
private:
    vector<string>ans;
    map<char,char>mp;
    string tmp;
    
    char translate(char& c){
        if(mp.find(c)==mp.end()){
            mp[c] = (char)(97+mp.size());
        }
        return mp[c];
    }
    void compare(string& s){
        mp.clear();
        for(int i=0;i<s.size();i++){
            if(translate(s[i]) != tmp[i]){
                return ;
            }
        }
        ans.push_back(s);
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        ans.resize(0);
        mp.clear();
        tmp = pattern;
        for(int i=0;i<pattern.size();i++){
            tmp[i] = translate(pattern[i]);
        }
        for(auto word: words){
            compare(word);
        }
        return ans;
    }
};