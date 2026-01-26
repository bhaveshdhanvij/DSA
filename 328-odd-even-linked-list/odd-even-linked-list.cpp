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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr ;
        int c = 0 ;

        ListNode* odd = new ListNode(-1) ;
        ListNode* even = new ListNode(-1) ;

        ListNode* curr = head ;
        ListNode* o = odd ;
        ListNode* e = even ;

        while ( curr ) {
            c++ ;

            if ( c & 1 ) {
                o->next = curr ;
                o = o->next ;
            }else {
                e->next = curr ;
                e = e->next ;
            }

            curr = curr->next ;
        }

        e->next = nullptr ;
        o->next = even->next ;

        return odd->next ;
    }
};