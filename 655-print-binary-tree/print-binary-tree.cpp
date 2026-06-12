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
    int height(TreeNode* root) {
        if ( root == nullptr ) return -1 ;
        
        int left = height(root->left) ;
        int right = height(root->right) ;

        return 1 + max(left , right) ;
    }
    void fill(TreeNode* root , vector<vector<string>>& ans , int row , int left , int right) {
        if (!root) return ;
        int mid = left + (right - left) / 2 ;
        ans[row][mid] = to_string(root->val) ;

        fill(root->left , ans , row + 1 , left , mid - 1) ;
        fill(root->right , ans , row + 1 , mid + 1 , right) ;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root) ;
        int m = h + 1 ;
        int n = pow(2 , h + 1) - 1 ;
        vector<vector<string>> ans(m , vector<string>(n , "")) ;
        fill(root , ans, 0 , 0 , n - 1);
        return ans ;
    }   
};