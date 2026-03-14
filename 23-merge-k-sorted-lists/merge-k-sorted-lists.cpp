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

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq ;

        for ( int i = 0 ; i < lists.size() ; i++ ) {
            if ( lists[i] ) {
                pq.push({lists[i]->val , lists[i]}) ;
            }
        }

        ListNode* ans = new ListNode(0) ;
        ListNode* curr = ans ;

        while (!pq.empty()) {
            auto it = pq.top() ;
            pq.pop() ;

            curr->next = it.second ;

            if ( it.second->next ) {
                pq.push({it.second->next->val , it.second->next}) ;
            }

            curr = curr->next ;
        }

        return ans->next ;
    }
};