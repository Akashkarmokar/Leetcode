class Solution {
public:
    int dp[1005];
    int f(int index,vector<vector<int>>&v){
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans = 0;
        for(int j=index+1;j<v.size();j++){
            if(v[j][0]>v[index][1]){
                ans = max(ans,f(j,v));
            }
        }
        dp[index] = ans + 1;
        return dp[index];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0;
        for(int i=0;i<pairs.size();i++){
            dp[i] = -1;
        }
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<pairs.size();i++){
            ans = max(ans,f(i,pairs));
        }
        return ans;
    }
};