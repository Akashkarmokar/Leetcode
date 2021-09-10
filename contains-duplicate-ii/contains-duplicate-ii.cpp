class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> mySet;
        for(int i=0;i<nums.size();i++){
            if(i>k){
                mySet.erase(nums[i-k-1]);
            }
            if(!mySet.insert(nums[i]).second){
                return true;
            }
        }
        
        return false;
    }
};