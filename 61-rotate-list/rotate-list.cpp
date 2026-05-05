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
    int helper(ListNode* head) {
        int ans = 0 ;
        while ( head ) {
            ans++ ;
            head = head->next ;
        }
        return ans ;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = helper(head) ;
        
        if (!head) return nullptr ;
        
        k = k % n ;
        if ( k == 0 ) return head ;

        int t = n - k ;
        
        ListNode* curr = head ;
        ListNode* prev = nullptr ;

        while (t--) {
            prev = curr ;
            curr = curr->next ;
        }

        ListNode* ans = curr ;
        prev->next = nullptr ;
        while ( curr->next ) curr = curr->next ;

        curr->next = head ;
        return ans ;
    }
};