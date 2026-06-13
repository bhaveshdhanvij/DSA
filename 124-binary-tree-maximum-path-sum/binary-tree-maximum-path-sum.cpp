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
    // Goldman Sachs
    // Salesforce
    // Oracle
    // Amazon
    // Google
    // Uber
    // Flipkart

    int ans = INT_MIN ;

    int helper(TreeNode* root) {
        if (!root) return 0 ;

        int left = max(0 , helper(root->left)) ;
        int right = max(0 , helper(root->right)) ;

        // passing through curr and connecting left and right 
        int curr = left + right + root->val ;

        ans = max ( ans , curr ) ;

        // contributing to the parent then only path either from left or right with the curr node 
        return root->val + max(left , right) ;  
    }
    
    int maxPathSum(TreeNode* root) {
        // Optimal Approach : DFS with maximum gain calculation 
        // TC : O(N) , SC : O(N) 
        
        helper(root) ;
        return ans ;  
    }
};