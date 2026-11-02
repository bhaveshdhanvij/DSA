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
    // Google
    // Meta
    // Cisco
    // Samsung
    // Goldman Sachs
    // Amazon
    // Wipro
    bool hasCycle(ListNode *head) {
        // Approach 1 : Using hashMap , storing the frequency count of each node 
        // TC : O(N) , SC : O(N) 

        // Optimal Approach : Using slow fast pointer approach 
        // TC : O(N) , SC : O(1)

        ListNode* slow = head ;
        ListNode* fast = head ;

        while ( fast != nullptr && fast->next != nullptr ) {
            slow = slow->next ;
            fast = fast->next->next ;

            if ( slow == fast ) {
                return true ; // cycle detected 
            }
        }

        return false ;
    }
};