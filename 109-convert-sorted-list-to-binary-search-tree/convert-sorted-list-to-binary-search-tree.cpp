/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

 // Optimal Solution | Not classic ll -> array conversion 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr ;
        if ( !head->next ) return new TreeNode(head->val) ;

        ListNode* fast = head ;
        ListNode* slow = head ;
        ListNode* prev = nullptr ;

        while ( fast && fast->next ) {
            prev = slow ;
            slow = slow->next ;
            fast = fast->next->next ;
        }

        TreeNode* root = new TreeNode(slow->val) ;

        prev->next = nullptr ;

        root->left = sortedListToBST(head) ;
        root->right = sortedListToBST(slow->next) ;

        return root ;
    }
};




// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* helper(vector<int>& a , int l , int r ) {
//         if ( l > r ) return nullptr ;

//         int mid = l + (r - l) / 2 ;

//         TreeNode* root = new TreeNode(a[mid]) ;

//         root->left = helper(a , l , mid - 1 ) ;
//         root->right = helper(a , mid + 1 , r ) ;

//         return root ;
//     }
//     TreeNode* sortedListToBST(ListNode* head) {
//         vector<int> a ;

//         while ( head ) {
//             a.push_back(head->val) ;
//             head = head->next ;
//         }

//         return helper( a , 0 , a.size() - 1 ) ;
//     }
// };