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
    void dfs( TreeNode* root , int maxx ) {
        if (!root) return ;

        if ( root->val >= maxx ) {
            maxx = root->val ;
            ans++ ;
        } 

        dfs(root->left , maxx) ;
        dfs(root->right , maxx) ;
    }
    int goodNodes(TreeNode* root) {
        dfs(root , INT_MIN ) ;
        return ans ;
    }
};