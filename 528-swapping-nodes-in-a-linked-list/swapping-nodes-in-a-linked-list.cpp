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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head ;
        ListNode* first = head ;
        ListNode* second = head ;

        int l = 0 ;
        while ( temp ) {
            l++ ;
            temp = temp->next ;
        }

        for ( int i = 1 ; i < k ; i++ ) {
            first = first->next ;
        }

        for ( int i = 1 ; i < l - k + 1 ; i++ ) {
            second = second->next ;
        }

        swap(first->val , second->val) ;
        return head ;
    }
};