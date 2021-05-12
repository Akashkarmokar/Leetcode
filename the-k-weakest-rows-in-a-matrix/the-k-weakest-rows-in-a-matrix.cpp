class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(),n=mat[0].size();
        vector<pair<int,int>>tmp;
        for(int i=0;i<m;i++){
            int l =-1,r=n;
            while(r>l+1){
                int m = (r+l)/2;
                if(mat[i][m]==0){
                    r = m;
                }else{
                    l = m;
                }
            }
            tmp.push_back(make_pair(n-(n-r),i));
        }
        sort(tmp.begin(),tmp.end());
        vector<int>ans;
        ans.reserve(k);
        for(int i=0;i<k;i++){
            ans.push_back(tmp[i].second);
        }
        return ans;
        
    }
};