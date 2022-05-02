class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int m = 0;
        for(int i=m;i<nums.size();i++){
            if(nums[i]%2==0){
                swap(nums[i],nums[m]);
                m++;
            }
        }
        return nums;
    }
};