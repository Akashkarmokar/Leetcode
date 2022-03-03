/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfArithmeticSlices = function(nums) {
    let n = nums.length;
    let ans = 0;
    for(let i=2, prev = nums[1]-nums[0], curCount = 0;i<n;i++){
        let dif = nums[i] - nums[i-1];
        dif === prev ? (ans+=++curCount):(prev = dif,curCount=0);
    }
    return ans;
};