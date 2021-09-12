class Solution {
private:
    
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        for(int i=0;i<arr1.size();i++){
            if(lower_bound(arr2.begin(),arr2.end(),arr1[i]-d) == upper_bound(arr2.begin(),arr2.end(),arr1[i]+d)){
                ans++;
            }
        }
        return ans;
    }
};