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
    unordered_map<int,long long> mp ;
    void dfs(TreeNode* root , int l ) {
        if ( !root ) return ;
        mp[l] += root->val ;

        dfs(root->left , l + 1) ;
        dfs(root->right , l + 1 ) ;
    }
    void dfs2(TreeNode* root , int l ) {
        if (!root) return ;

        int sum = 0 ;
        if ( root->left ) sum += root->left->val ;
        if ( root->right ) sum += root->right->val ;

        if ( root->left ) root->left->val = mp[l + 1] - sum ;
        if ( root->right ) root->right->val = mp[l + 1] - sum ;

        dfs2(root->left , l + 1 ) ;
        dfs2(root->right , l + 1) ;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs(root , 0) ;
        root->val = 0 ;
        dfs2(root , 0) ;
        return root ;
    }
};