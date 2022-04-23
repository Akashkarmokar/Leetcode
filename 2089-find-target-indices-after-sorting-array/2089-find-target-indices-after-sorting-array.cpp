class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        auto lowerIt = lower_bound(nums.begin(),nums.end(),target);
        auto upperIt = upper_bound(nums.begin(),nums.end(),target);
        if(upperIt == lowerIt){
            return {};
        }else{
            int startIndex = lowerIt - nums.begin();
            int endIndex = upperIt - nums.begin();
            vector<int> ans;
            for(int i=startIndex;i<endIndex;i++){
                ans.push_back(i);
            }
            return ans;
        }
        
    }
};