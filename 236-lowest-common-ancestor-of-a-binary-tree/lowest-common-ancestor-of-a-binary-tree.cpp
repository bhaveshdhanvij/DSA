/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Salesforce
    // Flipkart
    // Adobe
    // Oracle
    // Linkedin
    // Intuit
    // Google
    // Amazon
    // Morgan Stanley
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Optimal Approach : Recursive bottom-up approach DFS 
        // TC : O(N) , SC : O(N) - skewed tree 
        
        if (!root) return nullptr ;
        
        if ( root->val == p->val || root->val == q->val ) {
            return root ;
        }

        TreeNode* leftlca = lowestCommonAncestor(root->left , p , q) ;
        TreeNode* rightlca = lowestCommonAncestor(root->right , p , q) ;
        
        if ( leftlca && rightlca ) {
            return root ;
        }else if ( leftlca != nullptr ) {
            return leftlca ;
        }else {
            return rightlca ;
        }
    }
};