class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool bipar = true;
        vector<int> side(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(side[i]==-1){
                q.push(i);
                side[i] = 0;
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(auto v:graph[u]){
                        if(side[v]==-1){
                            side[v] = side[u] ^ 1;
                            q.push(v);
                        }else{
                            bipar&=(side[u]!=side[v]);
                        }
                    }
                }
            }
        }
        return bipar;
    }
};