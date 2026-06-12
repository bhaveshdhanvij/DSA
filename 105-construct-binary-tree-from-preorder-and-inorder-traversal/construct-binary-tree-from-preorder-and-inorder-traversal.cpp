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
    // Apple
    // Microsoft
    // Amazon
    // VMWare
    // Uber
    // Adobe

    // int search(vector<int>& inorder , int left , int right , int target ) {
    //     for ( int i = left ; i <= right ; i++ ) {
    //         if ( inorder[i] == target ) {
    //             return i ;
    //         }
    //     }
    //     return -1 ;
    // }
    unordered_map<int,int> mp ; // index mapping in inorder
    
    TreeNode* helper(vector<int>& preorder, int &preIdx , int left , int right) {
        if ( left > right ) {
            return nullptr ;
        }
        int rootval = preorder[preIdx++] ;

        TreeNode* root = new TreeNode(rootval) ;

        int inIdx = mp[rootval] ;
        
        root->left = helper(preorder , preIdx , left , inIdx - 1) ;
        root->right = helper(preorder , preIdx , inIdx + 1 , right) ;

        return root ; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Optimal Approach : Recursive divide and conquer using preorder and inorder traversal 
        // TC : O(N) , SC : O(N)
        
        int preIdx = 0 ;
        for ( int i = 0 ; i < inorder.size() ; i++ ) {
            mp[inorder[i]] = i ;
        }
        return helper(preorder , preIdx , 0 , inorder.size() - 1) ;
    }
};