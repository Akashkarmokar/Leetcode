/**
    TimeComplexity: O(n^2 logn)
*/
class Solution {
/**
    TimeComplexity: O(n)
*/
bool good(vector<int>& weights,int days,int capacity){
    int day = 1;
    int total = 0;
    for(int i=0;i<weights.size();i++){
        total+=weights[i];
        if(total > capacity){
            day++;
            total = weights[i];
            if(day > days){
                return false;
            }
        }
    }
    return true;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0; //bad
        for(int i=0;i<weights.size();i++){
            l = max(l,weights[i]);
        }
        int r = 25e6+5; //good
        int ans;
        
        while(l<=r){ // TimeComplexity: O(nlogn)
            int mid = (l+r)/2;
            if(good(weights,days,mid)){ // TimeComplexity: O(n)
                r = mid-1;
                ans = mid;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};