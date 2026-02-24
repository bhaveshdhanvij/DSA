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
    int ans = 0 ;
    void helper( TreeNode* root , int curr ) {
        if (!root ) return ;

        curr = (curr << 1) | root->val ;

        if ( !root->left && !root->right ) {
            ans += curr ;
            return ;
        }

        helper(root->left , curr) ;
        helper(root->right , curr) ;
    }
    int sumRootToLeaf(TreeNode* root) {
        helper(root , 0) ;
        return ans ;
    }
};