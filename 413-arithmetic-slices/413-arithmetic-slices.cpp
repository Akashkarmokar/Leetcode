class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp(n);
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = 1 + dp[i-1];
                ans+=dp[i];
            }
        }
        
        return ans;
    }
};