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
    // Microsoft
    // Amazon
    // Oracle
    // Google
    // Tejas network
    // Josh technology
    // TCS
    // Accenture
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Approach 1 & 2 : Convert both lists to numbers , add them , and create a new ll , can case overflow 
        // Better approach is storing digits and simulating addition 

        // Optimal Approach : Using a carry variable while traversing both linked list simultaneously 
        // TC : O(max(N , M)) , SC : O(max(N , M)) 

        ListNode* dummy = new ListNode(0) ;
        ListNode* curr = dummy ;

        int carry = 0 ;

        while ( l1 || l2 || carry ) {
            int x = 0 , y = 0 ;

            if ( l1 != nullptr ) x = l1->val ;
            if ( l2 != nullptr ) y = l2->val ;

            int sum = x + y + carry ;

            carry = sum / 10 ;

            curr->next = new ListNode(sum % 10) ;
            curr = curr->next ;

            if ( l1 != nullptr ) l1 = l1->next ;
            if ( l2 != nullptr ) l2 = l2->next ;
        }

        return dummy->next ;
    }
};