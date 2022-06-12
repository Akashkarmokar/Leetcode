/**
    Time Complexity: O(N)
    Space Complexity: O(1)
*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), curSum = 0, ans= 0, l = 0, r = 0;
        bool freq[10001]{false};
        while(l<=r && r<n){
            while(freq[nums[r]]){
                curSum-=nums[l];
                freq[nums[l++]] = false;
            }
            curSum+=nums[r];
            freq[nums[r++]] = true;
            ans = max(ans,curSum);
        }
        return ans;
    }
};