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

    // Uber
    // Google
    // Apple
    // Adobe
    // Microsoft
    // Amazon

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

        // vector<int> ans ;
        // TreeNode* curr = root ;

        // stack<TreeNode*> st ;

        // while( curr != nullptr || !st.empty() ) {
        //     while ( curr != nullptr ) {
        //         st.push(curr) ;
        //         curr = curr->left ;
        //     }

        //     curr = st.top() ;
        //     st.pop() ;

        //     ans.push_back(curr->val) ; 

        //     curr = curr->right ;
        // }
        
        // return ans ;

        // Optimal Approach : Morris Inorder Traversal 
        // TC : O(N) , SC : O(1) 

        // For every node :
        // No left child -> visit and go right 
        // left child exists ->
        // pred->right == nullptr -> create thread , go left 
        // pred->right == curr -> remove thread , visit and go right 

        vector<int> ans ;
        TreeNode* curr = root ;
        while ( curr ) {
            
            // case 1 : no left subtree
            if ( curr->left == nullptr ) {
                ans.push_back(curr->val) ;
                curr = curr->right ;
            }else{
                // case 2 : left subtree exists 
                TreeNode* pred = curr->left ;
                
                while ( pred->right && pred->right != curr){
                    pred = pred->right ;
                }

                // first visit 
                if ( pred->right == nullptr ) {
                    pred->right = curr ; // create thread 
                    curr = curr->left ;
                }else {
                    // second visit 

                    pred->right = nullptr ; // remove thread 
                    ans.push_back(curr->val) ;
                    curr = curr->right ;
                }
            }
        }

        return ans ;
    }
};