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
        int l = *max_element(weights.begin(),weights.end()) - 1;
        int r = accumulate(weights.begin(),weights.end(),0);
        
        int ans;
        while(r>l+1){
            int mid = (l+r)/2;
            if(good(weights,days,mid)){
                // r = mid - 1;
                // ans = mid;
                r = mid;
            }else{
                // l = mid + 1;
                l = mid;
            }
        }
        // return ans;
        return r;
    }
};