class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans;
        sort(bobSizes.begin(),bobSizes.end());
        sort(aliceSizes.begin(),aliceSizes.end());
        
        
        int alice = 0,bob = 0;
        
        for(int i=0;i<aliceSizes.size();i++){
            alice+=aliceSizes[i];
        }
        for(int i=0;i<bobSizes.size();i++){
            bob+=bobSizes[i];
        }
        
        int z = (bob-alice)/2;
        
        
        
        
        for(auto x:aliceSizes){
            int idx = lower_bound(bobSizes.begin(),bobSizes.end(),z + x) - bobSizes.begin();
            if(bobSizes[idx] == z+x){
                ans.push_back(x);
                ans.push_back(z+x);
                break;
            }
        }
        
        return ans;
    }
};