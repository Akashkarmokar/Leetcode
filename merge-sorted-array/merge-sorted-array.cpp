class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans(n+m);
        int i = 0,j=0;
        while(i<m || j<n){
            if(j==n || (i<m && nums1[i]<nums2[j])){
                ans[i+j] = nums1[i];
                i++;
            }else{
                ans[i+j] = nums2[j];
                j++;
            }
        }
        nums1 = ans;
    }
};