class Solution {
public:
    int getFreq(vector<int>& a,int lo,int hi,int targetValue){
        int count = 0;
        for(int i=lo;i<=hi;i++){
            if(a[i] == targetValue){
                count++;
            }
        }
        return count;
    }
public:
    int getMajorElement(vector<int>& a,int lo,int hi){
        if(lo==hi){
            return a[lo];
        }
        int mid = lo + (hi-lo)/2;
        int leftMajor = getMajorElement(a,lo,mid);
        int rightMajor = getMajorElement(a,mid+1,hi);
        
        if(leftMajor == rightMajor){
            return leftMajor;
        }
        
        int leftFreq = getFreq(a,lo,mid,leftMajor);
        int rightFreq = getFreq(a,mid+1,hi,rightMajor);
        
        return leftFreq > rightFreq ? leftMajor : rightMajor;
        
    }
    int majorityElement(vector<int>& nums) {
        return getMajorElement(nums,0,nums.size()-1);
    }
};