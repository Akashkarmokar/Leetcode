class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<(int)s.size();i++){
            mp[s[i]]++;
        }
        auto comp = [](pair<char,int>&a , pair<char,int>& b){
            return a.second<b.second;
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(comp)> pq(comp);
        string ans = "";
        for(auto it:mp){
            char c = it.first;
            int freq = it.second;
            pq.push({c,freq});
        }
        
        while(!pq.empty()){
            pair<char,int> val = pq.top();
            pq.pop();
            for(int i=0;i<val.second;i++){
                ans+=val.first;
            }
        }
        return ans;
    }
};