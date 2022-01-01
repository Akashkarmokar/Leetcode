class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> ump;
        for(int i=0;i<(int)words.size();i++){
            ump[words[i]]++;
        }
        
        // custom comparator function
        auto comp = [](pair<int,string>& a, pair<int,string>& b){
            if(a.first != b.first){
                return a.first > b.first;
            }else{
                return a.second < b.second;
            }

        };
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(comp) > minPQ(comp);
        for(auto it: ump){
            int freq = it.second;
            string s = it.first;
            minPQ.push({freq,s});
            if(minPQ.size()>k){
                minPQ.pop();
            }
        }
        vector<string> ans(k);
        while(!minPQ.empty() && k--){
            ans[k]=minPQ.top().second;
            minPQ.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};