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
    // Flipkart
    // Oracle
    // Google
    // Amazon
    // Adobe
    // Meta
    // Microsoft
    TreeNode* findmin(TreeNode* node) {
        while ( node->left ) {
            node = node->left ;
        }
        return node ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Optimal Approach : Recursive BST delete Inorder Successor Replacement 
        // TC : O(h) , SC : O(h) 

        if (!root) return nullptr ;
        if ( root->val < key ) {
            root->right = deleteNode(root->right , key) ;
        }else if ( root->val > key ) {
            root->left = deleteNode(root->left , key) ;
        }else {
            if ( !root->left ) {
                TreeNode* ans = root->right ;
                delete root ;
                return ans ;
            }

            if ( !root->right ) {
                TreeNode* ans = root->left ;
                delete root ;
                return ans ;
            }

            TreeNode* succ = findmin(root->right) ;
            root->val = succ->val ;
            root->right = deleteNode(root->right , succ->val) ;
        }

        return root ;
    }
};