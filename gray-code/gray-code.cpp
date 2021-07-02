class Solution {
private:
    vector<string> getGrayCode(int n){
        if(n==1){
            return {"0","1"};
        }
        vector<string> grayCodeOfPrev = getGrayCode(n-1);
        vector<string> res;
        int numOfGrayCodeInPrev = grayCodeOfPrev.size();
        
        for(auto i:grayCodeOfPrev){
            res.push_back("0"+i);
        }
        for(int i = numOfGrayCodeInPrev-1;i>=0;i--){
            res.push_back("1"+grayCodeOfPrev[i]);
        }
        return res;
    }
public:
    vector<int> grayCode(int n) {
        vector<string> temp = getGrayCode(n);
        vector<int> ans;
        for(auto i:temp){
            ans.push_back(stoi(i,0,2));
        }
        return ans;
    }
};



// https://leetcode.com/discuss/explore/july-leetcoding-challenge-2021/1308587/Gray-Code-or-Recursion-%2B-Iterative-wExplanation