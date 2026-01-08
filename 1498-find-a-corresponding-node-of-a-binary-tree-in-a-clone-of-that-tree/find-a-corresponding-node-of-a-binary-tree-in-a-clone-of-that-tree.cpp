/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* a, TreeNode* b, TreeNode* t) {
        if (!a) return nullptr ;
        if (a == t) return b ;

        TreeNode* temp = getTargetCopy(a->left , b->left , t) ;
        if ( temp ) return temp ;

        return getTargetCopy(a->right , b->right , t) ;
    }
};