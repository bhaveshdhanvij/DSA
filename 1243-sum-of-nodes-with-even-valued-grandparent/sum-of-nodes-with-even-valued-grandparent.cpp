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
private:
    void helper(TreeNode* gp , TreeNode* p , TreeNode* root , int &ans ) {
        if ( !root ) return ;

        if ( gp != nullptr && gp->val % 2 == 0 ) {
            ans += root->val ;
        }

        helper(p , root , root->left , ans ) ;
        helper(p , root , root->right , ans ) ;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0 ;
        helper( nullptr , nullptr , root , ans ) ;
        return ans ;
    }
};