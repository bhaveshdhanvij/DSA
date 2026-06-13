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
    // Amazon
    // Google
    // Adobe
    // Microsoft
    // Uber
    int widthOfBinaryTree(TreeNode* root) {
        // Optimal Approach : Complete Binary tree indexing logic
        // TC : O(N) , SC : O(W)
        
        queue<pair<TreeNode*,unsigned long long>> q ;
        q.push({root , 0}) ;
        
        int ans = 0 ;
        
        while ( q.size() > 0 ) {
            int size = q.size() ;
            unsigned long long curr = q.back().second - q.front().second + 1 ;
            ans = max ( ans , (int)curr ) ;

            for ( int i = 0 ; i < size ; i++ ) {
                auto curr = q.front() ;
                q.pop() ;

                unsigned long long idx = curr.second ;

                if ( curr.first->left ) {
                    q.push({curr.first->left , 2 * idx + 1}) ;
                }

                if ( curr.first->right ) {
                    q.push({curr.first->right , 2 * idx + 2}) ;
                }
            }
        }
        return ans ;
    }
};