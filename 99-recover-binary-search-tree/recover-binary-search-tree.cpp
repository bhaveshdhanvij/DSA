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
    // Oracle
    // Google
    // Amazon
    // Microsoft

    TreeNode* prev = nullptr , *first = nullptr , *second = nullptr ;
    void helper(TreeNode* root) {
        if (root == nullptr) {
            return ;
        }

        helper(root->left) ;

        if ( prev != nullptr && prev->val > root->val ) {
            if ( !first ) {
                first = prev ;
            }
            second = root ;
        }

        prev = root ;
        helper(root->right) ;
    }
    void recoverTree(TreeNode* root) {
        // Optimal Approach : Using bst inorder => sorted array logic 
        // TC : O(N) , SC : O(h) - height of the BST 

        helper(root) ;

        int temp = first->val ;
        first->val = second->val ;
        second->val = temp ;
    }
};