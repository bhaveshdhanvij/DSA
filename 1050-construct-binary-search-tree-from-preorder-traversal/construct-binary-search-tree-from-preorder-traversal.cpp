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
    TreeNode* helper(vector<int> &preorder , int &idx , int maxx ) {
        if ( idx == preorder.size() || preorder[idx] > maxx ) {
            return nullptr ;
        }

        int currval = preorder[idx++] ;
        TreeNode* root = new TreeNode(currval) ;

        root->left = helper(preorder, idx , currval) ;
        root->right = helper(preorder , idx , maxx) ;
        
        return root ;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0 ;
        return helper(preorder, idx , INT_MAX) ;
    }
};