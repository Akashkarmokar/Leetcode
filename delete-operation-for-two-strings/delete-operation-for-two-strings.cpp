class Solution {
public:
    int mem[505][505];
    int minDistance(string word1, string word2) {
        for(int i=0;i<505;i++){
            for(int j=0;j<505;j++){
                mem[i][j] = -1;
            }
        }
        int ans = 0;
        for(int i=0;i<word1.size();i++){
            for(int j=0;j<word2.size();j++){
                ans = max(ans,lcs(i,j,word1,word2));
            }
        }
        return word1.size()-ans+word2.size()-ans;
    }
    int lcs(int i,int j,string &s,string &w){
        if(i==s.size() || j==w.size()){
            return 0;
        }
        if(mem[i][j]!= -1){
            return mem[i][j];
        }
        int ans = 0 ;
        if(s[i]==w[j]){
            ans = 1 + lcs(i+1,j+1,s,w);
        }
        else{
            int val_1 = lcs(i+1,j,s,w);
            int val_2 = lcs(i,j+1,s,w);
            ans = max(val_1,val_2);
        }
        mem[i][j] = ans;
        return mem[i][j];
    }
};