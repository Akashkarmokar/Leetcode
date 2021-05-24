class TreeAncestor {
public:
    vector<vector<int>>jmp;
    vector<int>d;
    int kk;
    TreeAncestor(int n, vector<int>& parent) {
        parent[0]=0;
        kk = (int)ceil(log2(n));
        jmp.assign(n+1,vector<int>(kk+1));
        d.assign(n+1,0);
        for(int i=0;i<n;i++){
            jmp[i][0] = parent[i];
            if(i>0){
                d[i] = d[parent[i]] + 1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<=kk;j++){
                jmp[i][j] = jmp[jmp[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(d[node]<k){
            return -1;
        }
        for(int i=kk;i>=0;i--){
            if(k>=(1<<i)){
                node =  jmp[node][i];
                k-=(1<<i);
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */