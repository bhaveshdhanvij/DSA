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
    // Salesforce
    // Amazon
    // Microsoft
    // Google
    // Adobe
    // Meta

    // void helper(TreeNode* node , vector<int> &ans ) {
    //     if (!node) return ;
    //     ans.push_back(node->val) ;

    //     helper(node->left , ans) ;
    //     helper(node->right , ans) ;
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // Approach 1 : Recursive approach 
        // TC : O(N) , SC : O(h) - height 

        // vector<int> ans ;
        // helper(root , ans) ;
        // return ans ; 

        // Approach 2 : Iterative stack solution 
        // TC : O(N) , SC : O(h) 

        vector<int> ans ;
        if (!root) return ans ;

        stack<TreeNode*> st ;
        st.push(root) ;

        while (!st.empty()) {
            TreeNode* node = st.top() ;
            st.pop() ;

            ans.push_back(node->val) ;

            if ( node->right ) {
                st.push(node->right) ;
            }

            if ( node->left ) {
                st.push(node->left) ;
            }
        }
        return ans ;
    }
};