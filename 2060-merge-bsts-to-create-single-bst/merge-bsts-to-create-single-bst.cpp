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
    // Bloomberg
    // Microsoft

    unordered_map<int,TreeNode*> mp ;
    unordered_map<int,int> cnt ;

    bool valid ( TreeNode* node , long long minn , long long maxx ) {
        if ( !node ) {
            return true ;
        }

        if ( node->val <= minn || node->val >= maxx ) {
            return false ;
        }

        if ( node->left == nullptr && node->right == nullptr && mp.count(node->val) ) {
            TreeNode* root = mp[node->val] ;
            node->left = root->left ;
            node->right = root->right ;
            mp.erase(root->val) ;
        }

        return valid(node->left , minn , node->val) && valid(node->right , node->val , maxx ) ;
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        // Approach : DFS + Hash map tree merging with BST validation 
        // TC : O(N) , SC : O(N) 
        
        // counting frequencies to get the root of the ans 
        for ( auto* root : trees ) {
            mp[root->val] = root ;
            cnt[root->val]++ ;

            if (root->left) cnt[root->left->val]++ ;
            if (root->right) cnt[root->right->val]++ ; 
        }        

        TreeNode* start = nullptr ;
        for ( auto *root : trees ) {
            if ( cnt[root->val] == 1 ) {
                start = root ;
                break ;
            }
        }

        if ( start == nullptr ) {
            return nullptr ;
        }

        mp.erase(start->val) ;
        if ( !valid(start , LLONG_MIN , LLONG_MAX) ) {
            return nullptr ;
        }

        if ( !mp.empty() ) {
            return nullptr ;
        }

        return start ;
    }
};