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
    unordered_map<TreeNode*,int> mp ;
    TreeNode* ans = nullptr ;
    int helper( TreeNode* root) {
        if (!root) return 0 ;

        int curr = 0 ;
        
        int left = helper(root->left) ;
        int right = helper(root->right) ;
        
        curr += left + right ;
        
        if ( mp.count(root) ) curr++ ;
        
        if ( curr == mp.size() && ans == nullptr ) {
            ans = root ;
        }
        
        return curr ;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return nullptr ;
        queue<TreeNode*> q ;
        q.push(root) ;
        mp[root]++ ;

        while (q.size() > 0) {
            int size = q.size() ;
            mp.clear() ;

            for ( int i = 0 ; i < size ; i++ ) {
                auto curr = q.front() ;
                q.pop() ;

                mp[curr]++ ;

                if ( curr->left ) {
                    q.push(curr->left) ;
                }

                if ( curr->right ) {
                    q.push(curr->right) ;
                }
            }
        }

        helper(root) ;
        return ans ;
    }
};