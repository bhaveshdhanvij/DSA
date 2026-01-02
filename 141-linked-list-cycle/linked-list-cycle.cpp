/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // // Approach 1 : HashMap ( Trace Appearance ) 
        // unordered_map<ListNode*,int> umap ;
        // ListNode* curr = head ;
        // while ( curr ) {
        //     if ( umap.count(curr) ) return true ;
        //     umap[curr]++ ;
        //     curr = curr->next ;
        // }
        // return false ;


        // Approach 2 : Floyd Warshall's Appearance 
        ListNode* fast = head ;
        ListNode* slow = head ;
        while ( fast && fast->next ) {
            slow = slow->next ;
            fast = fast->next->next ;
            if ( slow == fast ) return true ;
        }
        return false ;
    }
};