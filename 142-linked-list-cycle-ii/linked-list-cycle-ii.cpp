/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Amazon
    // Oracle
    // Paytm
    // Google
    // Microsoft
    ListNode *detectCycle(ListNode *head) {
        // Optimal Approach : First detect the cycle using slow fast pointer and then reset slow and move both pointers by one , meeting point gives us the starting point of the cycle 
        // TC : O(N) , SC : O(1)

        ListNode* slow = head ;
        ListNode* fast = head ;
        
        while ( fast != nullptr && fast->next != nullptr ) {
            slow = slow->next ;
            fast = fast->next->next ;

            if ( slow == fast ) { // cycle detected 
                slow = head ;
                while ( slow != fast ) {
                    slow = slow->next ;
                    fast = fast->next ;
                }
                return slow ;
            }
        }

        return nullptr ; // no cycle detected 
    }
};