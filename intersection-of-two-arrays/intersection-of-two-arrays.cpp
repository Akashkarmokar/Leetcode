class Solution {
private:
    bool haveElement(vector<int> &a, int num){
        int l = -1; 
        int r = a.size();
        while(r>l+1){
            int mid = (r+l)/2;
            if(a[mid]<num){
                l = mid;
            }else{
                r = mid;
            }
        }
        if(r<a.size() && a[r]==num){
            return true;
        }
        return false;
        
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        
        if(a==0 || b==0){
            return {};
        }
        set<int> s;
        vector<int> ans;
        if(a>b){
            sort(nums2.begin(),nums2.end());
            for(int i=0;i<a;i++){
                if(haveElement(nums2,nums1[i])){
                    s.insert(nums1[i]);
                }
            }
        }else{
            sort(nums1.begin(),nums1.end());
            for(int i=0;i<b;i++){
                if(haveElement(nums1,nums2[i])){
                    s.insert(nums2[i]);
                }
            }
        }
        for(auto it: s){
            ans.push_back(it);
        }
        
        return ans;
    }
};