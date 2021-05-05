class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i=1,error=0;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                if(error++ || (i>1 && i<nums.size()-1 && nums[i-2]>nums[i] && nums[i-1]>nums[i+1])){
                    return false;
                }
            }
        }
        return true;
    }
};