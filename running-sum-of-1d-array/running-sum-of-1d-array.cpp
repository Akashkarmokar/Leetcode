class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int cur = 0;
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            ans.push_back(cur);
        }
        return ans;
    }
};