class Solution {
public:
    int dp[1005];
    int next_index[1005];
    
    int lis(int i,vector<int>& v){
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans = 0;
        for(int j=i+1;j<v.size();j++){
            if(v[j]%v[i]==0){
                int subResult = lis(j,v);
                if(subResult>ans){
                    ans = subResult;
                    next_index[i] = j;
                }
            }
        }
        dp[i]= ans +1;
        return dp[i];
    }
    
    
    
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            dp[i] = -1;
            next_index[i] = -1;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 0;
        int st_idx = -1;
        for(int i=0;i<nums.size();i++){
            // ans = max(ans,lis(i,nums));
            int result = lis(i,nums);
            if(result>ans){
                ans = result;
                st_idx = i;
            }
        }
        vector<int>l;
        while(st_idx!=-1){
            l.push_back(nums[st_idx]);
            st_idx = next_index[st_idx];
        }
        return l;
    }
};