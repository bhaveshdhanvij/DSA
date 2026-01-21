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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Approach 1 : brute force TC : O(N * K) , not optimal 

        // Approach 2 : first merge 2 then head with 3rd one and so on , optimized a bit to nlogn max 

        // Approach 3 : Using Min - Heap 

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>> ,greater<pair<int,ListNode*>>> pq ;

        for ( int i = 0 ; i < lists.size() ; i++ ) {
            if ( lists[i] ) {
                pq.push(make_pair(lists[i]->val , lists[i])) ;
            }
        }

        ListNode* ans = new ListNode(-1) ;
        ListNode* temp = ans ;

        while ( !pq.empty() ) {
            auto it = pq.top() ;
            pq.pop() ;

            temp->next = it.second ;

            if ( it.second->next ) {
                pq.push(make_pair(it.second->next->val , it.second->next)) ;
            }

            temp = temp->next ;
        }

        return ans->next ;
    }
};