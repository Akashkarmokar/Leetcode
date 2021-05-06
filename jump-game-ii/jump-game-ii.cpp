// https://leetcode.com/problems/jump-game-ii/discuss/1192401/Easy-Solutions-w-Explanation-or-Optimizations-from-Brute-Force-to-DP-to-Greedy-BFS
//  Recursive Dynamic Memorization technique 
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),1001);
        return solve(nums,dp,0);
        
    }
    int solve(vector<int>& nums,vector<int>& dp,int pos){
        if(pos>=nums.size()-1){
            return 0; //when we reached end, return 0 denoting we don't need any jump 
        }
        if(dp[pos]!=1001){
            return dp[pos];
        }
        for(int j=1;j<=nums[pos];j++){
            dp[pos] = min(dp[pos],1+solve(nums,dp,pos+j));
        }
        return dp[pos];
    }
};