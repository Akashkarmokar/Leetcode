class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int sum = 0;
        for(int i=0;i<mp.size();i++){
            sum+=(mp[i]*(mp[i]-1))/2;
        }
        return sum;
    }
};