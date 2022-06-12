/**
    Time Complexity: O(N)
    Space Complexity: O(N)
*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), curSum = 0, ans= 0, l = 0, r = 0;
        unordered_set<int> s;
        while(l<=r && r<n){
            while(s.find(nums[r]) != s.end()){
                curSum-=nums[l];
                s.erase(nums[l++]);
            }
            curSum+=nums[r];
            s.insert(nums[r++]);
            ans = max(ans,curSum);
        }
        return ans;
    }
};