class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int mxprft = 0;
        for(int i=0;i<prices.size();i++){
            if(minprice>prices[i]){
                minprice = prices[i];
            }else if(prices[i]-minprice>mxprft){
                mxprft = prices[i]-minprice;
            }
        }
        return mxprft;
    }
};