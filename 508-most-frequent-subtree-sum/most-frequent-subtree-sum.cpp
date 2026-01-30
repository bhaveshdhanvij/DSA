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
    unordered_map<int,int> umap ;
    
    int helper( TreeNode* root ) {
        if ( !root ) return 0 ;

        int left = helper(root->left) ;
        int right = helper(root->right) ;

        int curr = left + right + root->val ;

        umap[curr]++ ;

        return curr ;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root) ;
        int maxx = 0 ;

        for ( auto x : umap ) {
            maxx = max ( maxx , x.second ) ;
        }

        vector<int> ans ;
        for ( auto x : umap ) {
            if ( x.second == maxx ) {
                ans.push_back(x.first) ;
            }
        }

        return ans ;
    }
};