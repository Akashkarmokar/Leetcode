class Solution {
public:
    vector<vector<int>> adj, parent;
    vector<int> cnt;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        adj.resize(n);
        parent.resize(n);
        cnt.resize(n);
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(graph[i].size() == 0){
                q.push(i);
            }
            for(auto it:graph[i]){
                adj[i].push_back(it);
                cnt[i]++;
                parent[it].push_back(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(auto it:parent[v]){
                cnt[it]--;
                if(cnt[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};