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
    int count(ListNode* node) {
        int c = 0 ;
        while (node) {
            c++ ;
            node = node->next ;
        }
        return c ;
    } 
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = count(head) ;
        int each = n / k ;
        int extra = n % k ;

        vector<ListNode*> ans(k) ;
        ListNode* curr = head ;

        for ( int i = 0 ; i < k ; i++ ) {
            ans[i] = curr ;

            int n = each + (extra > 0 ? 1 : 0) ;
            if ( extra > 0 ) extra-- ;

            for ( int j = 1 ; j < n && curr ; j++ ) {
                curr = curr->next ;
            }

            if ( curr ) {
                ListNode* node = curr->next ;
                curr->next = nullptr ;
                curr = node ;
            }
        }

        return ans ;

        return ans ;
    }
};