/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Adobe
    // Airbnb
    // Google
    // Amazon
    // Samsung
    TreeNode* helper(vector<int> &nums , int st , int end) {
        if ( st > end ) {
            return nullptr ;
        }

        int mid = st + (end - st) / 2 ;
        TreeNode* node = new TreeNode(nums[mid]) ;

        node->left = helper(nums , st , mid - 1) ;
        node->right = helper(nums , mid + 1 , end) ;

        return node ;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Optimal Approach : Using divide and conquer technique 
        // TC : O(N) , SC : O(logN) - recursive stack

        return helper(nums , 0 , nums.size() - 1) ;
    }
};