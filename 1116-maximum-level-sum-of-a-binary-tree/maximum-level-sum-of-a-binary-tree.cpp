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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q ;
        q.push(root) ;
        int l = 0 , maxx = INT_MIN ;
        int ans = 0 ;
        while ( q.size() > 0 ) {
            int n = q.size() ;
            int sum = 0 ;
            l++ ;
            for ( int i = 0 ; i < n ; i++ ) {
                TreeNode* node = q.front() ;
                q.pop() ;
                sum += node->val ;
                
                if ( node->left ) q.push(node->left) ;
                if ( node->right ) q.push(node->right) ; 
            }
            if ( sum > maxx ) {
                ans = l ;
                maxx = sum ;
            }
        }
        return ans ;
    }
};