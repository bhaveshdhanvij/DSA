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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> st ;
        ListNode* curr = head ;

        while ( curr ) {
            st.push(curr) ;
            curr = curr->next ;
        }

        int c = 0 ;
        while ( !st.empty() ) {
            ListNode* node = st.top() ;
            st.pop() ;

            int x = node->val * 2 + c ;
            c = x / 10 ;
            node->val = x % 10 ;
        }

        if ( c ) {
            ListNode* node = new ListNode(c , head) ;
            return node ;
        }

        return head ;
    }
};