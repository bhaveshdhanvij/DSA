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
    int helper( vector<int> &a) {
        int n = a.size() ;
        int ans = 0 ;
        vector<int> t = a ;
        unordered_map<int,int> umap ;
        for ( int i = 0 ; i < n ; i++ ) {
            umap[a[i]] = i ;
        }
        sort( t.begin() , t.end() ) ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( t[i] != a[i] ) {
                int idx = umap[t[i]] ;
                umap[a[i]] = idx ;
                umap[a[idx]] = i ;

                swap(a[idx] , a[i]) ;
                ans++ ;
            }
        }
        return ans ;
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0 ;
        queue<TreeNode*> q ;
        q.push(root) ;
        while ( q.size() > 0 ) {
            int n = q.size() ;
            vector<int> a ;
            for ( int i = 0 ; i < n ; i++ ) {
                TreeNode* node = q.front() ;
                q.pop() ;
                a.push_back(node->val) ;

                if ( node->left) q.push(node->left) ;
                if ( node->right) q.push(node->right) ;
            }
            ans += helper(a) ;
        }
        return ans ;
    }
};