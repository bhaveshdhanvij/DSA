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
        // Approach 1 : HashMap ( Trace Appearance ) 
        unordered_map<ListNode*,int> umap ;
        ListNode* curr = head ;
        while ( curr ) {
            if ( umap.count(curr) ) return true ;
            umap[curr]++ ;
            curr = curr->next ;
        }
        return false ;
    }
};