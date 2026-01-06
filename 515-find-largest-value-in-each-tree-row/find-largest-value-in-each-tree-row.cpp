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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans ;
        if (!root) return ans ;
        queue<TreeNode*> q ;
        q.push(root) ;
        while ( q.size() > 0 ) {
            int maxx = INT_MIN ;
            int n = q.size() ;
            for ( int i = 0 ; i < n ; i++ ) {
                TreeNode* node = q.front() ;
                q.pop() ;
                maxx = max ( maxx , node->val ) ;
                if ( node->left ) q.push(node->left) ;
                if ( node->right ) q.push(node->right) ;
            }
            ans.push_back(maxx) ;
        }
        return ans ;
    }
};