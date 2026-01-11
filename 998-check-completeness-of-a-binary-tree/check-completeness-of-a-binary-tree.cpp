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
    bool isCompleteTree(TreeNode* root) {

        if (!root) return true ;
        bool flag = false ; // if someone's child is missing then noone's child should be missing

        queue<TreeNode*> q ;
        q.push(root) ;
        
        while ( q.size() > 0 ) {
            auto node = q.front() ;
            q.pop() ;

            if (!node->left ) flag = true ;
            else {
                if ( flag ) return false ;
                q.push(node->left) ;
            }

            if ( !node->right ) flag = true ;
            else {
                if ( flag ) return false ;
                q.push(node->right) ;
            }
        }
        return true ;
    }
};