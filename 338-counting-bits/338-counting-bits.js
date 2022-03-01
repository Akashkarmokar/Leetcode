function getBit(n){
    let count = 0;
    while(n){
        count+=(n&1);
        n = n>>1;
    }
    return count;
}
/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) {
    let ans = [];
    for(let i=0;i<=n;i++){
        ans.push(getBit(i));
    }
    return ans;
};