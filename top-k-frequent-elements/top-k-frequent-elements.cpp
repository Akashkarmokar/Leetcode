class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==nums.size()){
            return nums;
        }
        map<int,int> mp;
        for(int i=0;i<(int)nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minPQ;
        for(auto it: mp){
            int num = it.first;
            int freq = it.second;
            if(minPQ.size()<k){
                minPQ.push({it.second,it.first});
            }else if(minPQ.top().first < freq){
                minPQ.pop();
                minPQ.push({freq,num});
            }
        }
        vector<int> ans;
        while(!minPQ.empty()){
            ans.push_back(minPQ.top().second);
            minPQ.pop();
        }
        return ans;
    }
};