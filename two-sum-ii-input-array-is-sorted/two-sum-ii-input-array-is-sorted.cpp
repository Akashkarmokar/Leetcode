class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        
        for(int i=0;i<n-1;i++){
            int val = target - numbers[i];
            auto it = lower_bound(numbers.begin()+i+1,numbers.end(),val);
            int pos = it - numbers.begin();
            if(pos<n && numbers[pos]==val){
                ans.push_back(i+1);
                ans.push_back(pos+1);
            }
            
        }
        
        return ans;
    }
};