/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        int ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            int callBackResult = guess(mid);
            if(callBackResult == 1){
                l = mid + 1;
            }else if(callBackResult == -1){
                r = mid - 1;
            }else {
                ans = mid ;
                break;
            }
        }
        
        
        return ans;
    }
};