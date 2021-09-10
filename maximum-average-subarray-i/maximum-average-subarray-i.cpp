class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        long long sum = 0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        ans = max(ans,(double)sum/k);
        
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[i-k];
            ans = max(ans,(double)sum/k);
        }
        
        return ans;
    }
};