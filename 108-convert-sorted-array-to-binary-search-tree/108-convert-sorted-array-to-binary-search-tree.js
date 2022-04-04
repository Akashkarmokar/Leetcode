/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    if(nums.length == 0){
        return null;
    }else if(nums.length == 1 ){
        return new TreeNode(nums[0]);
    }
    const mid = Math.floor((nums.length)/2);
    const root = new TreeNode(nums[mid]);
    
    //left Subtree
    root.left = sortedArrayToBST(nums.slice(0,mid));
    
    // right Subtree
    root.right = sortedArrayToBST(nums.slice(mid+1));
    
    return root;
};