
// Source Link : https://www.youtube.com/watch?v=WcQ_y9TWhhw

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return n;
        }
        vector<int>lis(n,1),cnt(n,1);
        
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(nums[i]<nums[j]){
                    if(lis[i]>=lis[j]){
                        lis[j] = lis[i] + 1;
                        cnt[j] = cnt[i];
                    }
                    else if(lis[j]==lis[i]+1){
                        cnt[j]+=cnt[i];
                    }
                }
            }
        }
        int LIS = *max_element(lis.begin(),lis.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            if(lis[i]==LIS){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};