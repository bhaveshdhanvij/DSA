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
    void reorderList(ListNode* head) {
        if (!head || !head->next ) return ;

        ListNode* slow = head ;
        ListNode* fast = head ;
        
        while( fast->next && fast->next->next ) {
            slow = slow->next ;
            fast = fast->next->next ;
        }

        ListNode* mid = slow->next ;
        slow->next = nullptr ;

        stack<ListNode*> st ;

        while ( mid ) {
            st.push(mid) ;
            mid = mid->next ;
        }

        ListNode* curr = head ;
        
        while ( curr && !st.empty() ) {
            ListNode* next = curr->next ;
            ListNode* top = st.top() ;
            st.pop() ;

            curr->next = top ;
            top->next = next ;

            curr = next ;
        }
    }
};