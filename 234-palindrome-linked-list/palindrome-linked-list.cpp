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
class Solution {
public:
    // Qualcomm
    // Oracle
    // Adobe
    // Google
    // Uber
    // Amazon
    // Microsoft

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr ;
        ListNode* curr = head ;
        ListNode* next = nullptr ;

        while ( curr != nullptr ) {
            next = curr->next ;

            curr->next = prev ;

            prev = curr ;
            curr = next ;
        }
        return prev ;
    }

    bool isPalindrome(ListNode* head) {
        // Approach 1 : Store values in vector and check whether vector is palindrome or not using 2 pointer
        // TC : O(N) , SC : O(N) 

        // Approach 2 : Using stack , push all elements into the stack and check node value with top of stack
        // TC : O(N) , SC : O(N) 

        // Optimal Approach : Reverse second half and check with the first half 
        // TC : O(N) , SC : O(1)

        ListNode* slow = head ; 
        ListNode* fast = head ;

        while ( fast != nullptr && fast->next != nullptr ) {
            slow = slow->next ;
            fast = fast->next->next ;
        }

        ListNode* first = head ;
        ListNode* second = reverse(slow) ;

        while ( second != nullptr ) {
            if ( first->val != second->val ) {
                return false ;
            }

            first = first->next ;
            second = second->next ;
        }

        return true ;
    }
};