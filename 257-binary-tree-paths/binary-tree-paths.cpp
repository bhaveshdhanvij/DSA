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
    vector<string> ans ;

    void helper(TreeNode* root , string curr) {
        if (!root) return ;
        
        if ( !curr.empty() ) curr += "->" ;
        curr += to_string(root->val) ;

        if ( root->left == nullptr && root->right == nullptr ) {
            ans.push_back(curr) ;
            return ;
        }

        helper(root->left , curr) ;
        helper(root->right , curr) ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s ;
        helper(root , s) ;
        return ans ;
    }
};