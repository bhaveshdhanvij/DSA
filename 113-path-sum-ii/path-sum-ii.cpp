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
    vector<vector<int>> ans ;
    void helper( TreeNode* root , vector<int> a , int curr , int t ) {
        if ( !root ) return ;
        a.push_back(root->val) ;
        curr += root->val ;

        if ( !root->left && !root->right ) {
            if ( curr == t ) ans.push_back(a) ;
            return ;
        }

        helper(root->left , a , curr , t ) ;
        helper(root->right , a, curr , t ) ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<int> a ;
        int curr = 0 ;
        helper(root , a , curr , t ) ;
        return ans ;
    }
};