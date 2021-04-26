class Solution {
private:
    set<pair<string,string>>s;
    string getOne(string s,int a){
        for(int i=0;i<s.size();i++){
            if(i&1){
                int num = s[i]-'0';
                num = (num+a)%10;
                s[i] = num+'0';
            }
        }
        return s;
    }
    string getTwo(string s,int b){
        b = b%s.size();
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
        return s;
    }
    void dfs(const string& s,int a,int b,unordered_set<string>& visited,string &minS){
        if(visited.count(s)){
            return ;
        }
        visited.insert(s);
        minS = min(s,minS);
        dfs(getOne(s,a),a,b,visited,minS);
        dfs(getTwo(s,b),a,b,visited,minS);
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        string res = s;
        unordered_set<string>visited;
        dfs(s,a,b,visited,res);
        return res;
    }
};