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
    ListNode* helper(ListNode* head) {
        ListNode* prev = nullptr ;
        ListNode* curr = head ;
        while ( curr != nullptr ) {
            ListNode* next = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = next ;
        }
        return prev ;
    }
    int pairSum(ListNode* head) {
        if ( !head || !head->next ) return -1 ;

        ListNode* slow = head ;
        ListNode* fast = head ;

        while ( fast && fast->next ) {
            slow = slow->next ;
            fast = fast->next->next ;    
        }

        ListNode* head2 = helper(slow) ;
        int ans = INT_MIN ;

        while ( head2 ) {
            ans = max ( ans , head->val + head2->val ) ;
            head = head->next ;
            head2 = head2->next ;
        }

        return ans ;
    }
};