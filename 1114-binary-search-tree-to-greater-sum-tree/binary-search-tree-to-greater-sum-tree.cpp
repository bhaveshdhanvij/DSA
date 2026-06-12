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
    // Amazon
    // Microsoft
    // Ebay
    // SAP Labs
    int sum = 0 ;
    void helper( TreeNode* root ) {
        if (!root) return ;
        
        helper(root->right) ;

        sum += root->val ;
        root->val = sum ;

        helper(root->left) ;
    }
    TreeNode* bstToGst(TreeNode* root) {
        // Approach : Reverse inorder traversal : updates greater sum automatically 
        // TC : O(N) , SC : O(N)
        
        helper(root) ;
        return root ;
    }
};