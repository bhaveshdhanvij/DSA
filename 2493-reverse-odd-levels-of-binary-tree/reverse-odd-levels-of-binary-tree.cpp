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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int l = 0 ;
        queue<TreeNode*> q ;
        q.push(root) ;
        while ( q.size() > 0 ) {
            int n = q.size() ;
            vector<TreeNode*> a ;
            for ( int i = 0 ; i < n ; i++ ) {
                auto node = q.front() ;
                q.pop() ;
                a.push_back(node) ;

                if ( node->left ) q.push(node->left) ;
                if ( node->right ) q.push(node->right) ;
            }
            if ( l % 2 != 0 ) {
                int i = 0 , j = a.size() - 1 ;
                while ( i < j ) {
                    swap(a[i]->val , a[j]->val) ;
                    i++ , j-- ;
                }
            }
            l++ ;
        }
        return root ;
    }
};