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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<ListNode*> st ; 

        ListNode* curr = head ;
        while ( curr ) {
            while ( !st.empty() && curr->val > st.top()->val ) {
                st.top()->val = curr->val ;
                st.pop() ;
            } 

            st.push(curr) ;
            curr = curr->next ;
        }

        while ( !st.empty() ) {
            st.top()->val = 0 ;
            st.pop() ;
        }

        vector<int> ans ;

        curr = head ;
        while ( curr ) {
            ans.push_back(curr->val) ;
            curr = curr->next ;
        }

        return ans ;
    }
};