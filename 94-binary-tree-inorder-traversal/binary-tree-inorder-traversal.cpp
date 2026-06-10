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
    // Adobe
    // Uber
    // Meta
    // Google
    // Amazon
    // Microsoft

    // void helper(TreeNode* root , vector<int> &ans ) {
    //     if (!root) return ;
    //     helper(root->left , ans) ;
    //     ans.push_back(root->val) ;
    //     helper(root->right , ans) ;
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        // Approach 1 : Recursive Approach 
        // TC : O(N) , SC : O(h) - height 

        // vector<int> ans ;
        // helper(root , ans) ;
        // return ans ;

        // Approach 2 : Iterative stack based 
        // TC : O(N) , SC : O(N) 

        vector<int> ans ;
        TreeNode* curr = root ;

        stack<TreeNode*> st ;

        while( curr != nullptr || !st.empty() ) {
            while ( curr != nullptr ) {
                st.push(curr) ;
                curr = curr->left ;
            }

            curr = st.top() ;
            st.pop() ;

            ans.push_back(curr->val) ; 

            curr = curr->right ;
        }
        
        return ans ;
    }
};