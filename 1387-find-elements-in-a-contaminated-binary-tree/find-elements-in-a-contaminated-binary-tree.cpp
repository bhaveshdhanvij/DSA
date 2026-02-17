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
class FindElements {
public:
    unordered_map<int,int> mp ;
    void helper(TreeNode* root) {
        if ( !root ) return ;
        int x = root->val ;
        mp[x]++ ;
        if ( root->left ) {
            root->left->val = 2 * x + 1 ;
        }
        if ( root->right ) {
            root->right->val = 2 * x + 2 ;
        }

        helper(root->left) ;
        helper(root->right) ;
    }
    FindElements(TreeNode* root) {
        root->val = 0 ;
        helper(root) ;
    }
    
    bool find(int t) {
        return mp.count(t) ;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */