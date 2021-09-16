class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0;
        int r = arr.size();
        
        while(l<r){
            int mid = (r+l)/2;
            int missingNum = arr[mid] - mid - 1;
            if(missingNum<k){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        
        return l+k;
    }
};