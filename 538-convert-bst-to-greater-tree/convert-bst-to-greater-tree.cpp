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
    int sum = 0 ;
    TreeNode* convertBST(TreeNode* root) {
        // TC : O(N) , SC : O(h) - height of the binary tree
        
        if ( !root ) return nullptr ;
        
        convertBST(root->right) ;

        sum += root->val ;

        root->val = sum ;

        convertBST(root->left) ;
        
        return root ;
    }
};